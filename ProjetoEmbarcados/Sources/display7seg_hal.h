/* ***************************************************************** */
/* File name:        display7seg_hal.h                               */
/* File description: This file has a couple of useful functions to   */
/*                   control LEDs and Switches from peripheral board */
/* Author name:      julioalvesMS IagoAF                             */
/* Creation date:    05abr2018                                       */
/* Revision date:    05abr2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_DISPLAY7SEG_HAL_H_
#define SOURCES_DISPLAY7SEG_HAL_H_

#define D7S_ON 1;
#define D7S_OFF 0;


/* ************************************************ */
/* Method name:        display7seg_initDisplay      */
/* Method description: Initialize the displays      */
/*                     devices.                     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void display7seg_initDisplay(void);

/* ***************************************************** */
/* Method name:        display7seg_setDisplay            */
/* Method description: Set a HEX number and dot in a     */
/*                     specific display.                 */
/* Input params:       cDisplayChar = number {0..15}     */
/*                     cDot = ON(1) or OFF(0)            */
/*                     cDisplayID = which Display {1..4} */
/* Output params:      n/a                               */
/* ***************************************************** */
void display7seg_setDisplay(char cDisplayChar, char cDot, char cDisplayID);

/* ***************************************************** */
/* Method name:        display7seg_setSegment            */
/* Method description: Set a segment ON or OFF           */
/* Input params:       cValue = ON(1) OFF(0)             */
/*                     cPin = segment pin out            */
/* Output params:      n/a                               */
/* ***************************************************** */
void display7seg_setSegment(char cValue,char cPin);

/* ***************************************************** */
/* Method name:        display7seg_decoder               */
/* Method description: Convert a number and the dot in a */
/*                     binary sequence.                  */
/* Input params:       cDisplayChar = number {0..15}     */
/*                     cDot = ON(1) or OFF(0)            */
/*                     vCharDecoded[] = binary vector[8] */
/* Output params:      n/a                               */
/* ***************************************************** */
void display7seg_decoder(char cDisplayChar,char cDot, char vCharDecoded[]);

/* ***************************************************** */
/* Method name:        display7seg_selectDisplay         */
/* Method description: Enable a specific display.        */
/* Input params:       cDisplayID = which Display {1..4} */
/* Output params:      n/a                               */
/* ***************************************************** */
void display7seg_selectDisplay(char cDisplayID);

#endif /* SOURCES_DISPLAY7SEG_HAL_H_ */
