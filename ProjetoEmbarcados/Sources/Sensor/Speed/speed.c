/*
 * track.c
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */

#include "Domain/car_properties.h"
#include "Tachometer/tachometer_hal.h"
#include "speed.h"

input_port_type_e tachometerInputs[2] = {
	TACHOMETER_LEFT,
	TACHOMETER_RIGHT
};

void speed_initSensor(void)
{
	tachometer_initSensor();
}

double speed_calculateSpeed(double rotationFrequency)
{
	return pi*WheelDiameter*rotationFrequency;
}

void speed_readSensor(double motorSpeed[])
{
	double speed;
	for(int i=0; i<2;i++)
	{
		speed = tachometer_readSensor(tachometerInputs[i]);
		motorSpeed[i] = speed_calculateSpeed(speed);
	}
}
