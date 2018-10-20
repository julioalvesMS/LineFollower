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

pid_data_type pidLeftMotor, pidRightMotor;

const double cdMaxEstabilizationError = 1;

/* PID K Values */
const double Kp = 1;
const double Kd = 1;
const double Ki = 1;

int dMaxCoolerSpeed = 0.0;

/* ************************************************ */
/* Method name:        pid_init                     */
/* Method description: Initialize the PID controller*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(void)
{
	/* Left Motor PID */
	pidLeftMotor.dKp = Kp;
	pidLeftMotor.dKd = Kd;
	pidLeftMotor.dKi = Ki;
	pidLeftMotor.dSensor_previousValue = 0;
	pidLeftMotor.dError_sum = 0.0;

	/* Right Motor PID */
	pidRightMotor.dKp = Kp;
	pidRightMotor.dKd = Kd;
	pidRightMotor.dKi = Ki;
	pidRightMotor.dSensor_previousValue = 0;
	pidRightMotor.dError_sum = 0.0;
}


/* ************************************************** */
/* Method name:        pid_updateData                 */
/* Method description: Update the control output      */
/*                     using the reference and sensor */
/*                     value                          */
/* Input params:       dSensorValue: Value read from  */
/*                     the sensor                     */
/*                     dReferenceValue: Value used as */
/*                     control reference              */
/* Output params:      double: New Control effort     */
/* ************************************************** */
double pid_updateData(pid_data_type pidConfig, double dSensorValue, double dReferenceValue)
{
	double dError, dDifference, dOut;

	dError = dReferenceValue - dSensorValue;
	dDifference = pidConfig.dSensor_previousValue - dSensorValue;
	pidConfig.dError_sum += dError;

	dOut = pidConfig.dKp*dError + pidConfig.dKi*pidConfig.dError_sum + pidConfig.dKd*dDifference;

	pidConfig.dSensor_previousValue = dSensorValue;

	if (dOut>100.0)
		dOut = 100.0;

	else if (dOut<0.0)
		dOut = 0.0;

	return dOut;
}

double pid_controlMotor(motor_entity motor, double dSensorValue, double dReferenceValue)
{
	double controlValue = 0.0;
	switch(motor){
		case MOTOR_LEFT:
			controlValue = pid_updateData(pidLeftMotor, dSensorValue, dReferenceValue);
			break;
		case MOTOR_RIGHT:
			controlValue = pid_updateData(pidLeftMotor, dSensorValue, dReferenceValue);
			break;
		default:
			break;
	}
	return controlValue;
}
