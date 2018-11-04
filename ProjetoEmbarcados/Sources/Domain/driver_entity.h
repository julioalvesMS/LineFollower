/*
 * driver_entity.h
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */

#ifndef SOURCES_DOMAIN_DRIVER_ENTITY_H_
#define SOURCES_DOMAIN_DRIVER_ENTITY_H_

typedef enum
{
	START,
	STOP,
	DRIVE
} driver_state;

typedef struct driver_in_entity
{
	driver_state CurrentState;
	int TrackSensor[5];
	double SpeedSensor[2];
	double DebugSpeed[2];
} driver_in_entity;


typedef struct driver_out_entity
{
	double MotorSpeed[2];
	double* SpeedSensor;
} driver_out_entity;


#endif /* SOURCES_DOMAIN_DRIVER_ENTITY_H_ */
