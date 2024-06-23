/*
 * servo.h
 *
 *  Created on: Apr 15, 2024
 *      Author: mario
 */

#ifndef SERVO_H_
#define SERVO_H_

/*****************************************************************************************
 *                                         INCLUDES
 *****************************************************************************************/
#include"MCAL_Atmega32/timer1.h"
#include"MCAL_Atmega32/std_types.h"

/*****************************************************************************************
 *                                        DEFINITIONS
 *****************************************************************************************/

/* IMPORTATNT NOTE: the following 4 parameters depend on servo moto type */

#define SERVO_MIN_ANGLE 0
#define SERVO_MAX_ANGLE 180
#define SERVO_MIN_DUTY_CYCLE 2.5
#define SERVO_MAX_DUTY_CYCLE 12.5

/*
 * 1- black motor MG995
 * minimum angle 0
 * maximum angle 180
 * minimum duty cycle 2.5%
 * maximum duty cycle 12.5%
 *
 *
 * 2- blue motor SG90
 * minimum angle 0
 * maximum angle 180
 * minimum duty cycle 5%
 * maximum duty cycle 10%
 *
 * */

/*****************************************************************************************
 *                                    FUNCTIONS PROTOTYPE
 *****************************************************************************************/

void SERVO_init(void);
void SERVO_angle(uint8 sevo_num,uint8 degree);

#endif /* SERVO_H_ */
