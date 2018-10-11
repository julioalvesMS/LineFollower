/* ***************************************************************** */
/* File name:        cooler_hal.h                                    */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the cooler from the     */
/*                   peripheral board                                */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    03mai2018                                       */
/* Revision date:    03mai2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_MOTOR_HAL_H_
#define SOURCES_MOTOR_HAL_H_


/* ************************************************ */
/* Method name:        motor_initMotor            */
/* Method description: Initialize the board cooler. */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_initMotor(void);


/* ***************************************************** */
/* Method name:        motor_startMotor                */
/* Method description: Start the board cooler.           */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void motor_startMotor(void);


/* ***************************************************** */
/* Method name:        motor_stopMotor                 */
/* Method description: Stop the board cooler.            */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void motor_stopMotor(void);

#endif /* SOURCES_MOTOR_HAL_H_ */
