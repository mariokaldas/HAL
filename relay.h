/* Relay driver
 * relay.h
 *
 *  Created on: Nov 29, 2023
 *      Author: mario kaldas
 */

#ifndef RELAY_H_
#define RELAY_H_

#include "MCAL_Atmega32/std_types.h"

/***************************************************************************
 *                              Relays definition
 *************************************************************************** */

#define RELAYS_PORT PORTB_ID

#define RELAY1 0
#define RELAY2 1


/***************************************************************************
 *                            Functions declaration
 *************************************************************************** */

void RELAY_init(uint8 relay_num);
void RELAY_on(uint8 relay_num);
void RELAY_off(uint8 relay_num);

#endif /* RELAY_H_ */
