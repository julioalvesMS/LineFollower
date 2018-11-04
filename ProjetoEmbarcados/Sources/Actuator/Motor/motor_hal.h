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
/* Method name:        cooler_initCooler            */
/* Method description: Initialize the board cooler. */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_initMotorPWM(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       ucCoolerSpeed = Cooler power */
/*                     controled by PWM duty cycle. */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_setSpeed(double motorSpeed[]);

#endif /* SOURCES_MOTOR_HAL_H_ */
