/* ***************************************************************** */
/* File name:        pid.h                                           */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the PID                 */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    21jun2018                                       */
/* Revision date:    28jun2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_CONTROLLER_PID_H_
#define SOURCES_CONTROLLER_PID_H_


typedef struct pid_data_type {
	double dKp, dKd, dKi;
	double dSensor_previousValue;
	double dError_sum;
} pid_data_type;


/* ************************************************ */
/* Method name:        pid_init                     */
/* Method description: Initialize the PID controller*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(void);


/* ************************************************** */
/* Method name:        pid_setKp                      */
/* Method description: Set a new value for the PID    */
/*                     proportional constant          */
/* Input params:       dKp: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKp(double dKp);


/* ************************************************** */
/* Method name:        pid_getKp                      */
/* Method description: Get the value from the PID     */
/*                     proportional constant          */
/* Input params:       n/a                            */
/* Output params:      double: Value                  */
double pid_getKp(void);


/* ************************************************** */
/* Method name:        pid_setKi                      */
/* Method description: Set a new value for the PID    */
/*                     integrative constant           */
/* Input params:       dKi: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKi(double dKi);


/* ************************************************** */
/* Method name:        pid_getKi                      */
/* Method description: Get the value from the PID     */
/*                     integrative constant           */
/* Input params:       n/a                            */
/* Output params:      double: Value                  */
/* ************************************************** */
double pid_getKi(void);


/* ************************************************** */
/* Method name:        pid_setKd                      */
/* Method description: Set a new value for the PID    */
/*                     derivative constant            */
/* Input params:       dKd: New value                 */
/* Output params:      n/a                            */
/* ************************************************** */
void pid_setKd(double dKd);


/* ************************************************** */
/* Method name:        pid_getKd                      */
/* Method description: Get the value from the PID     */
/*                     derivative constant            */
/* Input params:       n/a                            */
/* Output params:      double: Value                  */
/* ************************************************** */
double pid_getKd(void);


/* ************************************************** */
/* Method name:        pid_updateData                 */
/* Method description: Update the control output      */
/*                     using the reference and sensor */
/*                     value                          */
/* Input params:       dSensorValue: Value read from  */
/*                     the sensor                     */
/*                     dReferenceValue: Value used as */
/*                     control reference              */
/* Output params:      double: New Control effort     */
/* ************************************************** */
double pid_updateData(double dSensorValue, double dReferenceValue);


/* ************************************************** */
/* Method name:        pid_findMaxSpeed               */
/* Method description: Discovers the max capable speed*/
/* Input params:       dSensorValue: Value read from  */
/*                     the sensor                     */
/* Output params:      int: 1 if the max speed was    */
/*                     achieved, 0 if not             */
/* ************************************************** */
int pid_findMaxSpeed(double dSensorValue);


/* ************************************************** */
/* Method name:        pid_getMaxSpeed                */
/* Method description: Get the max possible speed     */
/* Input params:       n/a                            */
/* Output params:      double: Max speed              */
/* ************************************************** */
double pid_getMaxSpeed(void);

#endif /* SOURCES_CONTROLLER_PID_H_ */
