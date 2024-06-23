/*
 * sevenSegment_display.h
 *
 *  Created on: Apr 26, 2024
 *      Author: mario
 */

#ifndef APP_HAL_SEVENSEGMENT_DISPLAY_H_
#define APP_HAL_SEVENSEGMENT_DISPLAY_H_

/*
 * This driver supports:
 * - 7-segments common anode and common cathode (MODIFY THE #define)
 * - 7-segments using decoder and without using it (MODIFY THE #define)
 * - single 7-segments or multiplexed 7-segments from 1 to 8
 *
 * */

/*****************************************************************************************
 * 										 INCLUDES
 *****************************************************************************************/

#include"MCAL_Atmega32/std_types.h"
#include"MCAL_Atmega32/GPIO.h"

/*****************************************************************************************
 * 										Definitions
 *****************************************************************************************/

/* please connect data pins in order (EVEN IF DECODER IS CONNECTED) */
#define SEVENSEGMENT_DATA_PORT PORTC_ID

/* used in case of using decoder */
#define SEVENSEGMENT_FIRST_DATA_PIN 0

/* how many displays you will use ? */
#define SEVENSEGMENT_NUMBEROF_DISPLAYS 2

/* in case there is more than one using multiplexed technique (connect pins in order also) */
#define SEVENSEGMENT_ENABLE_PORT PORTA_ID

/* in case you use one display only */
#define SEVENSEGMENT_ENABLE_PIN 0

#define DECODER_7447

/* please define the 7-segment type first */
#define COMMON_CATHODE

/*
 * VERY IMPORTANT WITH ETA32 KIT:
 *
 * - if you will use eta32 kit you must change the logic of CATHODE
 * because it is common cathode but it enabled with logic high
 *
 *- enable pins connected in PC6 and PC7 , so consider the display number in argument
 * display 1 >> make it 7			display 2 >> make it 8
 *
 * - add any number in the beginning of the ENUM because data pins begin with PA1 not 0
 * - you may need to increase delay in multiplexed function for clearer numbers
 *
 * */
/*****************************************************************************************
 * 									 TYPES DECLARATION
 *****************************************************************************************/

enum segment{

	A,B,C,D,E,F,G,DOT
};

/*****************************************************************************************
 * 									 FUNCTIONS PROTOTYPE
 *****************************************************************************************/
/* This function will setup 8-pins from the Port ( A -> B and DOT ) */
void SEVENSEGMENT_init(void);

#ifndef DECODER_7447
/* IMPORTANT: This function will process all 8-pins from the Port ( A -> B and DOT ) */
void SEVENSEGMENT_display(uint8 number);
#endif

#ifdef DECODER_7447
/* This function will NOT process all 8-pins from the Port just 4 */
void SEVENSEGMENT_display(uint8 number);
#endif

/* IMPORTANT: This function will process all 8-pins from the Port ( A -> B and DOT ) MULTIPLEXED
 * - when passing the argument display add 1 to the pin in the port:for enable pin PC5: display = 6
 * - Any delay in main will corrupt this function
 * */
void SEVENSEGMENT_displayMultiplexed(uint8 display,uint8 number);

#endif /* APP_HAL_SEVENSEGMENT_DISPLAY_H_ */
