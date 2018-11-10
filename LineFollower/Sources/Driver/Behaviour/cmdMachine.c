/* ***************************************************************** */
/* File name:        cmdMachine.c                                    */
/* File description: File dedicated for handling the state machine   */
/*                   responsable for the user interaction response.  */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    12abr2018                                       */
/* Revision date:    28jun2018                                       */
/* ***************************************************************** */

#include "cmdMachine.h"

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
void cmdMachine_stateProgression(unsigned char ucDataValue)
{
    static state_machine_type_e ssmCurrentState = INIT;

    state_machine_type_e smNextState = IDLE;

    switch(ssmCurrentState)
    {
    	default:
            break;

    } /* switch(ssmCurrentState) */

    /* Changes the current state to the next */
    ssmCurrentState = smNextState;
}
