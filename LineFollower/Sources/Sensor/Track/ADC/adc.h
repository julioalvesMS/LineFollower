/* ***************************************************************** */
/* File name:        adc.h                                           */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the ADC from the        */
/*                   peripheral board                                */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    07jun2018                                       */
/* Revision date:    21jun2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_ADC_HAL_H_
#define SOURCES_ADC_HAL_H_


typedef enum
{
	TRACK_SENSOR_1,
	TRACK_SENSOR_2,
	TRACK_SENSOR_3,
	TRACK_SENSOR_4,
	TRACK_SENSOR_5
} input_port_type_e;


/* *************************************************** */
/* Method name:        adc_initADCModule               */
/* Method description: Init a the ADC converter device */
/* Input params:       n/a                             */
/* Output params:      n/a                             */
/* *************************************************** */
void adc_initADCModule(void);


/* ************************************************** */
/* Method name:        adc_initConvertion             */
/* Method description: init a conversion from A to D  */
/* Input params:       n/a                            */
/* Output params:      n/a                            */
/* ************************************************** */
void adc_initConvertion(char sensorId);


/* ************************************************** */
/* Method name:        adc_isAdcDone                  */
/* Method description: check if conversion is done    */
/* Input params:       n/a                            */
/* Output params:      char: 1 if Done, else 0        */
/* ************************************************** */
char adc_isAdcDone(void);


/* ************************************************** */
/* Method name:        adc_getConvertionValue         */
/* Method description: Retrieve converted value       */
/* Input params:       n/a                            */
/* Output params:      int: Result from convertion    */
/* ************************************************** */
int adc_getConvertionValue(void);


/* ************************************************** */
/* Method name:        adc_converter                  */
/* Method description: Retrieve converted value       */
/* Input params:       n/a                            */
/* Output params:      int: Result from the last      */
/*                     A to D convertion              */
/* ************************************************** */
int adc_converter(char sensorId);


/* ************************************************** */
/* Method name:        adc_converter                  */
/* Method description: Retrieve converted value       */
/* Input params:       n/a                            */
/* Output params:      int: Result from the last      */
/*                     A to D convertion              */
/* ************************************************** */
int adc_read(input_port_type_e enumSensor);

#endif /* SOURCES_ADC_HAL_H_ */
