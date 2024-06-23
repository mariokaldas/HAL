/* LCD driver
 * LCD.h
 *
 *  Created on: Sep 30, 2023
 *      Author: mario kaldas
 */

#ifndef LCD_H_
#define LCD_H_

#include "MCAL_Atmega32/std_types.h"


/*************************************************************************
 *                             Definitions
 * **********************************************************************/

#define LCD_RS_PORT PORTD_ID
#define LCD_RS_PIN 4

#define LCD_ENABLE_PORT PORTD_ID
#define LCD_ENABLE_PIN 5

#define LCD_DATA_PORT PORTC_ID

#define LCD_DATA_BIT_MODE 4

#if(LCD_DATA_BIT_MODE == 4)

#define LCD_DB4 3
#define LCD_DB5 4
#define LCD_DB6 5
#define LCD_DB7 6

#endif

#if(LCD_DATA_BIT_MODE != 8  &&  LCD_DATA_BIT_MODE != 4)

#error

#endif

/*************************************************************************
 *                           Functions prototype
 * **********************************************************************/

void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 character);
void LCD_init(void);
void LCD_displayString(uint8* str);
void LCD_moveCursor(uint8 row,uint8 col);
void LCD_displayStringRowColumn(uint8* string, uint8 row, uint8 col);
void LCD_clearScreen(void);
void LCD_intgerToString(uint32 data);

#endif /* LCD_H_ */
