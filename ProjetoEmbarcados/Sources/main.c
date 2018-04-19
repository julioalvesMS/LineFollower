/* ********************************************** */
/* File name:					main.c            */
/* File description:  Main file of the code.      */
/*                    Contains the initialization */
/*                    sequence and the main loop  */
/* Author name:       julioalvesMS IagoAF         */
/* Creation date:     08mar2018                   */
/* Revision date:     05abr2018                   */
/* ********************************************** */

#include "fsl_device_registers.h"
#include "util.h"
#include "buzzer_hal.h"
#include "mcg_hal.h"
#include "ledswi_hal.h"
#include "display7seg_hal.h"
#include "debugUart.h"
#include "fsl_debug_console.h"
#include "serial.h"
#include "stateMachine.h"

void playBuzzer1ms(void)
{
	buzzer_setBuzz();
	util_genDelay250us();
	buzzer_clearBuzz();
	util_genDelay250us();
}

void showDisplay7Seg(unsigned int iValue)
{
	display7seg_setDisplay(iValue%16,0,4);
	iValue = iValue/16;
	util_genDelay1ms();

	display7seg_setDisplay(iValue%16,0,3);
	iValue = iValue/16;
	util_genDelay1ms();

	display7seg_setDisplay(iValue%16,0,2);
	iValue = iValue/16;
	util_genDelay1ms();

	display7seg_setDisplay(iValue%16,0,1);
	util_genDelay1ms();
}

/* ****************************************************** */
/* Method name:         setupPeripherals                  */
/* Method description:  Makes the necessaries setups and  */
/*                      initializations for a proper      */
/*                      preparation of the peripherals    */
/* Input params:                n/a                       */
/* Output params:               n/a                       */
/* ****************************************************** */
void setupPeripherals()
{
	/* Start clock */
	mcg_clockInit();

	/* Start serial communication */
	serial_init();

	/* Start leds */
	ledswi_initLedSwitch(0, 4);

	/* Start display7seg */
	display7seg_initDisplay();

	buzzer_init();
}

/* ****************************************************** */
/* Method name:         main                              */
/* Method description:  System main function. Contains    */
/*                      all the code that will actually   */
/*                      run                               */
/* Input params:                n/a                       */
/* Output params:               n/a                       */
/* ****************************************************** */
int main(void)
{

	unsigned char ucDataValue;
	char cLedsStates[4] = {0, 0, 0, 0};
	int iBuzzerTimer = 0;
	int *piBuzzerTimer = &iBuzzerTimer;

	setupPeripherals();


	for (int i=0;;i++)
	{
		if(UART0_BRD_S1_RDRF(UART0)){
			ucDataValue = GETCHAR();
			stateMachine_stateProgression(ucDataValue, cLedsStates, piBuzzerTimer);
		}

		/* Turn on the LED if the corresponding switch is on */
		ledswi_initLedSwitch(4, 0);
		if(cLedsStates[0])
		{
			ledswi_setLed(1);
		}
		else
		{
			ledswi_clearLed(1);
		}

		if(cLedsStates[1])
		{
			ledswi_setLed(2);
		}
		else
		{
			ledswi_clearLed(2);
		}

		if(cLedsStates[2])
		{
			ledswi_setLed(3);
		}
		else
		{
			ledswi_clearLed(3);
		}

		if(cLedsStates[3])
		{
			ledswi_setLed(4);
		}
		else
		{
			ledswi_clearLed(4);
		}

		/* Shows a counter in the display 7 segments */

		/*
		 * Rate of 1/100 of loop count to displayed count,
		 * otherwise the counter is to fast
		 */
		if(iBuzzerTimer>0)
		{
			playBuzzer1ms();
			iBuzzerTimer--;
		}

		/*
		 * Puts the counter in the displays.
		 * We need to put a delay between each display in order to avoid
		 * having the same data showing in multiple displays
		 */


	} /* Never leave main */
	return 0;
}
