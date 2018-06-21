/* ***************************************************************** */
/* File name:        lcd_hal.c                                       */
/* File description: File dedicated to the hardware abstraction layer*/
/*                   related to the LCD HARDWARE based on the KS006U */
/*                   controller                                      */
/* Author name:      dloubach                                        */
/* Creation date:    16out2015                                       */
/* Revision date:    25fev2016                                       */
/* ***************************************************************** */

#include "lcd_hal.h"
#include "KL25Z/es670_peripheral_board.h"
#include "Util/util.h"

/* system includes */
#include "fsl_clock_manager.h"
#include "fsl_port_hal.h"
#include "fsl_gpio_hal.h"

/* line and columns */
#define LINE0        0U
#define COLUMN0        0U

#define L0C0_BASE    0x80 /* line 0, column 0 */
#define L1C0_BASE    0xC0 /* line 1, column 0 */
#define MAX_COLUMN  15U

/* ************************************************ */
/* Method name:        lcd_initLcd                  */
/* Method description: Initialize the LCD function  */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_initLcd(void)
{
    /* pins configured as outputs */

    /* un-gate port clock*/
	SIM_SCGC5 |= SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);

    /* set pin as gpio */
	PORTC_PCR8 |= PORT_PCR_MUX(LCD_RS_ALT);
	PORTC_PCR9 |= PORT_PCR_MUX(LCD_ENABLE_ALT);
	PORTC_PCR0 |= PORT_PCR_MUX(LCD_DATA_ALT);
	PORTC_PCR1 |= PORT_PCR_MUX(LCD_DATA_ALT);
	PORTC_PCR2 |= PORT_PCR_MUX(LCD_DATA_ALT);
	PORTC_PCR3 |= PORT_PCR_MUX(LCD_DATA_ALT);
	PORTC_PCR4 |= PORT_PCR_MUX(LCD_DATA_ALT);
	PORTC_PCR5 |= PORT_PCR_MUX(LCD_DATA_ALT);
	PORTC_PCR6 |= PORT_PCR_MUX(LCD_DATA_ALT);
	PORTC_PCR7 |= PORT_PCR_MUX(LCD_DATA_ALT);

    /* set pin as digital output */
	GPIOC_PDDR |= GPIO_PDDR_PDD(LCD_DATA_DB0_DIR | LCD_DATA_DB1_DIR | LCD_DATA_DB2_DIR | LCD_DATA_DB3_DIR |
				LCD_DATA_DB4_DIR | LCD_DATA_DB5_DIR | LCD_DATA_DB6_DIR | LCD_DATA_DB7_DIR | LCD_RS_DIR | LCD_ENABLE_DIR );

    // turn-on LCD, with no cursor and no blink
    lcd_sendCommand(CMD_NO_CUR_NO_BLINK);

    // init LCD
    lcd_sendCommand(CMD_INIT_LCD);

    // clear LCD
    lcd_sendCommand(CMD_CLEAR);

    // LCD with no cursor
    lcd_sendCommand(CMD_NO_CURSOR);

    // cursor shift to right
    lcd_sendCommand(CMD_CURSOR2R);

}



