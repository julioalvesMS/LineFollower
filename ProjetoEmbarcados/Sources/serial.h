/* ***************************************************************** */
/* File name:        buzzer_hal.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling BUZZER from the         */
/*                   peripheral board                                */
/* Author name:      dloubach                                        */
/* Creation date:    12jan2016                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_SERIAL_H_
#define SOURCES_SERIAL_H_
/* ***************************************************************** */
/* File name:        buzzer_hal.c                                    */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related buzzer from the peripheral board        */
/* Author name:      dloubach                                        */
/* Creation date:    12jan2016                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#define NOT_READ 255

/* ************************************************ */
/* Method name:        buzzer_init                  */
/* Method description: Initialize the buzzer device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void serial_init(void);

/* ************************************************ */
/* Method name:        buzzer_clearBuzz             */
/* Method description: Clear the buzzer             */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
char serial_haveData(void);
void serial_sendAck(void);

void serial_sendErr(void);

/* ************************************************ */
/* Method name:        buzzer_setBuz                */
/* Method description: Set the buzze                */
/* Input params:       n/a                          */
/* Output params:       n/a                         */
/* ************************************************ */
unsigned char serial_readData(void);

void serial_sendData(char cDataToSend);

#endif /* SOURCES_SERIAL_H_ */
