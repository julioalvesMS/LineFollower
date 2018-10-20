/*
 * driver_ai.c
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */


#include "Domain\driver_entity.h"
#include "Domain\motor_entity.h"
#include "PID\pid.h"
#include "driver_ai.h"

void driver_init(void)
{
	pid_init();
}

driver_out_entity driver_run(driver_in_entity inputData)
{
	driver_out_entity driverOut;

	driverOut.MotorSpeed[0] = pid_controlMotor(MOTOR_LEFT, inputData.SpeedSensor[0], 0);
	driverOut.MotorSpeed[1] = pid_controlMotor(MOTOR_RIGHT, inputData.SpeedSensor[1], 0);

	driverOut.MotorSpeed[0] = inputData.DebugSpeed[0];
	driverOut.MotorSpeed[1] = inputData.DebugSpeed[1];

	return driverOut;
}
