/*
 * track.c
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */

#include "ADC/adc.h"
#include "Emitter/emitter_hal.h"
#include "Domain/driver_entity.h"
#include "track.h"

input_port_type_e trackInputs[5] = {
		TRACK_SENSOR_1,
		TRACK_SENSOR_2,
		TRACK_SENSOR_3,
		TRACK_SENSOR_4,
		TRACK_SENSOR_5
};

void track_initSensor(void)
{
	adc_initADCModule();
	emitter_init();
	emitter_turnOn();
}

void track_readSensor(int sensors[])
{
	for(int i=0; i<5;i++)
	{
		sensors[i] = adc_read(trackInputs[i]);
	}
}

void track_findTrack(driver_in_entity* driver)
{
	for(int i=0; i<5;i++)
	{
		if(driver->TrackSensor[i] < 40)
			driver->TrackState[i] = IN_TRACK;
		else
			driver->TrackState[i] = OFF_TRACK;
	}
}
