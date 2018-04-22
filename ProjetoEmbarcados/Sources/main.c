/* ********************************************** */
/* File name:                    main.c            */
/* File description:  Main file of the code.      */
/*                    Contains the initialization */
/*                    sequence and the main loop  */
/* Author name:       julioalvesMS & IagoAF       */
/* Creation date:     08mar2018                   */
/* Revision date:     05abr2018                   */
/* ********************************************** */

/* System includes */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "debugUart.h"
#include "util.h"

/* Hardware abstraction layers */
#include "buzzer_hal.h"
#include "mcg_hal.h"
#include "ledswi_hal.h"
#include "display7seg_hal.h"

/* communication */
#include "serial.h"
#include "stateMachine.h"


/* ****************************************************** */
/* Method name:         setupPeripherals                  */
/* Method description:  Makes the necessaries setups and  */
/*                      initializations for a proper      */
/*                      preparation of the peripherals    */
/* Input params:        n/a                               */
/* Output params:       n/a                               */
/* ****************************************************** */
void setupPeripherals()
{
    /* Start clock */
    mcg_clockInit();

    /* Start serial communication */
    serial_init();

    /* Start leds */
    ledswi_initLedSwitch(0, 4);

    /* Start display7seg */
    display7seg_initDisplay();

    /* Start the buzzer */
    buzzer_init();
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

    unsigned char ucDataValue;
    char cLedsStates[4] = {0, 0, 0, 0};
    int iBuzzerTimer = 0;
    int *piBuzzerTimer = &iBuzzerTimer;

    /* Make all the required inicializations */
    setupPeripherals();


    for (;;)
    {
        if(UART0_BRD_S1_RDRF(UART0)){
            ucDataValue = GETCHAR();
            stateMachine_stateProgression(ucDataValue, cLedsStates, piBuzzerTimer);
        }

        /* Set the LEDs ON/OFF according to the state vector */
        ledswi_changeAllLeds(cLedsStates)

        /* If needed, play the buzzer */
        if(iBuzzerTimer>0)
        {
            buzzer_playBuzz1ms();
            iBuzzerTimer--;
        }

    } /* Never leave main */
    return 0;
}
