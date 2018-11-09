/* ********************************************** */
/* File name:         main.c                      */
/* File description:  Main file of the code.      */
/*                    Contains the initialization */
/*                    sequence and the main loop  */
/* Author name:       julioalvesMS & IagoAF       */
/* Creation date:     08mar2018                   */
/* Revision date:     28jun2018                   */
/* ********************************************** */

#include "Util\IRQ\tc_hal.h"

#include "Util\Clock\mcg_hal.h"

#include "Domain\driver_entity.h"

#include "Actuator\Motor\motor_hal.h"
#include "Sensor\Speed\speed.h"
#include "Sensor\Track\track.h"

#include "Driver\driver_ai.h"

#include "Serial\serial.h"


/* defines */
#define CYCLIC_EXECUTIVE_PERIOD         250 * 1000 /* 250000 micro seconds */


/* globals */
volatile unsigned int uiFlagNextPeriod = 0;         /* cyclic executive flag */
extern const unsigned char tabela_temp[256];


/* ************************************************ */
/* Method name:        main_cyclicExecuteIsr        */
/* Method description: cyclic executive interrupt   */
/*                     service routine              */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void main_cyclicExecuteIsr(void)
{
    /* set the cyclic executive flag */
    uiFlagNextPeriod = 1;
}


/* ****************************************************** */
/* Method name:         setupPeripherals                  */
/* Method description:  Makes the necessaries setups and  */
/*                      initializations for a proper      */
/*                      preparation of the peripherals    */
/* Input params:        n/a                               */
/* Output params:       n/a                               */
/* ****************************************************** */
void setupPeripherals(void)
{
    /* Start clock */
    mcg_clockInit();

    /* Start serial communication */
    serial_init();

    driver_init();

    motor_initMotorPWM();

    track_initSensor();

    speed_initSensor();

}


/* ****************************************************** */
/* Method name:         setupPeripherals                  */
/* Method description:  Makes the necessaries setups and  */
/*                      initializations for a proper      */
/*                      preparation of the peripherals    */
/* Input params:        n/a                               */
/* Output params:       n/a                               */
/* ****************************************************** */
void enableInterruptions(void)
{

    /* configure cyclic executive interruption */
    tc_installLptmr0(CYCLIC_EXECUTIVE_PERIOD, main_cyclicExecuteIsr);

    serial_enableIRQ();
}


/* ****************************************************** */
/* Method name:         main                              */
/* Method description:  System main function. Contains    */
/*                      all the code that will actually   */
/*                      run                               */
/* Input params:        n/a                               */
/* Output params:       n/a                               */
/* ****************************************************** */
int main(void)
{

	driver_in_entity driverData;
	driver_out_entity driverControl;

	driverData.DebugSpeed[0] = 10;
	driverData.DebugSpeed[1] = 10;

    /* Make all the required inicializations */
    setupPeripherals();

    /* Enable needed interruptions
    enableInterruptions();*/

    /* Initiate ECC */
    for (;;)
    {

		track_readSensor(driverData.TrackSensor);

		track_findTrack(&driverData);

		speed_readSensor(driverData.SpeedSensor);

		driverControl = driver_run(driverData);

        motor_setSpeed(driverControl.MotorSpeed);

        serial_sendADConvertion(driverData.SpeedSensor[0]*100);
        serial_sendADConvertion(driverData.SpeedSensor[1]*100);
        serial_sendAck();

        /* WAIT FOR CYCLIC EXECUTIVE PERIOD
        while(!uiFlagNextPeriod);
        uiFlagNextPeriod = 0; */

    } /* Never leave main */
    return 0;
}
