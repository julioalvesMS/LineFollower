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

#define PWM_PERIOD 4000
#define PWM_0pct   0
#define PWM_100pct 3999.0

/* ************************************************** */
/* Method name:        timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:       n/a                   */
/* Outpu params:       n/a                       */
/* ************************************************** */
void pwm_initTPM1AsPWM(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pwm_motor_init(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       ucCoolerSpeed = Cooler power */
/*                     controled by PWM duty cycle. */
/* Output params:      n/a                          */
void pwm_motor_setSpeed(motor_entity motor, double dMotorSpeed);

#endif /* SOURCES_TIMER_COUNTER_HAL_H_ */
