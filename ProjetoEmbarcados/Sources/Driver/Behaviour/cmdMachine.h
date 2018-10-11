/* ***************************************************************** */
/* File name:        cmdMachine.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the state machine       */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    12abr2018                                       */
/* Revision date:    28jun2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_CMDMASCHINE_H_
#define SOURCES_CMDMASCHINE_H_

typedef enum
{
    INIT, IDLE, RUN, STOP
} state_machine_type_e;


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
void cmdMachine_stateProgression(unsigned char ucDataValue);

#endif /* SOURCES_CMDMASCHINE_H_ */
