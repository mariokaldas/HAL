/* Infra-red sensor driver
 * IR.h
 *
 *  Created on: Nov 29, 2023
 *      Author: mario
 */

#ifndef IR_H_
#define IR_H_

#include "MCAL_Atmega32/gpio.h"
#include "MCAL_Atmega32/std_types.h"

/***************************************************************************
 *                                Definitions
 *************************************************************************** */

#define OBJECT_DETECTED    1
#define NO_OBJECT_DETECTED 0

#define IR_PORT PORTA_ID


/***************************************************************************
 *                              IR's definition
 *************************************************************************** */

#define IR1 0
#define IR2 1


/***************************************************************************
 *                           Functions declaration
 *************************************************************************** */

void IR_init(uint8 IR_num);
uint8 IR_getReading(uint8 IR_num);

#endif /* IR_H_ */
