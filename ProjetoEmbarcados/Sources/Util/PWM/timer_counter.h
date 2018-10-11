/* ***************************************************************** */
/* File name:        tachometer_hal.h                                */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the PWM in TPM0, thus   */
/*                   also the heater and cooler from the peripheral  */
/*                   board.                                          */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    07jun2018                                       */
/* Revision date:    21jun2018                                       */
/* ***************************************************************** */


#ifndef SOURCES_TIMER_COUNTER_HAL_H_
#define SOURCES_TIMER_COUNTER_HAL_H_

#define PWM_PERIOD 99
#define PWM_0pct   0
#define PWM_100pct 99.0

/* ************************************************** */
/* Method name:        timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:       n/a                   */
/* Outpu params:       n/a                       */
/* ************************************************** */
void timer_initTPM1AsPWM(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_motor_init(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       ucCoolerSpeed = Cooler power */
/*                     controled by PWM duty cycle. */
/* Output params:      n/a                          */
void timer_motor_setSpeed(double dCoolerSpeed);

#endif /* SOURCES_TIMER_COUNTER_HAL_H_ */
