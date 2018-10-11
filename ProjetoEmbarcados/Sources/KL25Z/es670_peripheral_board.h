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
