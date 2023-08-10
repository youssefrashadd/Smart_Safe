/*
 * eeprom.c
 * Created: 8/5/2023 2:26:53 PM
 *  Author: reBuyTech
 */ 
#include "eeprom.h"

void EEPROM_write(u16 uiAddress, u8 ucData)
{
	/* Wait for completion of previous write */
	while(CHECK_BIT(EEPROM_EECR_REG, EEPROM_EEWE_BIT_NO) == 1)
	{
			;/*	Do Nothing	*/
	}
	/* Set up address and data registers */
	EEPROM_EEAR_REG = uiAddress;
	EEPROM_EEDR_REG = ucData;
	/* Write logical one to EEMWE */
	SET_BIT(EEPROM_EECR_REG,EEPROM_EEMWE_BIT_NO);
	/* Start eeprom write by setting EEWE */
	SET_BIT(EEPROM_EECR_REG, EEPROM_EEWE_BIT_NO);
}

u8 EEPROM_read(u16 uiAddress)
{
	/* Wait for completion of previous write */
	while(CHECK_BIT(EEPROM_EECR_REG, EEPROM_EEWE_BIT_NO) == 1)
	{
		;/*	Do Nothing	*/
	}
	/* Set up address register */
	EEPROM_EEAR_REG = uiAddress;
	/* Start eeprom read by writing EERE */
	SET_BIT(EEPROM_EECR_REG,EEPROM_EERE_BIT_NO);
	/* Return data from data register */
	return EEPROM_EEDR_REG;
}