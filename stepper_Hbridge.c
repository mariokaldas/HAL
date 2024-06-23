/*
 * stepper_Hbridge.c
 *
 *  Created on: May 7, 2024
 *      Author: mario
 */

/*****************************************************************************************
 *											INCLUDES
 ******************************************************************************************/

#include"stepper_Hbridge.h"
#include<util/delay.h>
#include"limitSwitch.h"

/*****************************************************************************************
 *									  FUNCTIONS DEFINITION
 ******************************************************************************************/

void STEPPER_HBRIDGE_init(uint8 motor_number){

	switch(motor_number){

	case 1:

		GPIO_setupPinDirection(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT+1,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT+2,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT+3,PIN_OUTPUT);

		GPIO_writePin(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT+1,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT+2,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR1_FIRST_INPUT+3,LOW);

		break;

	case 2:

		GPIO_setupPinDirection(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT+1,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT+2,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT+3,PIN_OUTPUT);

		GPIO_writePin(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT+1,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT+2,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_FIRST_PORT,STEPPER_HBRIDGE_MOTOR2_FIRST_INPUT+3,LOW);

		break;

	case 3:

		GPIO_setupPinDirection(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT+1,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT+2,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT+3,PIN_OUTPUT);

		GPIO_writePin(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT+1,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT+2,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR3_FIRST_INPUT+3,LOW);

		break;

	case 4:

		GPIO_setupPinDirection(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT+1,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT+2,PIN_OUTPUT);
		GPIO_setupPinDirection(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT+3,PIN_OUTPUT);

		GPIO_writePin(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT+1,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT+2,LOW);
		GPIO_writePin(STEPPER_HBRIDGE_SECOND_PORT,STEPPER_HBRIDGE_MOTOR4_FIRST_INPUT+3,LOW);

		break;
	}
}


void STEPPER_HBRIDGE_steps(uint8 motor_number,uint8 steps,uint8 direction){

	/*
	 * 1100
	 * 0100
	 * 0110
	 * 0010
	 * 0011
	 * 0001
	 * 1001
	 * 1000
	 *
	 * */
	uint8 step[8]={12,4,6,2,3,1,9,8};
	static uint8 step_number_cw=0;
	static uint8 step_number_ccw=7;
	uint8 i;

	uint8 value;

	switch(motor_number){

	case 1:

		value = GPIO_readPort(STEPPER_HBRIDGE_FIRST_PORT) & 0xF0;

		if(direction == STEPPER_HBRIDGE_CW){

			for(i=0;i<steps;step_number_cw++,i++){

				if(step_number_cw==8)
					step_number_cw=0;
				GPIO_writePort(STEPPER_HBRIDGE_FIRST_PORT, value | (step[step_number_cw]&0x0F));
				_delay_ms(500);
			}
		}
		else{

			for(i=0;i<steps;step_number_ccw--,i++){
				if(step_number_ccw==255)
					step_number_ccw=7;
				GPIO_writePort(STEPPER_HBRIDGE_FIRST_PORT, value | (step[step_number_ccw]&0x0F));
				_delay_ms(500);
			}
		}

		break;

	case 2:

		value = GPIO_readPort(STEPPER_HBRIDGE_FIRST_PORT) & 0x0F;

		if(direction == STEPPER_HBRIDGE_CW){

			for(i=0;i<steps;step_number_cw++,i++){

				if(step_number_cw==8)
					step_number_cw=0;
				GPIO_writePort(STEPPER_HBRIDGE_FIRST_PORT, value | ((step[step_number_cw]&0x0F)<<4));
				_delay_ms(500);
			}
		}
		else{

			for(i=0;i<steps;step_number_ccw--,i++){
				if(step_number_ccw==255)
					step_number_ccw=7;
				GPIO_writePort(STEPPER_HBRIDGE_FIRST_PORT, value | ((step[step_number_ccw]&0x0F)<<4));
				_delay_ms(500);
			}
		}

		break;

	case 3:

		value = GPIO_readPort(STEPPER_HBRIDGE_SECOND_PORT) & 0xF0;

		if(direction == STEPPER_HBRIDGE_CW){

			for(i=0;i<steps;step_number_cw++,i++){

				if(step_number_cw==8)
					step_number_cw=0;
				GPIO_writePort(STEPPER_HBRIDGE_SECOND_PORT, value | (step[step_number_cw]&0x0F));
				_delay_ms(500);
			}
		}
		else{

			for(i=0;i<steps;step_number_ccw--,i++){
				if(step_number_ccw==255)
					step_number_ccw=7;
				GPIO_writePort(STEPPER_HBRIDGE_SECOND_PORT, value | (step[step_number_ccw]&0x0F));
				_delay_ms(500);
			}
		}

		break;

	case 4:

		if(direction == STEPPER_HBRIDGE_CW){

			for(i=0;i<steps;step_number_cw++,i++){

				if(step_number_cw==8)
					step_number_cw=0;
				GPIO_writePort(STEPPER_HBRIDGE_SECOND_PORT, value | ((step[step_number_cw]&0x0F)<<4));
				_delay_ms(500);
			}
		}
		else{

			for(i=0;i<steps;step_number_ccw--,i++){
				if(step_number_ccw==255)
					step_number_ccw=7;
				GPIO_writePort(STEPPER_HBRIDGE_SECOND_PORT, value | ((step[step_number_ccw]&0x0F)<<4));
				_delay_ms(500);
			}
		}

		break;

	}
}

