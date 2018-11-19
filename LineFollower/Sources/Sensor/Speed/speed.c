/*
 * track.c
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */

#include "Domain/tachometer_entity.h"
#include "Tachometer/tachometer_hal.h"
#include "speed.h"

void speed_initSensor(void)
{
	tachometer_init();
}

void speed_readSensor(double motorSpeed[])
{
	motorSpeed[0] = tachometer_readSensor(TACHOMETER_LEFT);
	motorSpeed[1] = tachometer_readSensor(TACHOMETER_RIGHT);
}
