/*
 * pid_hal.c
 *
 *  Created on: 21/06/2018
 *      Author: aluno
 */

#include "pid.h"

pid_data_type pidConfig;

const double cdMaxEstabilizationError = 0.5;

double dMaxCoolerSpeed = 0.0;

/* ************************************************ */
/* Method name:        serial_init                  */
/* Method description: Initialize the serial port   */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(void)
{
	pidConfig.dKp = 0.0;
	pidConfig.dKd = 0.0;
	pidConfig.dKi = 0.0;
	pidConfig.dSensor_previousValue = 0.0;
	pidConfig.dError_sum = 0.0;
}

void pid_setKp(double dKp)
{
	pidConfig.dKp = dKp;
}


void pid_setKd(double dKd)
{
	pidConfig.dKd = dKd;
}


void pid_setKi(double dKi)
{
	pidConfig.dKi = dKi;
}

double pid_updateData(double dSensorValue, double dReferenceValue)
{
	double dError, dDifference, dOut;

	dError = dReferenceValue - dSensorValue;
	dDifference = pidConfig.dSensor_previousValue - dSensorValue;
	pidConfig.dError_sum += dError;

	dOut = pidConfig.dKp*dError + pidConfig.dKi*pidConfig.dError_sum + pidConfig.dKd*dDifference;

	pidConfig.dSensor_previousValue = dSensorValue;

	return dOut;
}

int pid_findMaxSpeed(double dSensorValue)
{
	double dDifference = pidConfig.dSensor_previousValue - dSensorValue;
	int iHasMaxSpeed = 0;

	pidConfig.dSensor_previousValue = dSensorValue;

	if(dDifference < cdMaxEstabilizationError)
	{
		iHasMaxSpeed = 1;
		dMaxCoolerSpeed = dSensorValue;
	}

	return iHasMaxSpeed;
}

double pid_getMaxSpeed(void)
{
	return dMaxCoolerSpeed;
}

