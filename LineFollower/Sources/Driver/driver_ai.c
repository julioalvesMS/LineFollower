/*
 * driver_ai.c
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */


#include "Domain/driver_entity.h"
#include "Domain/motor_entity.h"
#include "PID/pid.h"
#include "driver_ai.h"

static const int trackBias[5] = {
		-15,
		-12,
		  0,
		 12,
		 15
};

static const int baseSpeed = 50;

void driver_init(void)
{
	pid_init();
}

driver_out_entity driver_run(driver_in_entity inputData)
{

	double speedCorrection = 0, controlDiff;
	int activeSensors = 0;
	int i = 0;
	driver_out_entity driverOut;

	for(i=0;i<5;i++){
		activeSensors += inputData.TrackState[i];
	}

	for(i=0;i<5;i++){
		speedCorrection += trackBias[i]*inputData.TrackState[i];
	}

	if (activeSensors!=0)
	{
		controlDiff = pid_updateData(-speedCorrection/activeSensors, 0);

		//controlDiff = speedCorrection/activeSensors;

		driverOut.MotorSpeed[0] = baseSpeed + controlDiff;
		driverOut.MotorSpeed[1] = baseSpeed - controlDiff;
	}
	else
	{
		driverOut.MotorSpeed[0] = 0;
		driverOut.MotorSpeed[1] = 0;
	}

	if(driverOut.MotorSpeed[0] < 0) driverOut.MotorSpeed[0] = 0;
	if(driverOut.MotorSpeed[0] >  100) driverOut.MotorSpeed[0] =  100;

	if(driverOut.MotorSpeed[1] < 0) driverOut.MotorSpeed[1] = 0;
	if(driverOut.MotorSpeed[1] >  100) driverOut.MotorSpeed[1] =  100;

	return driverOut;
}
