/* DC-motor driver
 * DCmotor.h
 *
 *  Created on: Oct 13, 2023
 *      Author: mario kaldas
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include"MCAL_Atmega32/std_types.h"
/***************************************************************************
 *                             Definitions
 * *************************************************************************/
#define IN1_PORT PORTB_ID
#define IN1_PIN 4

#define IN2_PORT PORTB_ID
#define IN2_PIN 5


/*************************************************************************
 *                           Types declaration
 * ***********************************************************************/

typedef enum{
	DC_CW,DC_ACW,DC_MOTORSTOP
}DCmotor_state;

/************************************************************************
 *                          Functions prototype
 * ***********************************************************************/

void DCmotor_init(void);
void DCmotor_rotate(DCmotor_state state);

#endif /* DCMOTOR_H_ */
