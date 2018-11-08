/* ***************************************************************** */
/* File name:        tachometer_hal.h                                */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the tachometer from the */
/*                   peripheral board                                */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    03mai2018                                       */
/* Revision date:    03mai2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_TACHOMETER_HAL_H_
#define SOURCES_TACHOMETER_HAL_H_



/* ************************************************ */
/* Method name:        tachometer_initSensor        */
/* Method description: Initialize the board         */
/*                     tachometer sensor.           */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void tachometer_init(void);


/* ***************************************************** */
/* Method name:        tachometer_readSensor             */
/* Method description: Read the board tachometer sensor. */
/* Input params:       dPeriodMc: ECC period             */
/* Output params:      double: Motor speed               */
/* ***************************************************** */
double tachometer_readSensor(tachometer_entity tachomter);


#endif /* SOURCES_TACHOMETER_HAL_H_ */
