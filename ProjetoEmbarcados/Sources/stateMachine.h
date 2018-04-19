/* ***************************************************************** */
/* File name:        buzzer_hal.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling BUZZER from the         */
/*                   peripheral board                                */
/* Author name:      dloubach                                        */
/* Creation date:    12jan2016                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_STATEMASCHINE_H_
#define SOURCES_STATEMASCHINE_H_
/* ***************************************************************** */
/* File name:        buzzer_hal.c                                    */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related buzzer from the peripheral board        */
/* Author name:      dloubach                                        */
/* Creation date:    12jan2016                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#define NOT_READ 255

typedef enum
{
    IDLE,

    LED,LED_CLEAR,LED_SET,

	SWITCH,

	BUZZER,BUZZER_TIMER_X00, BUZZER_TIMER_XX0,
} state_machine_type_e;

void stateMachine_readSwitch(char cSwitchID);

void stateMachine_stateProgression(unsigned char ucDataValue, char cLedsStates[], int* iBuzzerTimer);

#endif /* SOURCES_STATEMASCHINE_H_ */
