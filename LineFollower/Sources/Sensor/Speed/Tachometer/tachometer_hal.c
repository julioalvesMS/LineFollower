/* ***************************************************************** */
/* File name:        tachometer_hal.c                                */
/* File description: This file has a couple of useful functions to   */
/*                   control the tachometer from the peripheral board*/
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    03mai2018                                       */
/* Revision date:    03mai2018                                       */
/* ***************************************************************** */

#include "Domain/tachometer_entity.h"
#include "KL25Z/es670_peripheral_board.h"
#include "tachometer_hal.h"

#define CLKIN0 1U
#define EXTCLK_4 2U
#define EXTCLK_3 1U
#define UP_COUNTER_MODE 1U
#define PRESCALE_FACTOR_1 7U
#define OSCERCLK_25 2U
#define OSCERCLK_24 1U

#define INTERRUPTION_ENABLE        1U

#define EDGE_ALIGN_A        0U
#define EDGE_ALIGN_B        0U
#define HIGH_TRUE_A         1U
#define HIGH_TRUE_B         0U

#define CLOCK_FREQUENCY 	32000

static int leftPeriod;
static int rightPeriod;

void tachometer_left_init(void)
{

    /* Enable device */
    SIM_SCGC6 |= SIM_SCGC6_TPM0(CGC_CLOCK_ENABLED);

    /* Enable device */
    SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);

    PORTE_PCR29 |= PORT_PCR_MUX(LEFT_TACHOMETER_ALT);

    /* Select output port to counter */
    SIM_SOPT4 &= ~SIM_SOPT4_TPM0CLKSEL(CLKIN0);

    TPM0_SC &= ~TPM_SC_CPWMS(UP_COUNTER_MODE);

    /* Use a external clock */
    TPM0_SC &= ~TPM_SC_CMOD(EXTCLK_4);
    TPM0_SC |= TPM_SC_CMOD(EXTCLK_3);

    /* Set Prescale factor to 1:1 */
    TPM0_SC &= ~TPM_SC_PS(PRESCALE_FACTOR_1);

    TPM0_C0SC |= (TPM_CnSC_CHIE(INTERRUPTION_ENABLE) | TPM_CnSC_MSB(EDGE_ALIGN_B) | TPM_CnSC_MSA(EDGE_ALIGN_A) | TPM_CnSC_ELSB(HIGH_TRUE_B) | TPM_CnSC_ELSA(HIGH_TRUE_A));

    /* Uses the internal reference clock */
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(OSCERCLK_25);
    SIM_SOPT2 &= ~SIM_SOPT2_TPMSRC(OSCERCLK_24);
}


void tachometer_right_init(void)
{

    /* Enable device */
    SIM_SCGC6 |= SIM_SCGC6_TPM2(CGC_CLOCK_ENABLED);

    /* Enable device */
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    PORTA_PCR1 |= PORT_PCR_MUX(RIGHT_TACHOMETER_ALT);

    /* Select output port to counter */
    SIM_SOPT4 &= ~SIM_SOPT4_TPM0CLKSEL(CLKIN0);

    TPM2_SC &= ~TPM_SC_CPWMS(UP_COUNTER_MODE);

    /* Use a external clock */
    TPM2_SC &= ~TPM_SC_CMOD(EXTCLK_4);
    TPM2_SC |= TPM_SC_CMOD(EXTCLK_3);

    /* Set Prescale factor to 1:1 */
    TPM2_SC &= ~TPM_SC_PS(PRESCALE_FACTOR_1);

    TPM2_C0SC |= (TPM_CnSC_CHIE(INTERRUPTION_ENABLE) | TPM_CnSC_MSB(EDGE_ALIGN_B) | TPM_CnSC_MSA(EDGE_ALIGN_A) | TPM_CnSC_ELSB(HIGH_TRUE_B) | TPM_CnSC_ELSA(HIGH_TRUE_A));

    /* Uses the internal reference clock */
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(OSCERCLK_25);
    SIM_SOPT2 &= ~SIM_SOPT2_TPMSRC(OSCERCLK_24);
}

void tachometer_init(void)
{
	tachometer_left_init();
	tachometer_right_init();
}


void TPM0_IRQHandler(void)
{
	leftPeriod = TPM0_CNT & LEFT_TACHOMETER_READ_MASK;
    TPM0_CNT = 0;
}
void TPM2_IRQHandler(void)
{
	rightPeriod = TPM2_CNT & RIGHT_TACHOMETER_READ_MASK;
    TPM2_CNT = 0;
}


/* ************************************************ */
/* Method name:        timer_motor_setSpeed         */
/* Method description: Initialize the cooler device */
/* Input params:       dMotorSpeed = Motor power    */
/*                     controled by PWM duty cycle. */
/* Output params:      n/a                          */
/* ************************************************ */
double tachometer_readSensor(tachometer_entity tachomter)
{
	int period = 0;
	double speed = 0;

	switch(tachomter){
		case TACHOMETER_LEFT:
			period = leftPeriod;
			break;
		case TACHOMETER_RIGHT:
			period = rightPeriod;
			break;
		default:
			break;
	}

	if(period!=0)
		speed = CLOCK_FREQUENCY/(period*encoderSize);

	return speed;
}



