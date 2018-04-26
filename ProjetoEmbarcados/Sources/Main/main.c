/* ********************************************** */
/* File name:         main.c                      */
/* File description:  Main file of the code.      */
/*                    Contains the initialization */
/*                    sequence and the main loop  */
/* Author name:       julioalvesMS & IagoAF       */
/* Creation date:     08mar2018                   */
/* Revision date:     25abr2018                   */
/* ********************************************** */

/* System includes */
#include "Util\util.h"

/* Hardware abstraction layers */
#include "Buzzer\buzzer_hal.h"
#include "Mcg\mcg_hal.h"
#include "LedSwi\ledswi_hal.h"
#include "Display7Seg\display7seg_hal.h"

/* communication */
#include "Serial\serial.h"
#include "Protocolo\cmdMachine.h"



/* ****************************************************** */
/* Method name:         showHexNumber                     */
/* Method description:  Display a 2 bytes hex value using */
/*                      all four 7 segments displayes     */
/* Input params:        uiValue: Value to be shown        */
/* Output params:       n/a                               */
/* ****************************************************** */
void showHexNumber(unsigned int uiValue)
{
    /* Extreme left display */
    display7seg_setDisplay(uiValue%16,0,4);
    uiValue = uiValue/16;
    util_genDelay1ms();

    /* Middle left display */
    display7seg_setDisplay(uiValue%16,0,3);
    uiValue = uiValue/16;
    util_genDelay1ms();

    /* Middle right display */
    display7seg_setDisplay(uiValue%16,0,2);
    uiValue = uiValue/16;
    util_genDelay1ms();

    /* Extreme right display */
    display7seg_setDisplay(uiValue%16,0,1);
    util_genDelay1ms();
}

/* ************************************************ */
/* Method name:        playBuzz1ms                  */
/* Method description: Plays the buzzer for 1 ms    */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void playBuzz1ms(void)
{
    /* Wave 1 */
    buzzer_setBuzz();
    util_genDelay250us();
    buzzer_clearBuzz();
    util_genDelay250us();

    /* Wave 2 */
    buzzer_setBuzz();
    util_genDelay250us();
    buzzer_clearBuzz();
    util_genDelay250us();
}

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
        if(serial_hasData()){
            ucDataValue = serial_getChar();
            cmdMachine_stateProgression(ucDataValue, cLedsStates, piBuzzerTimer);
        }

        /* Set the LEDs ON/OFF according to the state vector */
        ledswi_changeAllLeds(cLedsStates);

        /* If needed, play the buzzer */
        if(iBuzzerTimer>0)
        {
            playBuzz1ms();
            iBuzzerTimer--;
        }

    } /* Never leave main */
    return 0;
}
