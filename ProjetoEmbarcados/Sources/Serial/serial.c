/* ***************************************************************** */
/* File name:        serial.c                                        */
/* File description: File dedicated to the abstraction of the serial */
/*                   port communication                              */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    12abr2018                                       */
/* Revision date:    25abr2018                                       */
/* ***************************************************************** */

#include "serial.h"

#include "KL25Z\es670_peripheral_board.h"
#include "Util\debugUart.h"
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"

unsigned char ucvBuffer[BUFFER_SIZE];

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
/* Method name:        serial_enableIRQ             */
/* Method description: Enable the interruption for  */
/*                     serial port inputs and       */
/*                     prepare the buffer           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_enableIRQ(void)
{
    int i;

    /* Start all buffer positions as \0 */
    for(i=0;i<BUFFER_SIZE;i++)
        ucvBuffer[i] = '\0';

    /* Enable interruption */
    NVIC_EnableIRQ(UART0_IRQn);
    UART0_C2_REG(UART0) |= UART0_C2_RIE(1);
}


/* ************************************************ */
/* Method name:        UART0_IRQHandler             */
/* Method description: Serial port interruption     */
/*                     handler method. It Reads the */
/*                     new character and saves in   */
/*                     the buffer                   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void UART0_IRQHandler(void)
{
    static unsigned char ucBufferPointer = 0;
    ucvBuffer[ucBufferPointer] = GETCHAR();
    ucBufferPointer = (ucBufferPointer+1)%BUFFER_SIZE;
}


/* ************************************************** */
/* Method name:        serial_bufferReadData          */
/* Method description: Gets the next unread character */
/*                     in the buffer. Returns 0 if    */
/*                     there is nothing new.          */
/* Input params:       n/a                            */
/* Output params:      unsigned char: Next char       */
/*                     in buffer                      */
/* ************************************************** */
unsigned char serial_bufferReadData(void)
{
    static unsigned char ucBufferPointer = 0;
    unsigned char ucData = ucvBuffer[ucBufferPointer];
    if(ucData != '\0')
    {
        ucvBuffer[ucBufferPointer] = '\0';
        ucBufferPointer = (ucBufferPointer+1)%BUFFER_SIZE;
    }
    return ucData;
}


/* ************************************************ */
/* Method name:        serial_hasData               */
/* Method description: Informs if there is data in  */
/*                     the buffer that can be read  */
/* Input params:       n/a                          */
/* Output params:      char: 1 if true else 0       */
/* ************************************************ */
char serial_hasData(void)
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
    serial_sendLineBreak();
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
    serial_sendLineBreak();
}

/* ************************************************ */
/* Method name:        serial_sendADConversion      */
/* Method description: Sends a 3 digits value from  */
/*                     the AD through the serial    */
/*                     port                         */
/* Input params:       ucValue = value to send      */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_sendADConversion(unsigned char ucValue)
{
    PUTCHAR('0'+ucValue/100);
    ucValue = ucValue%100;
    PUTCHAR('0'+ucValue/10);
    ucValue = ucValue%10;
    PUTCHAR('0'+ucValue);
    serial_sendLineBreak();
}

/* ************************************************ */
/* Method name:        serial_sendLineBreak         */
/* Method description: Send a line break through    */
/*                     to the serial port           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_sendLineBreak()
{
    PUTCHAR(13);
    PUTCHAR(10);
}

/* ************************************************ */
/* Method name:        serial_getChar               */
/* Method description: Reads a character            */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
unsigned char serial_getChar()
{
    return GETCHAR();
}


/* ************************************************ */
/* Method name:        serial_putChar               */
/* Method description: Sends a character            */
/* Input params:       ucDataToSend: Character to   */
/*                       be sent                    */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_putChar(unsigned char ucDataToSend)
{
    PUTCHAR(ucDataToSend);
}
