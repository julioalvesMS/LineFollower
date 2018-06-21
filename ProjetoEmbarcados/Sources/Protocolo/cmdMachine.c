/* ***************************************************************** */
/* File name:        cmdMachine.c                                    */
/* File description: File dedicated for handling the state machine   */
/*                   responsable for the user interaction response.  */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    12abr2018                                       */
/* Revision date:    21jun2018                                       */
/* ***************************************************************** */

#include "cmdMachine.h"

/* System includes */
#include "KL25Z\es670_peripheral_board.h"

/* Hardware abstraction layers and communication */
#include "Serial\serial.h"
#include "LedSwi\ledswi_hal.h"
#include "Cooler\timer_counter.h"


/* ***************************************************** */
/* Method name:        cmdMachine_stateProgression       */
/* Method description: Change the state machine state    */
/*                     according to the user input       */
/* Input params:       ucDataValue = character read from */
/*                       the user input                  */
/*                     cLedsStates[] = vector containing */
/*                       data on what leds should be on  */
/*                     iBuzzerTimer = reference to a     */
/*                       variable containing the time in */
/*                       ms to play the buzzer           */
/* Output params:      n/a                               */
/* ***************************************************** */
void cmdMachine_stateProgression(unsigned char ucDataValue, char cLedsStates[], int* iBuzzerTimer)
{
    static state_machine_type_e ssmCurrentState = IDLE;
    static int siBuzzerTimer;
    static unsigned char sucCoolerSpeed;
    static unsigned char sucHeaterPower;

    state_machine_type_e smNextState = IDLE;
    char cErr = OK;
    switch(ssmCurrentState)
    {
        case IDLE:
            if('L'==ucDataValue)
                smNextState = LED;

            else if('S'==ucDataValue)
                smNextState = SWITCH;

            else if('B'==ucDataValue)
                smNextState = BUZZER;

            else if('C'==ucDataValue)
                smNextState = COOLER;

            else if('H'==ucDataValue)
                smNextState = HEATER;

            else
                cErr = ERR;

            break;

        case LED:
            if('S'==ucDataValue)
                smNextState = LED_SET;

            else if('C'==ucDataValue)
                smNextState = LED_CLEAR;

            else if('R'==ucDataValue)
                smNextState = LED_READ;

            else cErr = ERR;

            break;

        case LED_CLEAR:
            if('1'<=ucDataValue && ucDataValue <='4')
            {
                cLedsStates[ucDataValue-'1'] = 0;
                serial_sendAck();
            }
            else cErr = ERR;
            break;

        case LED_SET:
            if('1'<=ucDataValue && ucDataValue <='4')
            {
                cLedsStates[ucDataValue-'1'] = 1;
                serial_sendAck();
            }
            else cErr = ERR;
            break;

        case LED_READ:
            if('1'<=ucDataValue && ucDataValue <='4')
            {
                serial_sendAck();

                if(cLedsStates[ucDataValue-'1'] == 1)
                    serial_putChar('C');
                else
                	serial_putChar('O');
            }
            else cErr = ERR;
            break;

        case SWITCH:
            if('1'<=ucDataValue && ucDataValue <='4')
            {
                ledswi_initLedSwitch(0, 4);
                serial_sendAck();
                if(SWITCH_ON == ledswi_getSwitchStatus(ucDataValue-'0'))
                	serial_putChar('C');
                else
                	serial_putChar('O');
            }
            else cErr = ERR;
            break;

        case BUZZER:
            if('0'<=ucDataValue && ucDataValue <='9')
            {
                siBuzzerTimer = 100*(ucDataValue-'0');
                smNextState = BUZZER_TIMER_X00;
            }
            else cErr = ERR;
            break;

        case BUZZER_TIMER_X00:
            if('0'<=ucDataValue && ucDataValue <='9')
            {
                siBuzzerTimer = siBuzzerTimer + 10*(ucDataValue-'0');
                smNextState = BUZZER_TIMER_XX0;
            }
            else cErr = ERR;
            break;

        case BUZZER_TIMER_XX0:
            if('0'<=ucDataValue && ucDataValue <='9')
            {
                /* Update the buzzer timer variable with the read value */
                siBuzzerTimer = siBuzzerTimer + (ucDataValue-'0');
                (*iBuzzerTimer) = siBuzzerTimer;
                serial_sendAck();

            }
            else cErr = ERR;
            break;
        case COOLER:
            if('0'<=ucDataValue && ucDataValue <='9')
            {
            	sucCoolerSpeed = (ucDataValue-'0')*10;
            	smNextState = COOLER_SPEED_X0;

            }
            else cErr = ERR;
        	break;
        case COOLER_SPEED_X0:
            if('0'<=ucDataValue && ucDataValue <='9')
            {
            	sucCoolerSpeed += (ucDataValue-'0');
            	timer_cooler_setSpeed(sucCoolerSpeed);
                serial_sendAck();

            }
            else cErr = ERR;
        	break;
        case HEATER:
            if('0'<=ucDataValue && ucDataValue <='9')
            {
            	sucHeaterPower = (ucDataValue-'0')*10;
            	smNextState = HEATER_POT_X0;

            }
            else cErr = ERR;
        	break;
        case HEATER_POT_X0:
            if('0'<=ucDataValue && ucDataValue <='9')
            {
            	sucHeaterPower += (ucDataValue-'0');
            	timer_heater_changeTemperature(sucHeaterPower);
                serial_sendAck();

            }
            else cErr = ERR;
        	break;

    } /* switch(ssmCurrentState) */

    /* Changes the current state to the next */
    ssmCurrentState = smNextState;

    /* Send Error message in case of wrong input */
    if (ERR == cErr)
        serial_sendErr();
}
