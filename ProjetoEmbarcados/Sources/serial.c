/* ***************************************************************** */
/* File name:        buzzer_hal.c                                    */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related buzzer from the peripheral board        */
/* Author name:      dloubach                                        */
/* Creation date:    12jan2016                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#include "serial.h"
#include "es670_peripheral_board.h"
#include "debugUart.h"
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"


/* ************************************************ */
/* Method name:        buzzer_init                  */
/* Method description: Initialize the buzzer device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_init(void)
{
	/* Start serial communication */
	debugUart_init();

}


/* ************************************************ */
/* Method name:        buzzer_clearBuzz             */
/* Method description: Clear the buzzer             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
char serial_haveData(void)
{
	return UART0_BRD_S1_RDRF(UART0);
}

void serial_sendAck(void)
{
	PUTCHAR('A');
	PUTCHAR('C');
	PUTCHAR('K');
	PUTCHAR('\r');
}

void serial_sendErr(void)
{
	PUTCHAR('E');
	PUTCHAR('R');
	PUTCHAR('R');
	PUTCHAR('\r');
}

void serial_ledCommand(void)
{
	unsigned char action = NOT_READ;
	unsigned char ledID = NOT_READ;
	if(UART0_BRD_S1_RDRF(UART0))
	{
		action = GETCHAR();
		if(action != 'C' && action != 'S'){
			action = NOT_READ;
		}
	}

	if(UART0_BRD_S1_RDRF(UART0) && action != NOT_READ)
	{
		ledID = GETCHAR();
		if(ledID < '1' || ledID > '4'){
			ledID = NOT_READ;
		}
	}

	if(ledID != NOT_READ)
	{
		serial_sendAck();
		/* EXECUTA */
	}
	else
	{
		serial_sendErr();
	}
}

/* ************************************************ */
/* Method name:        buzzer_setBuz                */
/* Method description: Set the buzze                */
/* Input params:       n/a                          */
/* Output params:       n/a                         */
/* ************************************************ */
unsigned char serial_readData(void)
{
	unsigned char ucDataValue = NOT_READ;
	if(UART0_BRD_S1_RDRF(UART0))
	{
		ucDataValue = GETCHAR();
	}
	return ucDataValue;
}


void serial_stateMachine(void)
{
	static state_machine_type_e ssmCurrentState;
}

