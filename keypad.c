/*
 * Module : Keypad driver
 *
 * File name : keypad.c
 *
 * Description : source file for keypad driver
 *
 * Author: mario kaldas
 */

#include"keypad.h"
#include<util/delay.h>
#include "MCAL_Atmega32/gpio.h"

#define STANDARD_KEYPAD

/*****************************************************************************
 *                            Function prototype (private)
 * ****************************************************************************/


#if(KEYPAD_NUM_OF_COLS == 3)

static uint8 KEYPAD_4x3_adjustKey(uint8 num);

#elif(KEYPAD_NUM_OF_COLS == 4)

#ifndef STANDARD_KEYPAD
static uint8 KEYPAD_rev4x4_adjustKey(uint8 num);
#endif

#ifdef STANDARD_KEYPAD
static uint8 KEYPAD_4x4_adjustKey(uint8 num);
#endif

#endif


/***************************************************************************
 *                            Function definition
 * ***************************************************************************/

uint8 KEYPAD_getPressedKey(void){

	uint8 row,col;

	GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_FIRST_ROW_PIN,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_FIRST_ROW_PIN+1,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_FIRST_ROW_PIN+2,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_FIRST_ROW_PIN+3,PIN_INPUT);

	GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_FIRST_COL_PIN,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_FIRST_COL_PIN+1,PIN_INPUT);
	GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_FIRST_COL_PIN+2,PIN_INPUT);
#if(KEYPAD_NUM_OF_COLS == 4)
	GPIO_setupPinDirection(KEYPAD_COL_PORT,KEYPAD_FIRST_COL_PIN+3,PIN_INPUT);
#endif

	while(1){

		for(row=0;row<KEYPAD_NUM_OF_ROWS;row++){

			GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_FIRST_ROW_PIN+row,PIN_OUTPUT);

			GPIO_writePin(KEYPAD_ROW_PORT,KEYPAD_FIRST_ROW_PIN+row,KEYPAD_PRESSED);

			for(col=0;col<KEYPAD_NUM_OF_COLS;col++){

				if(GPIO_readPin(KEYPAD_COL_PORT,KEYPAD_FIRST_COL_PIN+col) == KEYPAD_PRESSED){

#if(KEYPAD_NUM_OF_COLS == 3)
					return KEYPAD_4x3_adjustKey((row*KEYPAD_NUM_OF_COLS)+col+1);
#elif(KEYPAD_NUM_OF_COLS == 4)

				#ifdef STANDARD_KEYPAD
					return (KEYPAD_4x4_adjustKey((row*KEYPAD_NUM_OF_COLS)+col+1));
				#endif


				#ifndef STANDARD_KEYPAD
					return (KEYPAD_rev4x4_adjustKey((row*KEYPAD_NUM_OF_COLS)+col+1));
				#endif

#endif
				}
			}//end inner for

			GPIO_setupPinDirection(KEYPAD_ROW_PORT,KEYPAD_FIRST_ROW_PIN+row,PIN_INPUT);
			_delay_ms(5);
		}//end outer for
	}//end while
}



#if(KEYPAD_NUM_OF_COLS == 3)

static uint8 KEYPAD_4x3_adjustKey(uint8 num){

	switch(num){
	case 10:
		return '*';
	case 11:
		return 0;
	case 12:
		return '#';
	default :
		return num;
	}//end switch
}//end 4x3


#elif(KEYPAD_NUM_OF_COLS == 4)

#ifndef STANDARD_KEYPAD
static uint8 KEYPAD_rev4x4_adjustKey(uint8 num){

	switch(num){
	case 1:
		return 7;
	case 2:
		return 8;
	case 3:
		return 9;
	case 4:
		return '/';
	case 5:
		return 4;
	case 6:
		return 5;
	case 7:
		return 6;
	case 8:
		return 'x';
	case 9:
		return 1;
	case 10:
		return 2;
	case 11:
		return 3;
	case 12:
		return '-';
	case 13:
		return 0;
	case 14:
		return 0;
	case 15:
		return '=';
	case 16:
		return '+';

	default :
		return num;
	}//end switch
}//end rev4x4
#endif /* STANDARD */


#ifdef STANDARD_KEYPAD
static uint8 KEYPAD_4x4_adjustKey(uint8 num){

	switch(num){
	case 4:
		return 'A';
	case 5:
		return 4;
	case 6:
		return 5;
	case 7:
		return 6;
	case 8:
		return 'B';
	case 9:
		return 7;
	case 10:
		return 8;
	case 11:
		return 9;
	case 12:
		return 'C';
	case 13:
		return '*';
	case 14:
		return 0;
	case 15:
		return '#';
	case 16:
		return 'D';
	default:
		return num;
	}//end switch
}//end 4x4
#endif /* STANDARD */


#endif
 /* STANDARD */
