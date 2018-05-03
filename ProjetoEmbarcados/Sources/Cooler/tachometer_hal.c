/* ***************************************************************** */
/* File name:        tachometer_hal.c                                */
/* File description: This file has a couple of useful functions to   */
/*                   control the tachometer from the peripheral board*/
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    03mai2018                                       */
/* Revision date:    03mai2018                                       */
/* ***************************************************************** */

#include "tachometer_hal.h"
#include "KL25Z\es670_peripheral_board.h"

/* ************************************************ */
/* Method name:        tachometer_initSensor        */
/* Method description: Initialize the board         */
/*                     tachometer sensor.           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void tachometer_initSensor(void)
{
	/* Enable device */
    SIM_SCGC6 |= SIM_SCGC6_TPM0(CGC_CLOCK_ENABLED);

	/* Enable device */
    SIM_SOPT4 &= ~SIM_SOPT4_TPM0CLKSEL(CLKIN0);

    /* FEITO ATE AQUI */
    /* 553, 196 */

    /* Set as GPIO */
    PORTA_PCR13 |= PORT_PCR_MUX(COOLER_ALT);
    /* Set as Output */
    GPIOA_PDDR |= GPIO_PDDR_PDD(COOLER_DIR);
}


/* ***************************************************** */
/* Method name:        tachometer_readSensor             */
/* Method description: Read the board tachometer sensor. */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void tachometer_readSensor(void)
{
    GPIOA_PSOR = GPIO_PSOR_PTSO(0x01 << COOLER_PIN);
}

