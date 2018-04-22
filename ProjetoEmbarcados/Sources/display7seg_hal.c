/* ***************************************************************** */
/* File name:        display7seg_hal.c                               */
/* File description: This file has a couple of useful functions to   */
/*                   control the four 7 segments display from the    */
/*                   peripheral board                                */
/* Author name:      julioalvesMS & IagoAF                           */
/* Creation date:    05abr2018                                       */
/* Revision date:    05abr2018                                       */
/* ***************************************************************** */

#include "display7seg_hal.h"
#include "es670_peripheral_board.h"
#include "util.h"


/* ************************************************ */
/* Method name:        display7seg_initDisplay      */
/* Method description: Initialize the displays      */
/*                     devices.                     */
/* Input params:       n/a                          */
/* Output params:      n/a                          */
/* ************************************************ */
void display7seg_initDisplay(void)
{
    /* un-gate port clock*/
    SIM_SCGC5 = SIM_SCGC5_PORTC(CGC_CLOCK_ENABLED);

    /* set pin as gpio */
    PORTC_PCR0 |= PORT_PCR_MUX(D7S0_ALT);
    PORTC_PCR1 |= PORT_PCR_MUX(D7S1_ALT);
    PORTC_PCR2 |= PORT_PCR_MUX(D7S2_ALT);
    PORTC_PCR3 |= PORT_PCR_MUX(D7S3_ALT);
    PORTC_PCR4 |= PORT_PCR_MUX(D7S4_ALT);
    PORTC_PCR5 |= PORT_PCR_MUX(D7S5_ALT);
    PORTC_PCR6 |= PORT_PCR_MUX(D7S6_ALT);
    PORTC_PCR7 |= PORT_PCR_MUX(D7S7_ALT);
    PORTC_PCR13 |= PORT_PCR_MUX(D7S13_ALT);
    PORTC_PCR12 |= PORT_PCR_MUX(D7S12_ALT);
    PORTC_PCR11 |= PORT_PCR_MUX(D7S11_ALT);
    PORTC_PCR10 |= PORT_PCR_MUX(D7S10_ALT);

    /* set pin as digital output */
	GPIOC_PDDR |= GPIO_PDDR_PDD(D7S0_DIR | D7S1_DIR | D7S2_DIR | D7S3_DIR |
			                    D7S4_DIR | D7S5_DIR | D7S6_DIR | D7S7_DIR |
								D7S13_DIR | D7S12_DIR | D7S11_DIR | D7S10_DIR);
}


/* ***************************************************** */
/* Method name:        display7seg_setDisplay            */
/* Method description: Set a HEX number and dot in a     */
/*                     specific display.                 */
/* Input params:       cDisplayChar = number {0..15}     */
/*                     cDot = ON(1) or OFF(0)            */
/*                     cDisplayID = which Display {1..4} */
/* Output params:      n/a                               */
/* ***************************************************** */
void display7seg_setDisplay(char cDisplayChar, char cDot, char cDisplayID)
{
	char vCharDecoded[8];

	/* choose a display to receive the character/dot */
	display7seg_selectDisplay(cDisplayID);
	/* decode the number to a binary for the 7segDisplay */
    display7seg_decoder(cDisplayChar, cDot, vCharDecoded);
    /* set the specific segments based on the binary vector */
    display7seg_setSegment(vCharDecoded[0], D7S0_PIN);
    display7seg_setSegment(vCharDecoded[1], D7S1_PIN);
    display7seg_setSegment(vCharDecoded[2], D7S2_PIN);
    display7seg_setSegment(vCharDecoded[3], D7S3_PIN);
    display7seg_setSegment(vCharDecoded[4], D7S4_PIN);
    display7seg_setSegment(vCharDecoded[5], D7S5_PIN);
    display7seg_setSegment(vCharDecoded[6], D7S6_PIN);
    display7seg_setSegment(vCharDecoded[7], D7S7_PIN);
}


/* ***************************************************** */
/* Method name:        display7seg_setSegment            */
/* Method description: Set a segment ON or OFF           */
/* Input params:       cValue = ON(1) OFF(0)             */
/*                     cPin = segment pin out            */
/* Output params:      n/a                               */
/* ***************************************************** */
void display7seg_setSegment(char cValue,char cPin)
{
	if(cValue == 1) /* turn ON the segment */
	{
		GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << cPin) );
	}
	else  /* turn OFF the segment */
	{
		GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << cPin) );
	}
}


