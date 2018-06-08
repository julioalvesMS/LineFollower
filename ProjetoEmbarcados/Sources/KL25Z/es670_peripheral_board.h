/* ***************************************************************** */
/* File name:        es670_peripheral_board.h                        */
/* File description: Header file containing the peripherals mapping  */
/*                     of the peripheral board for the ES670 hardware*/
/* Author name:      dloubach julioalvesMS IagoAF                    */
/* Creation date:    16out2015                                       */
/* Revision date:    05abr2018                                       */
/* ***************************************************************** */

#ifndef SOURCES_ES670_PERIPHERAL_BOARD_H_
#define SOURCES_ES670_PERIPHERAL_BOARD_H_

/* system includes */
#include <MKL25Z4.h>

/*                 General uC definitions                 */

/* Clock gate control */
#define  CGC_CLOCK_DISABLED         0x00U
#define  CGC_CLOCK_ENABLED          0x01U

/* GPIO input / output */
#define GPIO_INPUT                  0x00U
#define GPIO_OUTPUT                 0x01U


/*                 END OF General uC definitions         */


/*                 BUZZER Definitions                    */
#define BUZZER_PORT_BASE_PNT        PORTD                                   /* peripheral port base pointer */
#define BUZZER_GPIO_BASE_PNT        PTD                                     /* peripheral gpio base pointer */

#define BUZZER_PIN                  1U                                      /* buzzer pin */
#define BUZZER_DIR                  kGpioDigitalOutput
#define BUZZER_ALT                  0x01u
/*                 END OF BUZZER definitions             */


/*                 LED and SWITCH Definitions                    */
#define LS_PORT_BASE_PNT            PORTA                                   /* peripheral port base pointer */
#define LS_GPIO_BASE_PNT            PTA                                     /* peripheral gpio base pointer */

/* THIS PIN CONFLICTS WITH PTA1 USED AS UART0_RX IN THE OPENSDA SERIAL DEBUG PORT */
#define LS1_PIN                     1U                                      /* led/switch #1 pin */
#define LS1_DIR_OUTPUT              (GPIO_OUTPUT << LS1_PIN)
#define LS1_DIR_INPUT               (GPIO_OUTPUT << LS1_PIN)
#define LS1_ALT                     0x01u                                   /* GPIO alternative */

/* THIS PIN CONFLICTS WITH PTA2 USED AS UART0_TX IN THE OPENSDA SERIAL DEBUG PORT */
#define LS2_PIN                     2U                                      /* led/switch #2 pin */
#define LS2_DIR_OUTPUT              (GPIO_OUTPUT << LS2_PIN)
#define LS2_DIR_INPUT               (GPIO_OUTPUT << LS2_PIN)
#define LS2_ALT                     LS1_ALT

#define LS3_PIN                     4U                                      /* led/switch #3 pin */
#define LS3_DIR_OUTPUT              (GPIO_OUTPUT << LS3_PIN)
#define LS3_DIR_INPUT               (GPIO_OUTPUT << LS3_PIN)
#define LS3_ALT                     LS1_ALT

#define LS4_PIN                     5U                                      /* led/switch #4 pin */
#define LS4_DIR_OUTPUT              (GPIO_OUTPUT << LS4_PIN)
#define LS4_DIR_INPUT               (GPIO_OUTPUT << LS4_PIN)
#define LS4_ALT                     LS1_ALT

/*                 END OF LED and SWITCH definitions             */

/*                 DISPLAY 7SEG Definitions                    */
#define D7S_PORT_BASE_PNT            PORTC                                   /* peripheral port base pointer */
#define D7S_GPIO_BASE_PNT            PTC                                     /* peripheral gpio base pointer */

                               /*                SEGMENTS             */
#define D7S0_PIN                    0U                                      /* display7seg segment A */
#define D7S0_DIR                    (GPIO_OUTPUT << D7S0_PIN)
#define D7S0_ALT                    0x01u                                   /* GPIO alternative */

