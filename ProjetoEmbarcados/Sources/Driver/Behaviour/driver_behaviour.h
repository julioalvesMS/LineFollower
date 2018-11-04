/* ***************************************************************** */
/* File name:        cmdMachine.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the state machine       */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    12abr2018                                       */
/* Revision date:    28jun2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_DRIVER_BEHAVIOUR_H_
#define SOURCES_DRIVER_BEHAVIOUR_H_

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
void behaviour_update(unsigned char ucDataValue);

#endif /* SOURCES_DRIVER_BEHAVIOUR_H_ */
