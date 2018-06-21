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

#define CLKIN0 1U
#define EXTCLK_4 2U
#define EXTCLK_3 1U
#define PRESCALE_FACTOR_1 7U
#define OSCERCLK_25 2U
#define OSCERCLK_24 1U

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
    SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);

    PORTE_PCR29 |= PORT_PCR_MUX(TACHOMETER_ALT);

    /* Select output port to counter */
    SIM_SOPT4 &= ~SIM_SOPT4_TPM0CLKSEL(CLKIN0);

    /* Use a external clock */
    TPM0_SC |= TPM_SC_CMOD(EXTCLK_4);
    TPM0_SC &= ~TPM_SC_CMOD(EXTCLK_3);

    /* Set Prescale factor to 1:1 */
    TPM0_SC &= ~TPM_SC_PS(PRESCALE_FACTOR_1);

    /* Uses the internal reference clock */
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(OSCERCLK_25);
    SIM_SOPT2 &= ~SIM_SOPT2_TPMSRC(OSCERCLK_24);
}


/* ***************************************************** */
/* Method name:        tachometer_readSensor             */
/* Method description: Read the board tachometer sensor. */
/* Input params:       n/a                               */
/* Output params:      int                               */
/* ***************************************************** */
int tachometer_readSensor(void)
{
    int iCoolerSpeed = TPM0_CNT & TACHOMETER_READ_MASK;
    TPM0_CNT = 0;
    return iCoolerSpeed/7;
}



