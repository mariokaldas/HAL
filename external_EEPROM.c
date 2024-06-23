/* external EEPROM driver
 * EEPROM.c
 *
 *  Created on: Oct 23, 2023
 *      Author: mario kaldas
 */
#include "external_EEPROM.h"

#include "MCAL_Atmega32/AVRIO.h"
#include "MCAL_Atmega32/TWI.h"

/*
 * VERY IMPORTANT
 *
 * When using the driver you must delay 10ms at least between write and read
 * otherwise it WILL NOT work
 * this info from data-sheet of EEPROM
 *
 * */

/****************************************************************************
 *                             Global variables
 ***************************************************************************/

TWI_configType g_configs = {1,400000};

/****************************************************************************
 *                          Functions definition
 ***************************************************************************/

void EEPROM_init(void){

	TWI_init(&g_configs);

}

uint8 EEPROM_writeByte(uint16 u16add,uint8 u8data){

	TWI_start();

	if(TWI_getStatus() != TWI_STATUS_START)
		return ERROR;

	/*
	 *  Take A8 A9 A10 bits from memory address to device address
	 *  (RW bit = 0 (write))
	 * */
	TWI_writeByte((uint8) (0xA0 | ((u16add & 0x0700)>>7)) );

	if(TWI_getStatus() != TWI_STATUS_MT_SLA_W_ACK)
		return ERROR;

	/* Send memory address to store in */
	TWI_writeByte((uint8) u16add );

	if(TWI_getStatus() != TWI_STATUS_MT_DATA_ACK)
		return ERROR;

	/* Write data in the EEPROM memory */
	TWI_writeByte(u8data);

	if(TWI_getStatus() != TWI_STATUS_MT_DATA_ACK)
		return ERROR;

	TWI_stop();

	return SUCCESS;
}


uint8 EEPROM_readByte(uint16 u16add,uint8* data){

	TWI_start();

	if(TWI_getStatus() != TWI_STATUS_START)
		return ERROR;


	/*
	 *  Take A8 A9 A10 bits from memory address to device address
	 *  (RW bit = 0 (write))
	 * */
	TWI_writeByte((uint8) (0xA0 | ((u16add & 0x0700)>>7)) );

	if(TWI_getStatus() != TWI_STATUS_MT_SLA_W_ACK)
		return ERROR;

	/* Send memory address to store in */
	TWI_writeByte((uint8) u16add );

	if(TWI_getStatus() != TWI_STATUS_MT_DATA_ACK)
		return ERROR;

	TWI_start();

	if(TWI_getStatus() != TWI_STATUS_REPEATED_START)
		return ERROR;

	/*
	 *  Take A8 A9 A10 bits from memory address to device address
	 *  (RW bit = 1 (read))
	 * */
	TWI_writeByte((uint8) (0xA0 | ((u16add & 0x0700)>>7) | 1) );

	if(TWI_getStatus() != TWI_STATUS_MT_SLA_R_ACK)
		return ERROR;

	*data = TWI_readByteWithNACK();

	if(TWI_getStatus() != TWI_STATUS_MR_DATA_NACK)
		return ERROR;

	TWI_stop();

	return SUCCESS;
}


