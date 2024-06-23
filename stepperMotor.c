/*
 * stepperMotor.c
 *
 *  Created on: Apr 15, 2024
 *      Author: mario
 */

/******************************************************************************************
 *                                          INCLUDES
 ******************************************************************************************/

#include"stepperMotor.h"
#include"util/delay.h"

/******************************************************************************************
 *                                    FUNCTIONS DEFINITION
 ******************************************************************************************/

void STEPPERMOTOR_init(uint8 motor_number){

	GPIO_setupPinDirection(STEPPERMOTOR_PORT, motor_number, PIN_OUTPUT);
	GPIO_setupPinDirection(STEPPERMOTOR_PORT, motor_number + 1, PIN_OUTPUT);
}

void STEPPERMOTOR_steps(uint8 motor_number ,uint16 steps,STEPPERMOTOR_directionType direction){

	int i;

	GPIO_writePin(STEPPERMOTOR_PORT,motor_number+1,direction);

	for(i=0; i<steps; i++ ){

		GPIO_writePin(STEPPERMOTOR_PORT,motor_number,LOW);
		GPIO_writePin(STEPPERMOTOR_PORT,motor_number,HIGH);
		_delay_us(100);
	}
}

void STEPPERMOTOR_moveTillLS(uint8 motor_number,STEPPERMOTOR_directionType direction,uint8 LS_number){

	GPIO_writePin(STEPPERMOTOR_PORT,motor_number+1,direction);

	for(;;){

		if(LS_getReading(LS_number) == OBJECT_DETECTED)
			return;

		GPIO_writePin(STEPPERMOTOR_PORT,motor_number,LOW);
		GPIO_writePin(STEPPERMOTOR_PORT,motor_number,HIGH);
		_delay_us(100);
	}
}
