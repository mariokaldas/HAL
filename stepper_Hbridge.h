/*
 * stepper_Hbridge.h
 *
 *  Created on: May 7, 2024
 *      Author: mario
 */

#ifndef STEPPER_HBRIDGE_H_
#define STEPPER_HBRIDGE_H_

/*****************************************************************************************
 *											INCLUDES
 ******************************************************************************************/

#include "MCAL_ATMEGA32/gpio.h"
#include "MCAL_ATMEGA32/std_types.h"

/*****************************************************************************************
 *										   DEFINITIONS
 ******************************************************************************************/

#define STEPPER_HBRIDGE_FIRST_PORT PORTB_ID
#define STEPPER_HBRIDGE_SECOND_PORT PORTC_ID


/* IN2 will be IN1+1 and so on, so please connect the 4 input pins in order */
#define STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT 0

#define STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT 4

#define STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT 0

#define STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT 4


/* DONOT change the values of following definitions just change the names of motors */
#define STEPPER_HBRIDGE_MOTORZ 1
#define STEPPER_HBRIDGE_MOTOR2 2
#define STEPPER_HBRIDGE_MOTOR3 3
#define STEPPER_HBRIDGE_MOTOR4 4

/*****************************************************************************************
 *										 TYPES DECLARATION
 ******************************************************************************************/

typedef enum{

	STEPPER_HBRIDGE_CW,STEPPER_HBRIDGE_CCW
}STEPPER_HBRIDGE_directiontype;

/*****************************************************************************************
 *										FUNCTIONS PROTOTYPE
 ******************************************************************************************/
/* it is recommended after calling init function to call steps just 1 step for fully initialization  */
void STEPPER_HBRIDGE_init(uint8 motor_number);
void STEPPER_HBRIDGE_steps(uint8 motor_number,uint8 steps,STEPPER_HBRIDGE_directiontype direction);
void STEPPER_HBRIDGE_moveTillLS(uint8 motor_number,STEPPER_HBRIDGE_directiontype direction,uint8 LS_number);


#endif /* STEPPER_HBRIDGE_H_ */
