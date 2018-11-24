/*
 * emitter_hal.c
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */

#include "emitter_hal.h"
#include "KL25Z/es670_peripheral_board.h"

/* ************************************************ */
/* Method name:        cooler_initCooler            */
/* Method description: Initialize the board cooler. */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void emitter_init(void)
{
    /* Enable device */
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);
    /* Set as GPIO */
    PORTA_PCR13 |= PORT_PCR_MUX(TRACK_EMITTER_ALT);
    /* Set as Output */
    GPIOA_PDDR |= GPIO_PDDR_PDD(TRACK_EMITTER_DIR);
}


/* ***************************************************** */
/* Method name:        cooler_startCooler                */
/* Method description: Start the board cooler.           */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void emitter_turnOn(void)
{
    GPIOA_PSOR = GPIO_PSOR_PTSO(0x01 << TRACK_EMITTER_PIN);
}


/* ***************************************************** */
/* Method name:        cooler_stopCooler                 */
/* Method description: Stop the board cooler.            */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void emitter_turnOff(void)
{
    GPIOA_PCOR = GPIO_PCOR_PTCO(0x01 << TRACK_EMITTER_PIN);
}
