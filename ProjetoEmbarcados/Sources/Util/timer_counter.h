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

#define PWM_PERIOD 99
#define PWM_100pct PWM_PERIOD
#define PWM_75pct  PWM_PERIOD*3/4
#define PWM_50pct  PWM_PERIOD/2
#define PWM_25pct  PWM_PERIOD/4
#define PWM_0pct   0

#ifndef SOURCES_TIMER_COUNTER_HAL_H_
#define SOURCES_TIMER_COUNTER_HAL_H_


/* ************************************************** */
/* Method name: 	   timer_initTPM1AsPWM        */
/* Method description: configure Timer1 to act as PWM */
/* Input params:	   n/a 			      */
/* Outpu params:	   n/a 		              */
/* ************************************************** */
void timer_initTPM1AsPWM(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_cooler_init(void);

/* ************************************************ */
/* Method name:        timer_coolerfan_init         */
/* Method description: Initialize the cooler device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_cooler_setSpeed(unsigned char ucCoolerSpeed);

/* ************************************************** */
/* Method name:        timer_heater_changeTemperature */
/* Method description: Change the heater potency by   */
/*                     changing the PWM duty cycle.   */
/* Input params:       iPwm = Heater Potency {0..99}  */
/*                            controled by duty cycle */
/* Output params:      n/a                            */
/* ************************************************** */
void timer_heater_changeTemperature(int iPwm);

/* ************************************************ */
/* Method name:        timer_initHeater             */
/* Method description: Initialize the heater device */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void timer_heater_initHeater(void);

#endif /* SOURCES_TIMER_COUNTER_HAL_H_ */
