/* ***************************************************************** */
/* File name:        pid.c                                           */
/* File description: This file has a couple of useful functions to   */
/*                   control the implemented PID controller          */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    21jun2018                                       */
/* Revision date:    28jun2018                                       */
/* ***************************************************************** */

#include "pid.h"

pid_data_type pidConfig;

const double cdMaxEstabilizationError = 1;

int dMaxCoolerSpeed = 0.0;

/* ************************************************ */
/* Method name:        pid_init                     */
/* Method description: Initialize the PID controller*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(void)
{
	pidConfig.dKp = 0.0;
	pidConfig.dKd = 0.0;
	pidConfig.dKi = 0.0;
	pidConfig.dSensor_previousValue = 0;
	pidConfig.dError_sum = 0.0;
}


/* ************************************************** */
/* Method name:        pid_setKp                      */
/* Method description: Set a new value for the PID    */
/*                     proportional constant          */
/* Input params:       dKp: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKp(double dKp)
{
	pidConfig.dKp = dKp;
}


/* ************************************************** */
/* Method name:        pid_getKp                      */
/* Method description: Get the value from the PID     */
/*                     proportional constant          */
/* Input params:       n/a                            */
/* Output params:      double: Value                  */
/* ************************************************** */
double pid_getKp(void)
{
	return pidConfig.dKp;
}


/* ************************************************** */
/* Method name:        pid_setKi                      */
/* Method description: Set a new value for the PID    */
/*                     integrative constant           */
/* Input params:       dKi: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKi(double dKi)
{
	pidConfig.dKi = dKi;
}


/* ************************************************** */
/* Method name:        pid_getKi                      */
/* Method description: Get the value from the PID     */
/*                     integrative constant           */
/* Input params:       n/a                            */
/* Output params:      double: Value                  */
/* ************************************************** */
double pid_getKi(void)
{
	return pidConfig.dKi;
}


/* ************************************************** */
/* Method name:        pid_setKd                      */
/* Method description: Set a new value for the PID    */
/*                     derivative constant            */
/* Input params:       dKd: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKd(double dKd)
{
	pidConfig.dKd = dKd;
}


/* ************************************************** */
/* Method name:        pid_getKd                      */
/* Method description: Get the value from the PID     */
/*                     derivative constant            */
/* Input params:       n/a                            */
/* Output params:      double: Value                  */
/* ************************************************** */
double pid_getKd(void)
{
	return pidConfig.dKd;
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
double pid_updateData(double dSensorValue, double dReferenceValue)
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


/* ************************************************** */
/* Method name:        pid_findMaxSpeed               */
/* Method description: Discovers the max capable speed*/
/* Input params:       dSensorValue: Value read from  */
/*                     the sensor                     */
/* Output params:      int: 1 if the max speed was    */
/*                     achieved, 0 if not             */
int pid_findMaxSpeed(double dSensorValue)
{
	double dDifference = pidConfig.dSensor_previousValue - dSensorValue;
	int iHasMaxSpeed = 0;

	pidConfig.dSensor_previousValue = dSensorValue;

	if(dDifference < cdMaxEstabilizationError && dSensorValue>1)
	{
		iHasMaxSpeed = 1;
		dMaxCoolerSpeed = dSensorValue;
	}

	return iHasMaxSpeed;
}


/* ************************************************** */
/* Method name:        pid_getMaxSpeed                */
/* Method description: Get the max possible speed     */
/* Input params:       n/a                            */
/* Output params:      double: Max speed              */
/* ************************************************** */
double pid_getMaxSpeed(void)
{
	return dMaxCoolerSpeed;
}

