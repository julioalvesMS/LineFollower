/*
 * emitter_hal.h
 *
 *  Created on: 19/10/2018
 *      Author: aluno
 */

#ifndef SOURCES_SENSOR_TRACK_EMITTER_EMITTER_HAL_H_
#define SOURCES_SENSOR_TRACK_EMITTER_EMITTER_HAL_H_


/* ************************************************ */
/* Method name:        cooler_initCooler            */
/* Method description: Initialize the board cooler. */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void emitter_init(void);


/* ***************************************************** */
/* Method name:        cooler_startCooler                */
/* Method description: Start the board cooler.           */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void emitter_turnOn(void);


/* ***************************************************** */
/* Method name:        cooler_stopCooler                 */
/* Method description: Stop the board cooler.            */
/* Input params:       n/a                               */
/* Output params:      n/a                               */
/* ***************************************************** */
void emitter_turnOff(void);


#endif /* SOURCES_SENSOR_TRACK_EMITTER_EMITTER_HAL_H_ */