void STEPPER_HBRIDGE_moveTillLS(uint8 motor_number,STEPPER_HBRIDGE_directiontype direction,uint8 LS_number){


	/*
	 * 1100
	 * 0100
	 * 0110
	 * 0010
	 * 0011
	 * 0001
	 * 1001
	 * 1000
	 *
	 * */
	uint8 step[8]={12,4,6,2,3,1,9,8};
	static uint8 step_number_cw=0;
	static uint8 step_number_ccw=7;
	uint8 i;

	uint8 value;

	switch(motor_number){

	case 1:

		value = GPIO_readPort(STEPPER_HBRIDGE_FIRST_PORT) & 0xF0;

		if(direction == STEPPER_HBRIDGE_CW){

			for(;;step_number_cw++){

				if(LS_getReading(LS_number) == LS_OBJECT_DETECTED)
					return;

				if(step_number_cw==8)
					step_number_cw=0;
				GPIO_writePort(STEPPER_HBRIDGE_FIRST_PORT, value | (step[step_number_cw]&0x0F));
				_delay_ms(500);
			}
		}
		else{

			for(;;step_number_ccw--){

				if(LS_getReading(LS_number) == LS_OBJECT_DETECTED)
					return;

				if(step_number_ccw==255)
					step_number_ccw=7;
				GPIO_writePort(STEPPER_HBRIDGE_FIRST_PORT, value | (step[step_number_ccw]&0x0F));
				_delay_ms(500);
			}
		}

		break;

	case 2:

		value = GPIO_readPort(STEPPER_HBRIDGE_FIRST_PORT) & 0x0F;

		if(direction == STEPPER_HBRIDGE_CW){

			for(;;step_number_cw++){

				if(LS_getReading(LS_number) == LS_OBJECT_DETECTED)
					return;

				if(step_number_cw==8)
					step_number_cw=0;
				GPIO_writePort(STEPPER_HBRIDGE_FIRST_PORT, value | ((step[step_number_cw]&0x0F)<<4));
				_delay_ms(500);
			}
		}
		else{

			for(;;step_number_ccw--){

				if(LS_getReading(LS_number) == LS_OBJECT_DETECTED)
					return;

				if(step_number_ccw==255)
					step_number_ccw=7;
				GPIO_writePort(STEPPER_HBRIDGE_FIRST_PORT, value | ((step[step_number_ccw]&0x0F)<<4));
				_delay_ms(500);
			}
		}

		break;

	case 3:

		value = GPIO_readPort(STEPPER_HBRIDGE_SECOND_PORT) & 0xF0;

		if(direction == STEPPER_HBRIDGE_CW){

			for(;;step_number_cw++){

				if(LS_getReading(LS_number) == LS_OBJECT_DETECTED)
					return;

				if(step_number_cw==8)
					step_number_cw=0;
				GPIO_writePort(STEPPER_HBRIDGE_SECOND_PORT, value | (step[step_number_cw]&0x0F));
				_delay_ms(500);
			}
		}
		else{

			for(;;step_number_ccw--){

				if(LS_getReading(LS_number) == LS_OBJECT_DETECTED)
					return;

				if(step_number_ccw==255)
					step_number_ccw=7;
				GPIO_writePort(STEPPER_HBRIDGE_SECOND_PORT, value | (step[step_number_ccw]&0x0F));
				_delay_ms(500);
			}
		}

		break;

	case 4:

		if(direction == STEPPER_HBRIDGE_CW){

			for(;;step_number_cw++){

				if(LS_getReading(LS_number) == LS_OBJECT_DETECTED)
					return;

				if(step_number_cw==8)
					step_number_cw=0;
				GPIO_writePort(STEPPER_HBRIDGE_SECOND_PORT, value | ((step[step_number_cw]&0x0F)<<4));
				_delay_ms(500);
			}
		}
		else{

			for(;;step_number_ccw--){

				if(LS_getReading(LS_number) == LS_OBJECT_DETECTED)
					return;

				if(step_number_ccw==255)
					step_number_ccw=7;
				GPIO_writePort(STEPPER_HBRIDGE_SECOND_PORT, value | ((step[step_number_ccw]&0x0F)<<4));
				_delay_ms(500);
			}
		}

		break;

	}

}