#define D7S1_PIN                    1U                                      /* display7seg segment B */
#define D7S1_DIR                    (GPIO_OUTPUT << D7S1_PIN)
#define D7S1_ALT                    D7S0_ALT                                   /* GPIO alternative */

#define D7S2_PIN                    2U                                      /* display7seg segment C */
#define D7S2_DIR                    (GPIO_OUTPUT << D7S2_PIN)
#define D7S2_ALT                    D7S0_ALT                                   /* GPIO alternative */

#define D7S3_PIN                    3U                                      /* display7seg segment D */
#define D7S3_DIR                    (GPIO_OUTPUT << D7S3_PIN)
#define D7S3_ALT                    D7S0_ALT                                   /* GPIO alternative */

#define D7S4_PIN                    4U                                      /* display7seg segment E */
#define D7S4_DIR                    (GPIO_OUTPUT << D7S4_PIN)
#define D7S4_ALT                    D7S0_ALT                                   /* GPIO alternative */

#define D7S5_PIN                    5U                                      /* display7seg segment F */
#define D7S5_DIR                    (GPIO_OUTPUT << D7S5_PIN)
#define D7S5_ALT                    D7S0_ALT                                   /* GPIO alternative */

#define D7S6_PIN                    6U                                      /* display7seg segment G */
#define D7S6_DIR                    (GPIO_OUTPUT << D7S6_PIN)
#define D7S6_ALT                    D7S0_ALT                                   /* GPIO alternative */

#define D7S7_PIN                    7U                                      /* display7seg segment DP */
#define D7S7_DIR                    (GPIO_OUTPUT << D7S7_PIN)
#define D7S7_ALT                    D7S0_ALT                                   /* GPIO alternative */

                                /*                DISPLAYS             */
#define D7S13_PIN                    13U                                      /* display7seg DISPLAY 1 */
#define D7S13_DIR                    (GPIO_OUTPUT << D7S13_PIN)
#define D7S13_ALT                    D7S0_ALT                                   /* GPIO alternative */

#define D7S12_PIN                    12U                                      /* display7seg DISPLAY 2 */
#define D7S12_DIR                    (GPIO_OUTPUT << D7S12_PIN)
#define D7S12_ALT                    D7S0_ALT                                   /* GPIO alternative */


#define D7S11_PIN                    11U                                      /* display7seg DISPLAY 3 */
#define D7S11_DIR                    (GPIO_OUTPUT << D7S11_PIN)
#define D7S11_ALT                    D7S0_ALT                                   /* GPIO alternative */

#define D7S10_PIN                    10U                                      /* display7seg DISPLAY 4 */
#define D7S10_DIR                    (GPIO_OUTPUT << D7S10_PIN)
#define D7S10_ALT                    D7S0_ALT                                   /* GPIO alternative */

/*                 END OF DISPLAY 7SEG definitions             */


/*                 LCD definitions                 */

/* LCD Register Selector
 * Used as register selector input
 * When (LCD_RS = LCD_RS_HIGH) => DATA register is selected
 * When (LCD_RS = LCD_RS_LOW)  => INSTRUCTION register is selected
*/
#define LCD_PORT_BASE_PNT           PORTC                                   /* peripheral port base pointer */
#define LCD_GPIO_BASE_PNT           PTC                                     /* peripheral gpio base pointer */

#define LCD_RS_PIN                  8U                                      /* register selector */
#define LCD_RS_DIR                  (GPIO_OUTPUT << LCD_RS_PIN)
#define LCD_RS_ALT                  kPortMuxAsGpio

#define LCD_ENABLE_PIN              9U                                      /* enable pin */
#define LCD_ENABLE_DIR              (GPIO_OUTPUT << LCD_ENABLE_PIN)
#define LCD_ENABLE_ALT              kPortMuxAsGpio

#define LCD_RS_HIGH                 1U
#define LCD_RS_DATA                 LCD_RS_HIGH

#define LCD_RS_LOW                  0U
#define LCD_RS_CMD                  LCD_RS_LOW

#define LCD_ENABLED                 1U
#define LCD_DISABLED                0U

