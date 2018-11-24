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

static const int baseSpeed = 40;
static const int lapCondition = 20;
static const int lapsGoal = 2;

void driver_init(void)
{
	pid_init();
}

void driver_stopCar(driver_out_entity* driverOut)
{
	driverOut->MotorSpeed[0] = 0;
	driverOut->MotorSpeed[1] = 0;
}

void driver_limitPower(driver_out_entity* driverOut){

	if(driverOut->MotorSpeed[0] < 0) driverOut->MotorSpeed[0] = 0;
	if(driverOut->MotorSpeed[0] >  100) driverOut->MotorSpeed[0] =  100;

	if(driverOut->MotorSpeed[1] < 0) driverOut->MotorSpeed[1] = 0;
	if(driverOut->MotorSpeed[1] >  100) driverOut->MotorSpeed[1] =  100;
}

void driver_control(driver_in_entity inputData, driver_out_entity* driverOut, int activeSensors)
{
	int i;
	double speedCorrection = 0, controlDiff;

	for(i=0;i<5;i++)
		speedCorrection += trackBias[i]*inputData.TrackState[i];

	if (activeSensors!=0)
	{
		controlDiff = pid_updateData(-speedCorrection/activeSensors, 0);

		//controlDiff = speedCorrection/activeSensors;

		driverOut->MotorSpeed[0] = baseSpeed + controlDiff;
		driverOut->MotorSpeed[1] = baseSpeed - controlDiff;
	}
	else
	{
		driver_stopCar(driverOut);
	}
}


int driver_countLap(int activeSensors)
{
	static int lapConditionCount = 0;
	static int lapCount = 0;

	if (activeSensors == 5)
		lapConditionCount +=1;
	else
		lapConditionCount = 0;

	if (lapConditionCount >= lapCondition && activeSensors != 5)
		lapCount += 1;

	return lapCount;
}

driver_out_entity driver_run(driver_in_entity inputData)
{
	int activeSensors = 0;
	int i = 0;
	int lapsDone;

	driver_out_entity driverOut;

	for(i=0;i<5;i++){
		activeSensors += inputData.TrackState[i];
	}

	lapsDone = driver_countLap(activeSensors);


	if (lapsDone < lapsGoal)
	{
		driver_control(inputData, &driverOut, activeSensors);

		driver_limitPower(&driverOut);
	}
	else
	{
		driver_stopCar(&driverOut);
	}


	return driverOut;
}