/* ***************************************************** */
/* Method name:        display7seg_decoder               */
/* Method description: Convert a number and the dot in a */
/*                     binary sequence.                  */
/* Input params:       cDisplayChar = number {0..15}     */
/*                     cDot = ON(1) or OFF(0)            */
/*                     vCharDecoded[] = binary vector[8] */
/* Output params:      n/a                               */
/* ***************************************************** */
void display7seg_decoder(char cDisplayChar,char cDot, char vCharDecoded[])
{
    /* If the value for the dot is not valid, turn it off */
    if(D7S_OFF != cDot && D7S_OFF != cDot)
        cDot = D7S_OFF;

	switch(cDisplayChar) /* set a binary vector based on the number(cDisplayChar) and the dot(cDot) */
    {
	    case 0:  /* 0 */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_OFF;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 1:  /* 1 */
	    	vCharDecoded[0] = D7S_OFF;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_OFF;
	    	vCharDecoded[4] = D7S_OFF;
	    	vCharDecoded[5] = D7S_OFF;
	    	vCharDecoded[6] = D7S_OFF;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 2:  /* 2 */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_OFF;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_OFF;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 3:  /* 3 */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_OFF;
	    	vCharDecoded[5] = D7S_OFF;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 4:  /* 4 */
	    	vCharDecoded[0] = D7S_OFF;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_OFF;
	    	vCharDecoded[4] = D7S_OFF;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 5:  /* 5 */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_OFF;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_OFF;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 6:  /* 6 */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_OFF;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 7:  /* 7 */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_OFF;
	    	vCharDecoded[4] = D7S_OFF;
	    	vCharDecoded[5] = D7S_OFF;
	    	vCharDecoded[6] = D7S_OFF;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 8:  /* 8 */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 9:  /* 9 */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_OFF;
	    	vCharDecoded[4] = D7S_OFF;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 10: /* A */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_OFF;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 11: /* B */
	    	vCharDecoded[0] = D7S_OFF;
	    	vCharDecoded[1] = D7S_OFF;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 12:  /* C */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_OFF;
	    	vCharDecoded[2] = D7S_OFF;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_OFF;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 13:  /* D */
	    	vCharDecoded[0] = D7S_OFF;
	    	vCharDecoded[1] = D7S_ON;
	    	vCharDecoded[2] = D7S_ON;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_OFF;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 14:  /* E */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_OFF;
	    	vCharDecoded[2] = D7S_OFF;
	    	vCharDecoded[3] = D7S_ON;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
	    case 15:  /* F */
	    	vCharDecoded[0] = D7S_ON;
	    	vCharDecoded[1] = D7S_OFF;
	    	vCharDecoded[2] = D7S_OFF;
	    	vCharDecoded[3] = D7S_OFF;
	    	vCharDecoded[4] = D7S_ON;
	    	vCharDecoded[5] = D7S_ON;
	    	vCharDecoded[6] = D7S_ON;
	    	vCharDecoded[7] = cDot;
	        break;
      default: /* If the value is not configured, turn off the display */
	    	vCharDecoded[0] = D7S_OFF;
	    	vCharDecoded[1] = D7S_OFF;
	    	vCharDecoded[2] = D7S_OFF;
	    	vCharDecoded[3] = D7S_OFF;
	    	vCharDecoded[4] = D7S_OFF;
	    	vCharDecoded[5] = D7S_OFF;
	    	vCharDecoded[6] = D7S_OFF;
	    	vCharDecoded[7] = cDot;
	        break;

    } /* switch(cDisplayChar) */
}


/* ***************************************************** */
/* Method name:        display7seg_selectDisplay         */
/* Method description: Enable a specific display.        */
/* Input params:       cDisplayID = which Display {1..4} */
/* Output params:      n/a                               */
/* ***************************************************** */
void display7seg_selectDisplay(char cDisplayID)
{
	switch(cDisplayID) /* enable a display to receive the character */
	{
		case 1:
			GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << D7S13_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S12_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S11_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S10_PIN) );
			break;
		case 2:
			GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << D7S12_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S13_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S11_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S10_PIN) );
			break;
		case 3:
			GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << D7S11_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S13_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S12_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S10_PIN) );
			break;
		case 4:
			GPIOC_PSOR = GPIO_PSOR_PTSO( (0x01U << D7S10_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S13_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S12_PIN) );
			GPIOC_PCOR = GPIO_PCOR_PTCO( (0x01U << D7S11_PIN) );
			break;
	} /* switch(cDisplayID) */
}


/* ****************************************************** */
/* Method name:         display7seg_showHexNumber         */
/* Method description:  Display a 2 bytes hex value using */
/*                      all four 7 segments displayes     */
/* Input params:        iValue: Value to be shown         */
/* Output params:       n/a                               */
/* ****************************************************** */
void display7seg_showHexNumber(unsigned int iValue)
{
    /* Extreme left display */
	display7seg_setDisplay(iValue%16,0,4);
	iValue = iValue/16;
	util_genDelay1ms();

    /* Middle left display */
	display7seg_setDisplay(iValue%16,0,3);
	iValue = iValue/16;
	util_genDelay1ms();

    /* Middle right display */
	display7seg_setDisplay(iValue%16,0,2);
	iValue = iValue/16;
	util_genDelay1ms();

    /* Extreme right display */
	display7seg_setDisplay(iValue%16,0,1);
	util_genDelay1ms();
}
