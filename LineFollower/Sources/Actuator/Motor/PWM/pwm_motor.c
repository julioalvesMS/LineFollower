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
#include "Domain/motor_entity.h"
#include "pwm_motor.h"

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

const double cdPwmPeriodProportion = PWM_PERIOD/(100.0);

/* ************************************************** */
/* Method name:        timer_initTPM1AsPWM            */
/* Method description: configure Timer1 to act as PWM */
/* Input params:       n/a                            */
/* Outpu params:       n/a                            */
/* ************************************************** */
void pwm_initTPM1AsPWM(void)
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
    TPM1_C1SC |= (TPM_CnSC_MSB(CH1_EDGE_ALIGN_B) | TPM_CnSC_MSA(CH1_EDGE_ALIGN_A) | TPM_CnSC_ELSB(CH1_HIGH_TRUE_B) | TPM_CnSC_ELSA(CH1_HIGH_TRUE_A));

    //TPM1_C1V = TPM_CnV_VAL(PWM_0pct);

    /* END COOLER CONFIGURATIONS */


    /* HEATER CONFIGURATIONS */

    /* Use edge aligned PWM mode */
    /* Use as High True */
    TPM1_C0SC |= (TPM_CnSC_MSB(CH0_EDGE_ALIGN_B) | TPM_CnSC_MSA(CH0_EDGE_ALIGN_A) | TPM_CnSC_ELSB(CH0_HIGH_TRUE_B) | TPM_CnSC_ELSA(CH0_HIGH_TRUE_A));

    //TPM1_C0V = TPM_CnV_VAL(PWM_0pct); //PWM 00%

    /* END HEATER CONFIGURATIONS */


    /* Resets CNT register */
    TPM1_CNT = TPM_CNT_COUNT(0x00U);

    TPM1_MOD = TPM_MOD_MOD(PWM_PERIOD);

}

/* ************************************************ */
/* Method name:        timer_motor_init             */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pwm_motor_init(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 |= SIM_SCGC5_PORTE(CGC_CLOCK_ENABLED);

    /* set pin as PWM */
    PORTE_PCR20 |= PORT_PCR_MUX(LEFT_MOTOR_ALT_PWM);
    /* set pin as PWM */
    PORTE_PCR21 |= PORT_PCR_MUX(RIGHT_MOTOR_ALT_PWM);

}


/* ************************************************ */
/* Method name:        timer_motor_setSpeed         */
/* Method description: Initialize the cooler device */
/* Input params:       dMotorSpeed = Motor power    */
/*                     controled by PWM duty cycle. */
/* Output params:      n/a                          */
/* ************************************************ */
void pwm_motor_setSpeed(motor_entity motor, double dMotorSpeed)
{
	int iPwmDutyCycle;

	if(dMotorSpeed<0) dMotorSpeed = 0;
	if(dMotorSpeed>100) dMotorSpeed = 100;

	double dPwmDutyCycle = (dMotorSpeed*PWM_PERIOD)/(100.0);
	double dDecimal = dPwmDutyCycle - ((int) dPwmDutyCycle);

	if(dDecimal >= 0.5)
		iPwmDutyCycle =(int) (dPwmDutyCycle - dDecimal + 1);
	else
		iPwmDutyCycle =(int) (dPwmDutyCycle - dDecimal);

	switch(motor){
		case MOTOR_LEFT:
			TPM1_C0V = TPM_CnV_VAL(iPwmDutyCycle);
			break;
		case MOTOR_RIGHT:
			TPM1_C1V = TPM_CnV_VAL(iPwmDutyCycle);
			break;
		default:
			break;
	}
}
