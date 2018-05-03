/* ***************************************************************** */
/* File name:        cooler_hal.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the cooler from the     */
/*                   peripheral board                                */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    03mai2018                                       */
/* Revision date:    03mai2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_COOLER_HAL_H_
#define SOURCES_COOLER_HAL_H_


/* ************************************************ */
/* Method name:        cooler_initCooler            */
/* Method description: Initialize the board cooler. */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void cooler_initCooler(void);


/* ***************************************************** */
/* Method name:        cooler_startCooler                */
/* Method description: Start the board cooler.           */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void cooler_startCooler(void);


/* ***************************************************** */
/* Method name:        cooler_stopCooler                 */
/* Method description: Stop the board cooler.            */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void cooler_stopCooler(void);

#endif /* SOURCES_COOLER_HAL_H_ */
