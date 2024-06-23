/* DC-motor driver
 * DCmotor.c
 *
 *  Created on: Oct 13, 2023
 *      Author: mario kaldas
 */

#include"DCmotor.h"
#include"MCAL_Atmega32/gpio.h"

/**********************************************************************
 *                           Function definition
 **********************************************************************/

void DCmotor_init(void){

	/* Setup the two pins of motor to output pins */
	GPIO_setupPinDirection(IN1_PORT,IN1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(IN2_PORT,IN2_PIN,PIN_OUTPUT);

	/* Stop motor at beginning */
	GPIO_writePin(IN1_PORT,IN1_PIN,LOW);
	GPIO_writePin(IN2_PORT,IN2_PIN,LOW);
}

void DCmotor_rotate(DCmotor_state state){

	switch(state){
	case DC_CW:

		GPIO_writePin(IN1_PORT,IN1_PIN,HIGH);
		GPIO_writePin(IN2_PORT,IN2_PIN,LOW);
		break;
	case DC_ACW:
		GPIO_writePin(IN1_PORT,IN1_PIN,LOW);
		GPIO_writePin(IN2_PORT,IN2_PIN,HIGH);
		break;
	case DC_MOTORSTOP:
		GPIO_writePin(IN1_PORT,IN1_PIN,LOW);
		GPIO_writePin(IN2_PORT,IN2_PIN,LOW);
		break;
	}
}
