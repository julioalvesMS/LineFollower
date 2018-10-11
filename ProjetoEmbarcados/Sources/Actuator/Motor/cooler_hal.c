/* ***************************************************************** */
/* File name:        cooler_hal.c                                    */
/* File description: This file has a couple of useful functions to   */
/*                   control the cooler from the peripheral board    */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    03mai2018                                       */
/* Revision date:    03mai2018                                       */
/* ***************************************************************** */

#include "motor_hal.h"
#include "KL25Z\es670_peripheral_board.h"

/* ************************************************ */
/* Method name:        cooler_initCooler            */
/* Method description: Initialize the board cooler. */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_initMotor(void)
{
    /* Enable device */
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);
    /* Set as GPIO */
    PORTA_PCR13 |= PORT_PCR_MUX(COOLER_ALT);
    /* Set as Output */
    GPIOA_PDDR |= GPIO_PDDR_PDD(COOLER_DIR);
}


/* ***************************************************** */
/* Method name:        cooler_startCooler                */
/* Method description: Start the board cooler.           */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void motor_startMotor(void)
{
    GPIOA_PSOR = GPIO_PSOR_PTSO(0x01 << COOLER_PIN);
}


/* ***************************************************** */
/* Method name:        cooler_stopCooler                 */
/* Method description: Stop the board cooler.            */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void motor_stopMotor(void)
{
    GPIOA_PCOR = GPIO_PCOR_PTCO(0x01 << COOLER_PIN);
}
