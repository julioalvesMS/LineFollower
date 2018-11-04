/* ***************************************************************** */
/* File name:        cmdMachine.c                                    */
/* File description: File dedicated for handling the state machine   */
/*                   responsable for the user interaction response.  */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    12abr2018                                       */
/* Revision date:    28jun2018                                       */
/* ***************************************************************** */

#include "Domain/common.h"
#include "Domain/driver_entity.h"
#include "driver_behaviour.h"

bool behaviour_checkStopCondition(driver_in_entity driverInput)
{
  return false;
}

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
void behaviour_update(driver_in_entity driverInput)
{
    driver_state nextState = driverInput.CurrentState;

    switch(driverInput.CurrentState)
    {
      case START:
        nextState = DRIVE;
        break;
      case DRIVE:
        if (behaviour_checkStopCondition(driverInput))
          nextState = STOP;
        break
    	default:
        break;

    } /* switch(driverInput.CurrentState) */

    /* Changes the current state to the next */
    driverInput.CurrentState = nextState;
}
