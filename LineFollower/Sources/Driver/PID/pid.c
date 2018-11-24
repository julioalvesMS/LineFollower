/* ***************************************************************** */
/* File name:        pid.c                                           */
/* File description: This file has a couple of useful functions to   */
/*                   control the implemented PID controller          */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    21jun2018                                       */
/* Revision date:    28jun2018                                       */
/* ***************************************************************** */

#include "Domain/motor_entity.h"
#include "pid.h"

pid_data_type pidConfig;

/* PID K Values */
const double Kp = 3;
const double Kd = 9;
const double Ki = 0;

/* ************************************************ */
/* Method name:        pid_init                     */
/* Method description: Initialize the PID controller*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(void)
{
	/* Left Motor PID */
	pidConfig.Kp = Kp;
	pidConfig.Kd = Kd;
	pidConfig.Ki = Ki;
	pidConfig.PreviousValue = 0;
	pidConfig.ErrorSum = 0.0;
}


/* ************************************************** */
/* Method name:        pid_updateData                 */
/* Method description: Update the control output      */
/*                     using the reference and sensor */
/*                     value                          */
/* Input params:       sensorValue: Value read from  */
/*                     the sensor                     */
/*                     referenceValue: Value used as */
/*                     control reference              */
/* Output params:      double: New Control effort     */
/* ************************************************** */
double pid_updateData(double sensorValue, double referenceValue)
{
	double Error, difference, out;

	Error = referenceValue - sensorValue;
	difference = pidConfig.PreviousValue - sensorValue;
	/* pidConfig.ErrorSum += Error; */

	out = pidConfig.Kp*Error + pidConfig.Ki*pidConfig.ErrorSum + pidConfig.Kd*difference;

	pidConfig.PreviousValue = sensorValue;

	if (out>100.0)
		out = 100.0;

	else if (out<-100.0)
		out = -100.0;

	return out;
}
