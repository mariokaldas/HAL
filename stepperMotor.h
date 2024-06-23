/*
 * stepperMotor.h
 *
 *  Created on: Apr 15, 2024
 *      Author: mario
 */

#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

/******************************************************************************************
 *                                          INCLUDES
 ******************************************************************************************/

#include"MCAL_ATMEGA32/gpio.h"
#include"MCAL_ATMEGA32/std_types.h"
#include"limitSwitch.h"

/******************************************************************************************
 *                                 PRE-PROCESSOR CONFIGURATION
 ******************************************************************************************/

#define STEPPERMOTOR_PORT PORTB_ID

#define STEPPERX 0
#define STEPPERX_DIR_PIN (STEPPERX+1) //1

#define STEPPERY 2
#define STEPPERY_DIR_PIN (STEPPERY+1) //3



/******************************************************************************************
 *                                    TYPES DECLARATIONS
 ******************************************************************************************/

typedef enum{

	STEPPER_CW,STEPPER_CCW

}STEPPERMOTOR_directionType;

/******************************************************************************************
 *                                      FUNCTIONS PROTOTYPE
 ******************************************************************************************/

void STEPPERMOTOR_init(uint8 motor_number);
void STEPPERMOTOR_steps(uint8 motor_number ,uint16 steps,STEPPERMOTOR_directionType direction);
void STEPPERMOTOR_moveTillLS(uint8 motor_number,STEPPERMOTOR_directionType direction,uint8 LS_number);


#endif /* STEPPERMOTOR_H_ */
