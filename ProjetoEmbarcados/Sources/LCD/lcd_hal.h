/* ***************************************************************** */
/* File name:        lcd_hal.h                                       */
/* File description: Header file containing the functions/methods    */
/*                   interfaces for handling the LCD hardware from   */
/*                   the hardware kit                                */
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#ifndef SOURCES_LCD_HAL_H_
#define SOURCES_LCD_HAL_H_

/* lcd basic commands list */
#define CMD_INIT_LCD        0x0F
#define CMD_CLEAR           0x01
#define CMD_NO_CURSOR       0x0C
#define CMD_CURSOR2R        0x06 /* cursor to right */
#define CMD_NO_CUR_NO_BLINK 0x38 /* no cursor, no blink */


/* ************************************************ */
/* Method name:        lcd_initLcd                  */
/* Method description: Initialize the LCD function  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_initLcd(void);


/* ************************************************ */
/* Method name:        lcd_writeData                */
/* Method description: Write data to be displayed   */
/* Input params:       ucData => char to be written */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeData(unsigned char ucData);


/* ************************************************ */
/* Method name:        lcd_sendCommand              */
/* Method description: Write command to LCD         */
/* Input params:       ucCmd=>command to be executed*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd);


/* ************************************************ */
/* Method name:        lcd_WriteString              */
/* Method description: Write string to be displayed */
/* Input params:       cpBuffer => string to be     */
/*                     written in LCD               */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeString(const char *cpBuffer);


/* ************************************************ */
/* Method name:        lcd_setCursor                */
/* Method description: Set cursor line and column   */
/* Input params:       ucLine = LINE0..LINE1        */
/*                     ucColumn =COLUMN0..MAX_COLUMN*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_setCursor(unsigned char ucLine, unsigned char ucColumn);


/* ************************************************ */
/* Method name:        lcd_writeText                */
/* Method description: Write a text in LCD both     */
/*                     lines from the LCD           */
/* Input params:       cpLine1 => string to be      */
/*                       written in line 1 from LCD */
/*                     cpLine2 => string to be      */
/*                       written in line 2 from LCD */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeText(const char *cpLine1, const char *cpLine2);


/* ************************************************ */
/* Method name:        lcd_writeNumberLine          */
/* Method description: Write a number in a line to  */
/*                     be sent to the LCD           */
/* Input params:       cpLine => line string        */
/*                     ucPointer => Number start    */
/*                       position.                  */
/*                     iValue => Number value to be */
/*                       written.                   */
/*                     cDigits => Number of digits  */
/*                       that should be used to     */
/*                       write the number           */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeNumberLine(char *cpLine, unsigned char ucPointer, int iValue, char cDigits);

void lcd_writeDoubleLine(char *cpLine, unsigned char ucPointer, double dValue, char cUnityDigits, char cDecimalDigits);

#endif /* SOURCES_LCD_HAL_H_ */
