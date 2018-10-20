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



/*                 LEFT MOTOR Definitions                    */
#define LEFT_MOTOR_PORT_BASE_PNT        PORTE                                   /* peripheral port base pointer */
#define LEFT_MOTOR_GPIO_BASE_PNT        PTE                                     /* peripheral gpio base pointer */

#define LEFT_MOTOR_PIN                  20U                                      /* cooler pin */
#define LEFT_MOTOR_DIR                  (GPIO_OUTPUT << LEFT_MOTOR_PIN)
#define LEFT_MOTOR_ALT_PWM              0x03u
/*                 END OF LEFT MOTOR definitions             */

/*                 RIGHT MOTOR Definitions                    */
#define RIGHT_MOTOR_PORT_BASE_PNT        PORTE                                   /* peripheral port base pointer */
#define RIGHT_MOTOR_GPIO_BASE_PNT        PTE                                     /* peripheral gpio base pointer */

#define RIGHT_MOTOR_PIN                  21U                                      /* cooler pin */
#define RIGHT_MOTOR_DIR                  (GPIO_OUTPUT << RIGHT_MOTOR_PIN)
#define RIGHT_MOTOR_ALT_PWM              0x03u
/*                 END OF RIGHT MOTOR definitions             */


/*                 TACHOMETER Definitions                    */
#define TACHOMETER_PORT_BASE_PNT    PORTE                                   /* peripheral port base pointer */
#define TACHOMETER_GPIO_BASE_PNT    PTE                                     /* peripheral gpio base pointer */

#define TACHOMETER_PIN              29U                                      /* tachometer pin */
#define TACHOMETER_DIR              (GPIO_INPUT << TACHOMETER_PIN)
#define TACHOMETER_ALT              0x04u
#define TACHOMETER_READ_MASK        0xffffu
/*                 END OF TACHOMETER definitions             */


/*                 TRACK EMITTER  SOURCE DEFINITIONS                    */
#define TRACK_EMITTER_PORT_BASE_PNT    PORTA                                   /* peripheral port base pointer */
#define TRACK_EMITTER_GPIO_BASE_PNT    PTA                                     /* peripheral gpio base pointer */

#define TRACK_EMITTER_PIN              13U                                      /* thermometer pin */
#define TRACK_EMITTER_DIR              (GPIO_OUTPUT << TRACK_EMITTER_PIN)
#define TRACK_EMITTER_ALT              0x01u
/*                 END OF VOLTAGE SENSOR DEFINITIONS             */


/*                 TRACK SENSOR 1 DEFINITIONS                    */
#define TRACK_SENSOR_1_PORT_BASE_PNT    PORTB                                   /* peripheral port base pointer */
#define TRACK_SENSOR_1_GPIO_BASE_PNT    PTB                                     /* peripheral gpio base pointer */

#define TRACK_SENSOR_1_PIN              03U                                      /* thermometer pin */
#define TRACK_SENSOR_1_DIR              (GPIO_INPUT << TRACK_SENSOR_1_PIN)
#define TRACK_SENSOR_1_ALT              0x00u
/*                 END OF TRACK SENSOR 1 DEFINITIONS             */

/*                 TRACK SENSOR 2 DEFINITIONS                    */
#define TRACK_SENSOR_2_PORT_BASE_PNT    PORTB                                   /* peripheral port base pointer */
#define TRACK_SENSOR_2_GPIO_BASE_PNT    PTB                                     /* peripheral gpio base pointer */

#define TRACK_SENSOR_2_PIN              02U                                      /* thermometer pin */
#define TRACK_SENSOR_2_DIR              (GPIO_INPUT << TRACK_SENSOR_2_PIN)
#define TRACK_SENSOR_2_ALT              0x00u
/*                 END OF TRACK SENSOR 2 DEFINITIONS             */

/*                 TRACK SENSOR 3 DEFINITIONS                    */
#define TRACK_SENSOR_3_PORT_BASE_PNT    PORTC                                   /* peripheral port base pointer */
#define TRACK_SENSOR_3_GPIO_BASE_PNT    PTC                                     /* peripheral gpio base pointer */

#define TRACK_SENSOR_3_PIN              02U                                      /* thermometer pin */
#define TRACK_SENSOR_3_DIR              (GPIO_INPUT << TRACK_SENSOR_3_PIN)
#define TRACK_SENSOR_3_ALT              0x00u
/*                 END OF TRACK SENSOR 3 DEFINITIONS             */

/*                 TRACK SENSOR 4 DEFINITIONS                    */
#define TRACK_SENSOR_4_PORT_BASE_PNT    PORTB                                   /* peripheral port base pointer */
#define TRACK_SENSOR_4_GPIO_BASE_PNT    PTB                                     /* peripheral gpio base pointer */

#define TRACK_SENSOR_4_PIN              01U                                      /* thermometer pin */
#define TRACK_SENSOR_4_DIR              (GPIO_INPUT << TRACK_SENSOR_4_PIN)
#define TRACK_SENSOR_4_ALT              0x00u
/*                 END OF TRACK SENSOR 4 DEFINITIONS             */

/*                 TRACK SENSOR 5 DEFINITIONS                    */
#define TRACK_SENSOR_5_PORT_BASE_PNT    PORTB                                   /* peripheral port base pointer */
#define TRACK_SENSOR_5_GPIO_BASE_PNT    PTB                                     /* peripheral gpio base pointer */

#define TRACK_SENSOR_5_PIN              00U                                      /* thermometer pin */
#define TRACK_SENSOR_5_DIR              (GPIO_INPUT << TRACK_SENSOR_5_PIN)
#define TRACK_SENSOR_5_ALT              0x00u
/*                 END OF TRACK SENSOR 5 DEFINITIONS             */











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
