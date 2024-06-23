/* Relay driver
 * relay.c
 *
 *  Created on: Nov 29, 2023
 *      Author: mario kaldas
 */
#include"relay.h"

#include "MCAL_Atmega32/gpio.h"

/***************************************************************************
 *                           Functions definitions
 *************************************************************************** */

void RELAY_init(uint8 relay_num){

	GPIO_setupPinDirection(RELAYS_PORT,relay_num,PIN_OUTPUT);
}

void RELAY_on(uint8 relay_num){

	GPIO_writePin(RELAYS_PORT,relay_num,HIGH);
}

void RELAY_off(uint8 relay_num){

	GPIO_writePin(RELAYS_PORT,relay_num,LOW);
}
