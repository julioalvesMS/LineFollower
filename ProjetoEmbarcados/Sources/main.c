/* ********************************************** */
/* File name:					main.c            */
/* File description:  Main file of the code.      */
/*                    Contains the initialization */
/*                    sequence and the main loop  */
/* Author name:       julioalvesMS                */
/* Creation date:     08mar2018                   */
/* Revision date:     15mar2018                   */
/* ********************************************** */

#include "fsl_device_registers.h"
#include "util.h"
#include "buzzer_hal.h"
#include "mcg_hal.h"
#include "ledswi_hal.h"

/* ****************************************************** */
/* Method name:         setupPeripherals                  */
/* Method description:  Makes the necessaries setups and  */
/*                      initializatios for a proper       */
/*                      preparation of the peripherals    */
/* Input params:                n/a                       */
/* Output params:               n/a                       */
/* ****************************************************** */
void setupPeripherals()
{
	/* Start clock */
	mcg_clockInit();

	/* Start leds */
	ledswi_initLedSwitch(0, 4);
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

	switch_status_type_e e1, e2, e3, e4;
	setupPeripherals();


	for (;;)
	{

		ledswi_initLedSwitch(0, 4);
		e1 = ledswi_getSwitchStatus(1);
		e2 = ledswi_getSwitchStatus(2);
		e3 = ledswi_getSwitchStatus(3);
		e4 = ledswi_getSwitchStatus(4);

		ledswi_initLedSwitch(4, 0);
		if(SWITCH_ON == e1)
		{
			ledswi_setLed(1);
		}
		else
		{
			ledswi_clearLed(1);
		}

		if(SWITCH_ON == e2)
		{
			ledswi_setLed(2);
		}
		else
		{
			ledswi_clearLed(2);
		}

		if(SWITCH_ON == e3)
		{
			ledswi_setLed(3);
		}
		else
		{
			ledswi_clearLed(3);
		}

		if(SWITCH_ON == e4)
		{
			ledswi_setLed(4);
		}
		else
		{
			ledswi_clearLed(4);
		}
	}

	/* Never leave main */
	return 0;
}
