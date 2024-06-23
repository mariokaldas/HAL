/*  limit switch driver
 * limitSwitch.h
 *
 *  Created on: Nov 29, 2023
 *      Author: mario
 */

#ifndef IR_H_
#define IR_H_

#include "MCAL_Atmega32/std_types.h"

/***************************************************************************
 *                                Definitions
 *************************************************************************** */

#define OBJECT_DETECTED    1
#define NO_OBJECT_DETECTED 0

#define LS_PORT PORTA_ID


/***************************************************************************
 *                              IR's definition
 *************************************************************************** */

#define LS1 0
#define LS2 1


/***************************************************************************
 *                           Functions declaration
 *************************************************************************** */

void LS_init(uint8 LS_num);
uint8 LS_getReading(uint8 LS_num);

#endif /* IR_H_ */
