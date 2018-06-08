
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


void timer_cooler_setSpeed(unsigned char ucCoolerSpeed);



#endif /* SOURCES_TIMER_COUNTER_HAL_H_ */
