/* keypad driver
 * keypad.h
 *
 *  Created on: Sep 25, 2023
 *      Author: mario kaldas
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "MCAL_Atmega32/std_types.h"

/****************************************************************************
 *                               Definitions
 * *************************************************************************/

#define KEYPAD_NUM_OF_COLS  4
#define KEYPAD_NUM_OF_ROWS  4

#define KEYPAD_COL_PORT	PORTD_ID
#define KEYPAD_FIRST_COL_PIN 2

#define KEYPAD_ROW_PORT PORTB_ID
#define KEYPAD_FIRST_ROW_PIN 4

#define KEYPAD_PRESSED LOW
#define KEYPAD_RELEASED HIGH

/**************************************************************************
 *                          Functions prototype
 * *************************************************************************/

uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */
