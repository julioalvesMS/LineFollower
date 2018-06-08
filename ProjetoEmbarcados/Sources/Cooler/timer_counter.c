#include "KL25Z/es670_peripheral_board.h"
#include "fsl_tpm_hal.h"
#include "timer_counter.h"

#define LPTPM_COUNTER_MODE_4    2U
#define LPTPM_COUNTER_MODE_3    1U
#define UP_COUNTER_MODE         1U
#define PRESCALE_FACTOR_1       7U
#define CH1_INTERRUPTION        1U
#define CH1_EDGE_ALIGN          1U
#define CH1_HIGH_TRUE           1U

/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM            */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a                            */
/* Outpu params:	   n/a                            */
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

    /* Enable interruptions */
	/* Use edge aligned PWM mode */
	/* Use as High True */
	TPM1_C1SC |= TPM_CnSC_CHIE(CH1_INTERRUPTION) | TPM_CnSC_MSB(CH1_EDGE_ALIGN) | TPM_CnSC_ELSB(CH1_HIGH_TRUE);

	/* Resets CNT register */
	TPM1_CNT = TPM_CNT_COUNT(0x00U);

	//TPM1_MOD &= ~MASK_16BITS;
	TPM1_MOD = TPM_MOD_MOD(PWM_PERIOD);

<<<<<<< Updated upstream
    TPM1_C1V = TPM_CnV_VAL(PWM_100pct*85/100); //PWM 100%
//	TPM1_C1V = TPM_CnV_VAL(PWM_75pct); //PWM 75%
//	TPM1_C1V = TPM_CnV_VAL(PWM_50pct); //PWM 50%
//	TPM1_C1V = TPM_CnV_VAL(PWM_25pct); //PWM 25%
//	TPM1_C1V = TPM_CnV_VAL(PWM_0pct); //PWM 0%
=======
    TPM1_C1V = TPM_CnV_VAL(PWM_0pct);
>>>>>>> Stashed changes


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

void timer_cooler_setSpeed(unsigned char ucCoolerSpeed)
{
<<<<<<< Updated upstream
	switch(cCoolerSpeed)
	{
		case 4:
			TPM1_C1V = TPM_CnV_VAL(PWM_100pct); //PWM 100%
			break;
		case 3:
			TPM1_C1V = TPM_CnV_VAL(PWM_75pct); //PWM 75%
			break;
		case 2:
			TPM1_C1V = TPM_CnV_VAL(PWM_50pct); //PWM 50%
			break;
		case 1:
			TPM1_C1V = TPM_CnV_VAL(PWM_25pct); //PWM 25%
			break;
		case 0:
		default:
			TPM1_C1V = TPM_CnV_VAL(PWM_0pct); //PWM 0%
			break;
	}
=======
	TPM1_C1V = TPM_CnV_VAL(PWM_PERIOD * ucCoolerSpeed/100);
>>>>>>> Stashed changes
}
