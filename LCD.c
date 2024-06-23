/* LCD driver
 * LCD.c
 *
 *  Created on: Sep 30, 2023
 *      Author: mario kaldas
 */

#include"LCD.h"
#include<util/delay.h>
#include<stdlib.h>

#include "MCAL_Atmega32/common_macros.h"
#include "MCAL_Atmega32/gpio.h"

/***************************************************************************
 *								 Definitions
 * *************************************************************************/

/* LCD commands */
#define CLEAR_SCREEN                     0x01
#define TWO_LINES_EIGHT_BITS_MODE        0x38
#define TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define TWO_LINES_FOUR_BITS_MODE   		 0x28
#define CURSOR_OFF                 		 0x0C
#define CURSOR_ON                  	 	 0x0E
#define SET_CURSOR_LOCATION        		 0x80

/***************************************************************************
 *                            Function definition
 * ***************************************************************************/


void LCD_sendCommand(uint8 command){

	GPIO_writePin(LCD_RS_PORT,LCD_RS_PIN,LOW);
	_delay_ms(1); /* 50ns      in all delays us will only work in simulation but won't in AVR due to bad hardware  */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1); /* 290-200 = 190ns */

#if(LCD_DATA_BIT_MODE == 4)

	GPIO_writePin(LCD_DATA_PORT,LCD_DB4,GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5,GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6,GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7,GET_BIT(command,7));

	_delay_ms(1); /* 100ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
	_delay_ms(1); /* 13ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1); /* 13ns */

	GPIO_writePin(LCD_DATA_PORT,LCD_DB4,GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5,GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6,GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7,GET_BIT(command,3));

	_delay_ms(1); /* 100ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
	_delay_ms(1); /* 100ns */

#elif(LCD_DATA_BIT_MODE == 8)

	GPIO_writePort(LCD_DATA_PORT,command);
	_delay_ms(1); /* 100ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
	_delay_ms(1); /* 13ns */

#endif

}//end LCD_sendCommand

void LCD_displayCharacter(uint8 character){

	GPIO_writePin(LCD_RS_PORT,LCD_RS_PIN,HIGH);
	_delay_ms(1); /* 50ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1); /* 290-200 = 190ns */

#if(LCD_DATA_BIT_MODE == 4)

	GPIO_writePin(LCD_DATA_PORT,LCD_DB4,GET_BIT(character,4));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5,GET_BIT(character,5));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6,GET_BIT(character,6));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7,GET_BIT(character,7));

	_delay_ms(1); /* 100ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
	_delay_ms(1); /* 13ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,HIGH);
	_delay_ms(1); /* 13ns */

	GPIO_writePin(LCD_DATA_PORT,LCD_DB4,GET_BIT(character,0));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5,GET_BIT(character,1));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6,GET_BIT(character,2));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7,GET_BIT(character,3));

	_delay_ms(1); /* 100ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
	_delay_ms(1); /* 13ns */

#elif(LCD_DATA_BIT_MODE == 8)

	GPIO_writePort(LCD_DATA_PORT,character);
	_delay_ms(1); /* 100ns */
	GPIO_writePin(LCD_ENABLE_PORT,LCD_ENABLE_PIN,LOW);
	_delay_ms(1); /* 13ns */

#endif

}//end LCD_displayCharacter

void LCD_init(void){

	GPIO_setupPinDirection(LCD_RS_PORT,LCD_RS_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_ENABLE_PORT,LCD_ENABLE_PIN,PIN_OUTPUT);
	_delay_ms(20); /* due to LCD hardware booting */

#if(LCD_DATA_BIT_MODE == 4)

	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB4,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB5,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB6,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB7,PIN_OUTPUT);

	LCD_sendCommand(TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(TWO_LINES_FOUR_BITS_MODE_INIT2);
	LCD_sendCommand(TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BIT_MODE == 8)

	GPIO_setupPortDirection(LCD_DATA_PORT,PORT_OUTPUT);
	LCD_sendCommand(TWO_LINES_EIGHT_BITS_MODE); /* 2lines + 8-bits */

#endif
	LCD_sendCommand(CURSOR_OFF); /* cursor off */
	LCD_sendCommand(CLEAR_SCREEN); /* clear screen */

}//end LCD_init

void LCD_displayString(uint8 * str){
	int i;
	for(i=0; str[i] != '\0' ;i++){
		LCD_displayCharacter(str[i]);
	}//end for

}//end LCD_displayString


/*
 * Explanation :
 * 0x80 is the command for moving cursor 1000 0000  ( no address this far )
 * the missing parameters is the position of column and base of row
 * first row : 00	second row : 40		third row : 10	fourth row : 50
 * and position of column from 0 to F
 * */
void LCD_moveCursor(uint8 row,uint8 col){

	switch(row){

	case 1:
		return LCD_sendCommand(0x80 + col);
	case 2:
		return LCD_sendCommand(0x80 + 0x40 + col);
	case 3:
		return LCD_sendCommand(0x80 + 0x10 + col);
	case 4:
		return LCD_sendCommand(0x80 + 0x50 + col);
	default:
		return LCD_sendCommand(0x80);
	}//end switch

}//end LCD_moveCursor

void LCD_displayStringRowColumn(uint8* string, uint8 row, uint8 col){

	LCD_moveCursor(row,col);
	LCD_displayString(string);

}//end LCD_displayStringRowColumn

void LCD_clearScreen(void){

	LCD_sendCommand(CLEAR_SCREEN);

}//end LCD_clearScreen

void LCD_intgerToString(uint32 data){

	uint8 buff[16]; /* String to hold the ASCII result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* Display the string */

}//end LCD_intgerToString
