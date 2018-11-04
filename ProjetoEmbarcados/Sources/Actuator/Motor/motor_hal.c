/* ***************************************************************** */
/* File name:        cooler_hal.c                                    */
/* File description: This file has a couple of useful functions to   */
/*                   control the cooler from the peripheral board    */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    03mai2018                                       */
/* Revision date:    03mai2018                                       */
/* ***************************************************************** */

#include "motor_hal.h"
#include "KL25Z/es670_peripheral_board.h"
#include "Domain/motor_entity.h"
#include "PID/pid.h"
#include "PWM/pwm_motor.h"


/* ************************************************ */
/* Method name:        cooler_initCooler            */
/* Method description: Initialize the board cooler. */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void motor_initMotorPWM(void)
{
	pwm_initTPM1AsPWM();
	pwm_motor_init();
	pid_init();
}


/* ************************************************ */
/* Method name:        motor_setSpeed               */
/* Method description: Initialize the cooler device */
/* Input params:       ucCoolerSpeed = Cooler power */
/*                     controled by PWM duty cycle. */
/* Output params:      n/a                          */
void motor_setSpeed(driver_out_entity driverControl)
{
	double leftDuty, rightDuty;

	leftDuty = pid_motor_control(MOTOR_LEFT, driverControl.SpeedSensor[0], driverControl.MotorSpeed[0]);
	rightDuty = pid_motor_control(MOTOR_RIGHT, driverControl.SpeedSensor[1], driverControl.MotorSpeed[1]);

	pwm_motor_setSpeed(MOTOR_LEFT, leftDuty);
	pwm_motor_setSpeed(MOTOR_RIGHT, rightDuty);
}