/* ************************************************ */
/* Method name:        lcd_write2Lcd                */
/* Method description: Send command or data to LCD  */
/* Input params:       ucBuffer => char to be send  */
/*                     ucDataType=command LCD_RS_CMD*/
/*                     or data LCD_RS_DATA          */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_write2Lcd(unsigned char ucBuffer,  unsigned char ucDataType)
{
    /* writing data or command */
    if(LCD_RS_CMD == ucDataType)
        /* will send a command */
       /* GPIO_HAL_WritePinOutput(LCD_GPIO_BASE_PNT, LCD_RS_PIN, LCD_RS_CMD);*/
    	GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_RS_HIGH << LCD_RS_PIN);
    else
        /* will send data */
        /*GPIO_HAL_WritePinOutput(LCD_GPIO_BASE_PNT, LCD_RS_PIN, LCD_RS_DATA);*/
        GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_RS_HIGH << LCD_RS_PIN);

    /* write in the LCD bus */
    if(LCD_ENABLED == ((ucBuffer & (1u << 0u)) >> 0u))
        GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_DATA_DB0_PIN);
    else
        GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_DATA_DB0_PIN);

    if(LCD_ENABLED == ((ucBuffer & (1u << 1u)) >> 1u))
		GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_DATA_DB1_PIN);
	else
		GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_DATA_DB1_PIN);

    if(LCD_ENABLED == ((ucBuffer & (1u << 2u)) >> 2u))
		GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_DATA_DB2_PIN);
	else
		GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_DATA_DB2_PIN);

    if(LCD_ENABLED == ((ucBuffer & (1u << 3u)) >> 3u))
		GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_DATA_DB3_PIN);
	else
		GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_DATA_DB3_PIN);

    if(LCD_ENABLED == ((ucBuffer & (1u << 4u)) >> 4u))
		GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_DATA_DB4_PIN);
	else
		GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_DATA_DB4_PIN);

    if(LCD_ENABLED == ((ucBuffer & (1u << 5u)) >> 5u))
		GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_DATA_DB5_PIN);
	else
		GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_DATA_DB5_PIN);

    if(LCD_ENABLED == ((ucBuffer & (1u << 6u)) >> 6u))
		GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_DATA_DB6_PIN);
	else
		GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_DATA_DB6_PIN);

    if(LCD_ENABLED == ((ucBuffer & (1u << 7u)) >> 7u))
		GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_DATA_DB7_PIN);
	else
		GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_DATA_DB7_PIN);

    /* enable, delay, disable LCD */
    /* this generates a pulse in the enable pin */
    GPIOC_PSOR = GPIO_PSOR_PTSO(LCD_ENABLED << LCD_ENABLE_PIN);
    util_genDelay1ms();
    GPIOC_PCOR = GPIO_PCOR_PTCO(LCD_ENABLED << LCD_ENABLE_PIN);
    util_genDelay1ms();
}



/* ************************************************ */
/* Method name:        lcd_writeData                */
/* Method description: Write data to be displayed   */
/* Input params:       ucData => char to be written */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeData(unsigned char ucData)
{
    /* just a relay to send data */
    lcd_write2Lcd(ucData, LCD_RS_DATA);
}



/* ************************************************ */
/* Method name:        lcd_sendCommand              */
/* Method description: Write command to LCD         */
/* Input params:       ucCmd=>command to be executed*/
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_sendCommand(unsigned char ucCmd)
{
    /* just a relay to send command */
    lcd_write2Lcd(ucCmd, LCD_RS_CMD);
}



/* ************************************************ */
/* Method name:        lcd_setCursor                */
/* Method description: Set cursor line and column   */
/* Input params:       ucLine = LINE0..LINE1        */
/*                     ucColumn =COLUMN0..MAX_COLUMN*/
/* Output params:       n/a                         */
/* ************************************************ */
void lcd_setCursor(unsigned char ucLine, unsigned char ucColumn)
{
    char cCommand;

    if(LINE0 == ucLine)
        /* line 0 */
        cCommand = L0C0_BASE;
    else
        /* line 1 */
        cCommand = L1C0_BASE;

    /* maximum MAX_COLUMN columns */
    cCommand += (ucColumn & MAX_COLUMN);

    // send the command to set the cursor
    lcd_sendCommand(cCommand);
}



/* ************************************************ */
/* Method name:        lcd_writeString              */
/* Method description: Write string to be displayed */
/* Input params:       cpBuffer => string to be     */
/*                     written in LCD               */
/* Output params:      n/a                          */
/* ************************************************ */
void lcd_writeString(const char *cpBuffer)
{
    while(*cpBuffer)
    {
        lcd_writeData(*cpBuffer++);
    };
}



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
void lcd_writeText(const char *cpLine1,const char *cpLine2)
{
    // clear LCD
    lcd_sendCommand(CMD_CLEAR);

    // set the cursor line 0, column 1
    lcd_setCursor(0,0);

    // send string
    lcd_writeString(cpLine1);

    // set the cursor line 1, column 0
    lcd_setCursor(1,0);
    lcd_writeString(cpLine2);
}
