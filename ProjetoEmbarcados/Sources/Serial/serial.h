/* ***************************************************************** */
/* File name:        serial.h                                        */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the serial port         */
/*                   communication                                   */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    12abr2018                                       */
/* Revision date:    25abr2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_SERIAL_H_
#define SOURCES_SERIAL_H_

#define BUFFER_SIZE 16

/* ************************************************ */
/* Method name:        serial_init                  */
/* Method description: Initialize the serial port   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_init(void);

void serial_enableIRQ(void);
void UART0_IRQHandler(void);
unsigned char serial_bufferReadData(void);


/* ************************************************ */
/* Method name:        serial_hasData               */
/* Method description: Informs if there is data in  */
/*                     the buffer that can be read  */
/* Input params:       n/a                          */
/* Output params:      char: 1 if true else 0       */
/* ************************************************ */
char serial_hasData(void);


/* ************************************************ */
/* Method name:        serial_sendAck               */
/* Method description: Send "ACK" through the       */
/*                     serial port                  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_sendAck(void);


/* ************************************************ */
/* Method name:        serial_sendErr               */
/* Method description: Send "ERR" through the       */
/*                     serial port                  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_sendErr(void);


/* ************************************************ */
/* Method name:        serial_getChar               */
/* Method description: Reads a character            */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
unsigned char serial_getChar();


/* ************************************************ */
/* Method name:        serial_putChar               */
/* Method description: Sends a character            */
/* Input params:       cDataToSend: Character to    */
/*                       be sent                    */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_putChar(unsigned char cDataToSend);

#endif /* SOURCES_SERIAL_H_ */
