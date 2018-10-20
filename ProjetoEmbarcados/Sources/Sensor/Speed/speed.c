/*
 * track.c
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */

#include "speed.h"
#include "Tachometer\tachometer_hal.h"

input_port_type_e tachometerInputs[2] = {
		TACHOMETER_LEFT,
	    TACHOMETER_RIGHT
};

void speed_initSensor(void)
{
	tachometer_initSensor();
}

void speed_readSensor(double dMotorSpeed[])
{
	for(int i=0; i<2;i++)
	{
		dMotorSpeed[i] = tachometer_readSensor(tachometerInputs[i]);
	}
}
