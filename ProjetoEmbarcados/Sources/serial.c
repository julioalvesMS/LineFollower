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

/* ************************************************ */
/* Method name:        buzzer_setBuz                */
/* Method description: Set the buzze                */
/* Input params:       n/a                          */
/* Output params:       n/a                         */
/* ************************************************ */
unsigned char serial_readData(void)
{
	return GETCHAR();
}

void serial_sendData(char cDataToSend)
{
	PUTCHAR(cDataToSend);
}
