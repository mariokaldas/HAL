/* Infra-red sensor driver
 * IR.c
 *
 *  Created on: Nov 29, 2023
 *      Author: mario kaldas
 */

#include"limitSwitch.h"

#include "MCAL_Atmega32/gpio.h"

/***************************************************************************
 *                          Functions definition
 *************************************************************************** */
void LS_init(uint8 LS_num){

	GPIO_setupPinDirection(LS_PORT,LS_num,PIN_INPUT);
}

uint8 LS_getReading(uint8 LS_num){

	return GPIO_readPin(LS_PORT,LS_num);
}
