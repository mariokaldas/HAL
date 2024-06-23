/* ultrasonic driver
 * ultraSonic.h
 *
 *  Created on: Oct 15, 2023
 *      Author: mario kaldas
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "MCAL_Atmega32/std_types.h"

/*************************************************************************
 *                               Definitions
 * **********************************************************************/

#define ULTRASONIC_TRIGGER_PORT PORTB_ID
#define ULTRASONIC_TRIGGER_PIN 5

#define ULTRASONIC_ECHO_PORT PORTD_ID
#define ULTRASONIC_ECHO_PIN 6

/*************************************************************************
 *                          Function prototypes
 * **********************************************************************/

void ULTRASONIC_init(void);
void ULTRASONIC_trigger(void);
uint16 ULTRASONIC_readDistance(void);
void ULTRASONIC_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