#define LCD_DATA_DIR                kGpioDigitalOutput                      /* LCD data pins */
#define LCD_DATA_ALT                kPortMuxAsGpio

#define LCD_DATA_DB0_PIN            0u
#define LCD_DATA_DB1_PIN            1u
#define LCD_DATA_DB2_PIN            2u
#define LCD_DATA_DB3_PIN            3U
#define LCD_DATA_DB4_PIN            4U
#define LCD_DATA_DB5_PIN            5U
#define LCD_DATA_DB6_PIN            6U
#define LCD_DATA_DB7_PIN            7U

#define LCD_DATA_DB0_DIR            (GPIO_OUTPUT << LCD_DATA_DB0_PIN)
#define LCD_DATA_DB1_DIR            (GPIO_OUTPUT << LCD_DATA_DB1_PIN)
#define LCD_DATA_DB2_DIR            (GPIO_OUTPUT << LCD_DATA_DB2_PIN)
#define LCD_DATA_DB3_DIR            (GPIO_OUTPUT << LCD_DATA_DB3_PIN)
#define LCD_DATA_DB4_DIR            (GPIO_OUTPUT << LCD_DATA_DB4_PIN)
#define LCD_DATA_DB5_DIR            (GPIO_OUTPUT << LCD_DATA_DB5_PIN)
#define LCD_DATA_DB6_DIR            (GPIO_OUTPUT << LCD_DATA_DB6_PIN)
#define LCD_DATA_DB7_DIR            (GPIO_OUTPUT << LCD_DATA_DB7_PIN)
/*                 END OF LCD definitions                 */



/*                 COOLER Definitions                    */
#define COOLER_PORT_BASE_PNT        PORTA                                   /* peripheral port base pointer */
#define COOLER_GPIO_BASE_PNT        PTA                                     /* peripheral gpio base pointer */

#define COOLER_PIN                  13U                                      /* cooler pin */
#define COOLER_DIR                  (GPIO_OUTPUT << COOLER_PIN)
#define COOLER_ALT                  0x01u
#define COOLER_ALT_PWM              0x03u
/*                 END OF COOLER definitions             */



/*                 TACHOMETER Definitions                    */
#define TACHOMETER_PORT_BASE_PNT    PORTE                                   /* peripheral port base pointer */
#define TACHOMETER_GPIO_BASE_PNT    PTE                                     /* peripheral gpio base pointer */

#define TACHOMETER_PIN              29U                                      /* tachometer pin */
#define TACHOMETER_DIR              (GPIO_INPUT << TACHOMETER_PIN)
#define TACHOMETER_ALT              0x04u
#define TACHOMETER_READ_MASK        0xffffu
/*                 END OF TACHOMETER definitions             */



/*                 TEMPERATURE SENSOR DIODE DEFINITIONS                    */
#define THERMOMETER_PORT_BASE_PNT    PORTE                                   /* peripheral port base pointer */
#define THERMOMETER_GPIO_BASE_PNT    PTE                                     /* peripheral gpio base pointer */

#define THERMOMETER_PIN              21U                                      /* thermometer pin */
#define THERMOMETER_DIR              (GPIO_INPUT << TERMOMETER_PIN)
#define THERMOMETER_ALT              0x00u
/*                 END OF TEMPERATURE SENSOR DIODE DEFINITIONS             */



/*                 VOLTAGE SENSOR DEFINITIONS                    */
#define VOLTMETER_PORT_BASE_PNT    PORTE                                   /* peripheral port base pointer */
#define VOLTMETER_GPIO_BASE_PNT    PTE                                     /* peripheral gpio base pointer */

#define VOLTMETER_PIN              20U                                      /* thermometer pin */
#define VOLTMETER_DIR              (GPIO_INPUT << VOLTMETER_PIN)
#define VOLTMETER_ALT              0x00u
/*                 END OF VOLTAGE SENSOR DEFINITIONS             */



#endif /* SOURCES_ES670_PERIPHERAL_BOARD_H_ */
