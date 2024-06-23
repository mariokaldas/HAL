/*
 * sevenSegment_display.c
 *
 *  Created on: Apr 26, 2024
 *      Author: mario
 */

/*****************************************************************************************
 * 										 INCLUDES
 *****************************************************************************************/

#include"sevenSegment_display.h"
#include<util/delay.h>

/*****************************************************************************************
 * 									 FUNCTIONS DEFINITION
 *****************************************************************************************/

void SEVENSEGMENT_init(void){

	uint8 display;
#ifndef DECODER_7447
	GPIO_setupPortDirection(SEVENSEGMENT_DATA_PORT,PORT_OUTPUT);
#endif

#ifdef DECODER_7447
	GPIO_setupPinDirection(SEVENSEGMENT_DATA_PORT,SEVENSEGMENT_FIRST_DATA_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(SEVENSEGMENT_DATA_PORT,SEVENSEGMENT_FIRST_DATA_PIN+1,PIN_OUTPUT);
	GPIO_setupPinDirection(SEVENSEGMENT_DATA_PORT,SEVENSEGMENT_FIRST_DATA_PIN+2,PIN_OUTPUT);
	GPIO_setupPinDirection(SEVENSEGMENT_DATA_PORT,SEVENSEGMENT_FIRST_DATA_PIN+3,PIN_OUTPUT);
#endif

#if SEVENSEGMENT_NUMBEROF_DISPLAYS == 1

	GPIO_setupPinDirection(SEVENSEGMENT_ENABLE_PORT,SEVENSEGMENT_ENABLE_PIN,PIN_OUTPUT);

#ifdef COMMON_CATHODE
		GPIO_writePin(SEVENSEGMENT_ENABLE_PORT,SEVENSEGMENT_ENABLE_PIN,LOW); /* enabled */
#endif /* COMMON_CATHODE */
#ifdef COMMON_ANODE
		GPIO_writePin(SEVENSEGMENT_ENABLE_PORT,SEVENSEGMENT_ENABLE_PIN,HIGH); /* enabled */
#endif /* COMMON_ANODE */

#else /* more than one display (MULTIPLEXED) */

		for(display=0; display < SEVENSEGMENT_NUMBEROF_DISPLAYS ; display++){

			GPIO_setupPinDirection(SEVENSEGMENT_ENABLE_PORT,display,PIN_OUTPUT);

#ifdef COMMON_CATHODE
		GPIO_writePin(SEVENSEGMENT_ENABLE_PORT,display,HIGH);
#endif /* COMMON_CATHODE */
#ifdef COMMON_ANODE
		GPIO_writePin(SEVENSEGMENT_ENABLE_PORT,display,LOW);
#endif /* COMMON_ANODE */
		}
#endif /* number of displays */
}


#ifndef DECODER_7447

#ifdef COMMON_CATHODE

void SEVENSEGMENT_display(uint8 number){

	switch(number){

	case 0:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,G,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,LOW);
		break;

	case 1:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,C,HIGH);
		break;

	case 2:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,C,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,F,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,LOW);
		break;

	case 3:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,E,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,F,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,LOW);
		break;

	case 4:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,C,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,F,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,G,HIGH);
		break;

	case 5:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,E,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,LOW);
		break;

	case 6:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,LOW);
		break;

	case 7:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,A,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,C,HIGH);
		break;

	case 8:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,LOW);
		break;

	case 9:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,E,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,LOW);
		break;
	}
}

#endif /* COMMON_CATHODE */

#ifdef COMMON_ANODE

void SEVENSEGMENT_display(uint8 number){

	switch(number){

	case 0:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,G,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,HIGH);
		break;

	case 1:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0xFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,C,LOW);
		break;

	case 2:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,C,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,F,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,HIGH);
		break;

	case 3:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,E,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,F,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,HIGH);
		break;

	case 4:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,C,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,F,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,G,LOW);
		break;

	case 5:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,E,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,HIGH);
		break;

	case 6:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,HIGH);
		break;

	case 7:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0XFF);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,A,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,B,LOW);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,C,LOW);
		break;

	case 8:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,HIGH);
		break;

	case 9:
		GPIO_writePort(SEVENSEGMENT_DATA_PORT,0);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,E,HIGH);
		GPIO_writePin(SEVENSEGMENT_DATA_PORT,DOT,HIGH);
		break;
	}
}


#endif /* COMMON_ANODE */

#endif /* DECODER_7447 */


#ifdef DECODER_7447
void SEVENSEGMENT_display(uint8 number){

	uint8 value;

	value = (0xF0 & GPIO_readPort(SEVENSEGMENT_DATA_PORT)) | (number & 0x0F); /* xxxx0000 | 0000xxxx*/

	GPIO_writePort(SEVENSEGMENT_DATA_PORT,value);

}
#endif


void SEVENSEGMENT_displayMultiplexed(uint8 display,uint8 number){

#ifdef COMMON_CATHODE
	GPIO_writePin(SEVENSEGMENT_ENABLE_PORT,display-1,LOW);
#endif
#ifdef COMMON_ANODE
	GPIO_writePin(SEVENSEGMENT_ENABLE_PORT,display-1,HIGH);
#endif

	SEVENSEGMENT_display(number);
	_delay_ms(1);

#ifdef COMMON_CATHODE
	GPIO_writePin(SEVENSEGMENT_ENABLE_PORT,display-1,HIGH);
#endif
#ifdef COMMON_ANODE
	GPIO_writePin(SEVENSEGMENT_ENABLE_PORT,display-1,LOW);
#endif

}


