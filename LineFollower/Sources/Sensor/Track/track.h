/*
 * track.h
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */

#ifndef SOURCES_SENSOR_TRACK_TRACK_H_
#define SOURCES_SENSOR_TRACK_TRACK_H_


void track_initSensor(void);

void track_readSensor(int sensors[]);

void track_findTrack(driver_in_entity* driver);


#endif /* SOURCES_SENSOR_TRACK_TRACK_H_ */
