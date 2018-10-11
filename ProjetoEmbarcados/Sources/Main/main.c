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
#include "Sensor\Tachometer\tachometer_hal.h"
#include "Util\PWM\timer_counter.h"
#include "Sensor\ADC\adc.h"
#include "Sensor\ADC\lut_adc_3v3.h"

#include "Driver\Behaviour\cmdMachine.h"
#include "Driver\PID\pid.h"


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

    /* Prepare the cooler as PWM */
    timer_initTPM1AsPWM();
    timer_motor_init();

    /* Initiate de ADC Module and prepare heater */
    adc_initADCModule();

    /* Setup the PID */
    pid_init();

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

    unsigned char ucDataValue = 0;
    double dMotorSpeed = 0.0;
    int iCoolerReferenceSpeed = 0;
    int iMaxCoolerSpeed = 0.0;
    double dPwmControlValue = 0.0;

    /* Make all the required inicializations */
    setupPeripherals();

    /* Enable needed interruptions */
    enableInterruptions();

    timer_motor_setSpeed(PWM_0pct);

    /* Initiate ECC */
    for (;;)
    {
		cmdMachine_stateProgression(ucDataValue);

		if(iCoolerReferenceSpeed > iMaxCoolerSpeed)
			iCoolerReferenceSpeed = iMaxCoolerSpeed;

        /* Reads the cooler speed */
		dMotorSpeed = tachometer_readSensor(CYCLIC_EXECUTIVE_PERIOD);

        dPwmControlValue = pid_updateData((double) dMotorSpeed, (double) iCoolerReferenceSpeed);
        timer_motor_setSpeed(dPwmControlValue);


        /* WAIT FOR CYCLIC EXECUTIVE PERIOD */
        while(!uiFlagNextPeriod);
        uiFlagNextPeriod = 0;

    } /* Never leave main */
    return 0;
}
