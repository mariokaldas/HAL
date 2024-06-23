/*
 * servo.c
 *
 *  Created on: Apr 15, 2024
 *      Author: mario
 */

/*****************************************************************************************
 *                                         INCLUDES
 *****************************************************************************************/
#include"MCAL_Atmega32/timer1.h"
#include"servo.h"

/*****************************************************************************************
 *                                     GLOBAL VARIABLES
 *****************************************************************************************/

/* best configurations for servo-motor : generates 50.0000 HZ (20MS) */
TIMER1_configType configs={PWM_AB,FACTOR8,0,39999,SERVO_MIN_DUTY_CYCLE,SERVO_MIN_DUTY_CYCLE};


/*****************************************************************************************
 *                                   FUNCTIONS DEFINITION
 *****************************************************************************************/

void SERVO_init(void){

	TIMER1_init(&configs);/* start at 0 degree both motors */

}


void SERVO_angle(uint8 servo_num,uint8 degree){

	float32 dutyCycle;

	/* map function in arduino */
	dutyCycle =
	(degree-SERVO_MIN_ANGLE) * (float32)(SERVO_MAX_DUTY_CYCLE-SERVO_MIN_DUTY_CYCLE)/(SERVO_MAX_ANGLE-SERVO_MIN_ANGLE) + SERVO_MIN_DUTY_CYCLE;

	if(servo_num == 1)
		configs.UNITA_dutyCycle = dutyCycle;
	else
		configs.UNITB_dutyCycle = dutyCycle;

	TIMER1_init(&configs);


}
