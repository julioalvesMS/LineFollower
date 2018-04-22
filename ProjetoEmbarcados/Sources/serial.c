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
/* Method name:        serial_init                  */
/* Method description: Initialize the serial port   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_init(void)
{
    /* Start serial communication */
    debugUart_init();

}


/* ************************************************ */
/* Method name:        serial_haveData              */
/* Method description: Informs if there is data in  */
/*                     the buffer that can be read  */
/* Input params:       n/a                          */
/* Output params:      char: 1 if true else 0       */
/* ************************************************ */
char serial_haveData(void)
{
    return UART0_BRD_S1_RDRF(UART0);
}


/* ************************************************ */
/* Method name:        serial_sendAck               */
/* Method description: Send "ACK" through the       */
/*                     serial port                  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_sendAck(void)
{
    PUTCHAR('A');
    PUTCHAR('C');
    PUTCHAR('K');
}


/* ************************************************ */
/* Method name:        serial_sendErr               */
/* Method description: Send "ERR" through the       */
/*                     serial port                  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_sendErr(void)
{
    PUTCHAR('E');
    PUTCHAR('R');
    PUTCHAR('R');
}
