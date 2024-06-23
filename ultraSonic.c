/* ultrasonic driver
 * ultraSonic.c
 *
 *  Created on: Oct 15, 2023
 *      Author: mario kaldas
 */

#include"ultraSonic.h"
#include<util/delay.h>
#include "MCAL_Atmega32/gpio.h"
#include "MCAL_Atmega32/ICU.h"

/****************************************************************************
 *                           Global variables
 * *************************************************************************/

ICU_configType ICU_configrations = {FACTOR1,RISING};

uint8 volatile static g_edgeCount=0;
uint8 volatile static g_widthOfEcho;

/****************************************************************************
 *                         Function definition
 * *************************************************************************/

void ULTRASONIC_init(void){

	ICU_init(&ICU_configrations);
	ICU_setCallBack(ULTRASONIC_edgeProcessing);
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,PIN_OUTPUT);

}

void ULTRASONIC_trigger(void){

	GPIO_writePin(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,HIGH);
	_delay_us(12);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,LOW);
}

uint16 ULTRASONIC_readDistance(void){

	uint16 distance;

	ULTRASONIC_trigger();

	/*
	 * Distance = Time * speed ( sonic speed )
	 *          = Time * 34000(cm/s) / 2
	 *
	 *          = 1*10^-6 * 17000 * value of ICU
	 *
	 *          = 0.017 * value of ICU
	 */

	distance = (uint16)( (float)0.017 * g_widthOfEcho);
	return distance;
}

void ULTRASONIC_edgeProcessing(void){

	g_edgeCount++;
	if(g_edgeCount == 1){

		ICU_clearTimer();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2){

		g_widthOfEcho=ICU_getInputCaptureValue();

		ICU_clearTimer();
		ICU_deInit();
	}
}
