/* pushbutton driver
 * pushbutton.c
 *
 *  Created on: Nov 30, 2023
 *      Author: mario kaldas
 */
#include"pushbutton.h"

#include "MCAL/gpio.h"

/***************************************************************************
 *                          Functions definition
 *************************************************************************** */
void PB_init(uint8 PB_num){

    if(PB_num <= (NUM_OF_PINS_PER_PORT-1)){

        GPIO_setupPinDirection(PB_PORT, PB_num, PIN_INPUT);
    }
    else{

        GPIO_setupPinDirection(PB_PORT_ADD, PB_num % (NUM_OF_PINS_PER_PORT-1), PIN_INPUT);
    }}


uint8 PB_getReading(uint8 PB_num){


    if(PB_num <= (NUM_OF_PINS_PER_PORT-1)){

        return GPIO_readPin(PB_PORT,PB_num);
    }
    else{

        return GPIO_readPin(PB_PORT_ADD,PB_num % (NUM_OF_PINS_PER_PORT-1));
    }
}


