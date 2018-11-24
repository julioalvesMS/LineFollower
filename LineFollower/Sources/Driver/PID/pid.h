/* ***************************************************************** */
/* File name:        pid.h                                           */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the PID                 */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    21jun2018                                       */
/* Revision date:    28jun2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_DRIVER_PID_H_
#define SOURCES_DRIVER_PID_H_


typedef struct pid_data_type {
	double Kp, Kd, Ki;
	double PreviousValue;
	double ErrorSum;
} pid_data_type;


/* ************************************************ */
/* Method name:        pid_init                     */
/* Method description: Initialize the PID controller*/
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void pid_init(void);


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
double pid_updateData(double sensorValue, double referenceValue);


double pid_controlMotor(double sensorValue, double referenceValue);

#endif /* SOURCES_DRIVER_PID_H_ */
