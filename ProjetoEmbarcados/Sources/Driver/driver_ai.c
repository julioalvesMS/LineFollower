/*
 * driver_ai.c
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */


#include "Domain/driver_entity.h"
#include "Domain/motor_entity.h"
#include "Behaviour/driver_behaviour.h"
#include "PID/pid.h"
#include "driver_ai.h"

void driver_drive(driver_in_entity inputData)
{
	driver_out_entity driverOut;

	driverOut.MotorSpeed[0] = inputData.DebugSpeed[0];
	driverOut.MotorSpeed[1] = inputData.DebugSpeed[1];

	return driverOut;
}

void driver_stop(driver_in_entity inputData)
{
	driver_out_entity driverOut;

	driverOut.MotorSpeed[0] = 0;
	driverOut.MotorSpeed[1] = 0;

	return driverOut;
}

driver_out_entity driver_run(driver_in_entity inputData)
{
	driver_out_entity driverOut;
	behaviour_update(inputData);

	switch (inputData.CurrentState) {
		case DRIVE:
			driverOut = driver_drive(inputData);
			break;
		default:
			driverOut = driver_stop(inputData);
			break;
	}

	/* Maintain in the driver control the actual speed data */
	driverOut.SpeedSensor = &(inputData.SpeedSensor)

	return driverOut;
}
