/* buzzer driver
 * buzzer.c
 *
 *  Created on: Oct 26, 2023
 *      Author: mario kaldas
 */
#include"buzzer.h"

#include "MCAL_Atmega32/gpio.h"

/****************************************************************************
 *                          Functions definitions
 ****************************************************************************/

void BUZZER_init(void){

	/* Setup buzzer pin to be output pin */
	GPIO_setupPinDirection(BUZZER_PORT,BUZZER_PIN,PIN_OUTPUT);

	/* Initial value foe buzzer = zero */
	GPIO_writePin(BUZZER_PORT,BUZZER_PIN,LOW);
}

void BUZZER_on(void){

	GPIO_writePin(BUZZER_PORT,BUZZER_PIN,HIGH);
}

void BUZZER_off(void){

	GPIO_writePin(BUZZER_PORT,BUZZER_PIN,LOW);
}
