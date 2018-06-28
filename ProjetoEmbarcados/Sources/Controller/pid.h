/*
 * pid_hal.h
 *
 *  Created on: 21/06/2018
 *      Author: aluno
 */

#ifndef SOURCES_CONTROLLER_PID_H_
#define SOURCES_CONTROLLER_PID_H_


typedef struct pid_data_type {
	double dKp, dKd, dKi;
	int dSensor_previousValue;
	double dError_sum;
} pid_data_type;

void pid_init(void);

void pid_setKp(double dKp);

double pid_getKp(void);

void pid_setKi(double dKi);

double pid_getKi(void);

void pid_setKd(double dKd);

double pid_getKd(void);

double pid_updateData(double dSensorValue, double dReferenceValue);

int pid_findMaxSpeed(int dSensorValue);

double pid_getMaxSpeed(void);

#endif /* SOURCES_CONTROLLER_PID_H_ */
