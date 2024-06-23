/* buzzer driver
 * buzzer.h
 *
 *  Created on: Oct 26, 2023
 *      Author: mario
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "MCAL_Atmega32/std_types.h"

/****************************************************************************
 *                               Definitions
 ****************************************************************************/

#define BUZZER_PORT PORTC_ID
#define BUZZER_PIN 4

/****************************************************************************
 *                          Functions prototype
 ****************************************************************************/


void BUZZER_init(void);
void BUZZER_on(void);
void BUZZER_off(void);

#endif /* BUZZER_H_ */
