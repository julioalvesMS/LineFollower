/* ***************************************************************** */
/* File name:        timer_counter.c                                 */
/* File description: This file has a couple of useful functions to   */
/*                   control the PWM in TPM0 from the peripheral     */
/*                   board. The PWM is connected to both, cooler and */
/*                   heater.                                         */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    07jun2018                                       */
/* Revision date:    21jun2018                                       */
/* ***************************************************************** */

#include "KL25Z/es670_peripheral_board.h"
#include "fsl_tpm_hal.h"
#include "timer_counter.h"

#define LPTPM_COUNTER_MODE_4    2U
#define LPTPM_COUNTER_MODE_3    1U
#define UP_COUNTER_MODE         1U
#define PRESCALE_FACTOR_1       7U

#define CH1_INTERRUPTION        1U
#define CH1_EDGE_ALIGN_A        0U
#define CH1_EDGE_ALIGN_B        1U
#define CH1_HIGH_TRUE_A         0U
#define CH1_HIGH_TRUE_B         1U

#define CH0_EDGE_ALIGN_A        0U
#define CH0_EDGE_ALIGN_B        1U
#define CH0_HIGH_TRUE_A         0U
#define CH0_HIGH_TRUE_B         1U

const double cdPwmPeriodProportion = ((double) PWM_PERIOD)/(100.0);

/* ************************************************** */
/* Method name:        timer_initTPM1AsPWM            */
/* Method description: configure Timer1 to act as PWM */
/* Input params:       n/a                            */
/* Outpu params:       n/a                            */
/* ************************************************** */
void timer_initTPM1AsPWM(void)
{
    /* un-gate port clock for TPM1 */
    SIM_SCGC6 |= SIM_SCGC6_TPM1(CGC_CLOCK_ENABLED);

    /* Up counting mode */
    TPM1_SC &= ~TPM_SC_CPWMS(UP_COUNTER_MODE);

    /* LPTPM Counter increments on every LPTPM counter clock */
    TPM1_SC |= TPM_SC_CMOD(LPTPM_COUNTER_MODE_3);
    TPM1_SC &= ~TPM_SC_CMOD(LPTPM_COUNTER_MODE_4);

    /* Prescale ratio factor set to 1:1 */
    TPM1_SC &= ~TPM_SC_PS(PRESCALE_FACTOR_1);


    /* COOLER CONFIGURATIONS */

    /* Enable interruptions */
    /* Use edge aligned PWM mode */
    /* Use as High True */
    TPM1_C1SC |= TPM_CnSC_CHIE(CH1_INTERRUPTION) | TPM_CnSC_MSB(CH1_EDGE_ALIGN_B) | TPM_CnSC_ELSB(CH1_HIGH_TRUE_B);

    /* Resets CNT register */
    TPM1_CNT = TPM_CNT_COUNT(0x00U);

    //TPM1_MOD &= ~MASK_16BITS;
    TPM1_MOD = TPM_MOD_MOD(PWM_PERIOD);

    TPM1_C1V = TPM_CnV_VAL(PWM_0pct);

    /* END COOLER CONFIGURATIONS */


    /* HEATER CONFIGURATIONS */

    /* Use edge aligned PWM mode */
    /* Use as High True */
    TPM1_C0SC |= (TPM_CnSC_MSB(CH0_EDGE_ALIGN_B) | TPM_CnSC_MSA(CH0_EDGE_ALIGN_A) | TPM_CnSC_ELSB(CH0_HIGH_TRUE_B) | TPM_CnSC_ELSA(CH0_HIGH_TRUE_A));

    TPM1_C0V = PWM_0pct; //PWM 00%

    /* END HEATER CONFIGURATIONS */

}

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_cooler_init(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTA_PCR13 |= PORT_PCR_MUX(COOLER_ALT_PWM);

}


/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       ucCoolerSpeed = Cooler power */
/*                     controled by PWM duty cycle. */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_cooler_setSpeed(double dCoolerSpeed)
{
	int iPwmDutyCycle;
	double dPwmDutyCycle = cdPwmPeriodProportion*dCoolerSpeed;
	double dDecimal = dPwmDutyCycle - ((int) dPwmDutyCycle);

	if(dDecimal >= 0.5)
		iPwmDutyCycle =(int) (dPwmDutyCycle - dDecimal + 1);
	else
		iPwmDutyCycle =(int) (dPwmDutyCycle - dDecimal);

    TPM1_C1V = TPM_CnV_VAL(iPwmDutyCycle);
}


/* ************************************************** */
/* Method name:        timer_heater_changeTemperature */
/* Method description: Change the heater potency by   */
/*                     changing the PWM duty cycle.   */
/* Input params:       iPwm = Heater Potency {0..99}  */
/*                            controled by duty cycle */
/* Output params:      n/a                            */
/* ************************************************** */
void timer_heater_changeTemperature(int iPwm)
{
    if(iPwm>50){
        iPwm = 50;
    }
    iPwm = (iPwm*TPM1_MOD)/100;
    TPM1_C0V = iPwm;
}


/* ************************************************ */
/* Method name:        timer_initHeater             */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_heater_initHeater(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTA(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTA_PCR12 |= PORT_PCR_MUX(HEATER_ALT);
}
