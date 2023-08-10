/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  dio.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void dio_vidConfigChannel
						(dio_port_t port, dio_pin_t pin, dio_direction_t direction)        
* \Description     : this service for configuring IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port 	   -> MC port ID
					 channel   -> MC channel ID
					 direction -> MC channel direction
* \Return value:   : None                            
*******************************************************************************/
void dio_vidConfigChannel(dio_portId_t port, dio_channelId_t channel, dio_direction_t direction)
{
	switch (port)
	{
	case DIO_PORTA:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRA_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRA_REG,channel);
		}
		break;

	case DIO_PORTB:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRB_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRB_REG,channel);
		}
		break;

	case DIO_PORTC:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRC_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRC_REG,channel);
		}
		break;

	case DIO_PORTD:
		if (direction == OUTPUT)
		{
			SET_BIT (DIO_DDRD_REG,channel);
		}
		else
		{
			CLEAR_BIT (DIO_DDRD_REG,channel);
		}
		break;
	}
}

/******************************************************************************
* \Syntax          : void dio_vidWriteChannel
						(dio_portId_t port, dio_channelId_t channel, dio_level_t level)      
* \Description     : this service for writting on IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port 	  -> MC port ID
					 channel  -> MC channel ID
					 level    -> MC channel level
* \Return value:   : None                            
*******************************************************************************/
void dio_vidWriteChannel(dio_portId_t port, dio_channelId_t channel, dio_level_t level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTA_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTA_REG,channel);
		}
		break;

	case DIO_PORTB:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTB_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTB_REG,channel);
		}
		break;

	case DIO_PORTC:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTC_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTC_REG,channel);
		}
		break;

	case DIO_PORTD:
		if (level == STD_LOW)
		{
			CLEAR_BIT(DIO_PORTD_REG,channel);
		}
		else
		{
			SET_BIT(DIO_PORTD_REG,channel);
		}
		break;
	}
}

/******************************************************************************
* \Syntax          :void dio_vidWriteChannelGroup
						(dio_portId_t port,u8 value,u8 mask)
* \Description     : this service for writing on group of IO channels                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  -> MC port ID
					 value -> data value
					 mask  -> data mask
* \Return value:   : None                            
*******************************************************************************/
void dio_vidWriteChannelGroup(dio_portId_t port,u8 value,u8 mask,u8 pos)
{
	u8 loc_portData = 0;
	switch (port)
	{
		case DIO_PORTA:
		loc_portData = DIO_PORTA_REG;
		//clear old data
		loc_portData &= ~(mask); //ba3mel clear lel old data (banadaf el reg abl ma3mel write 3aleh)
		//validate new data
		value = (value<<pos) & mask; //bashafeto w ba3melo and ma3 el mask ashan law geeh input aktar men l max beta3 ek mask yehsal trim
		//write new data
		loc_portData |= value;
		DIO_PORTA_REG = loc_portData;
		break;
		case DIO_PORTB:
		loc_portData = DIO_PORTB_REG;
		//clear old data
		loc_portData &= ~(mask); //ba3mel clear lel old data (banadaf el reg abl ma3mel write 3aleh)
		//validate new data
		value = (value<<pos) & mask; //bashafeto w ba3melo and ma3 el mask ashan law geeh input aktar men l max beta3 ek mask yehsal trim
		//write new data
		loc_portData |= value;
		DIO_PORTB_REG = loc_portData;
		break;
		case DIO_PORTC:
		loc_portData = DIO_PORTC_REG;
		//clear old data
		loc_portData &= ~(mask); //ba3mel clear lel old data (banadaf el reg abl ma3mel write 3aleh)
		//validate new data
		value = (value<<pos) & mask; //bashafeto w ba3melo and ma3 el mask ashan law geeh input aktar men l max beta3 ek mask yehsal trim
		//write new data
		loc_portData |= value;
		DIO_PORTD_REG = loc_portData;
		break;
		case DIO_PORTD:
		loc_portData = DIO_PORTD_REG;
		//clear old data
		loc_portData &= ~(mask); //ba3mel clear lel old data (banadaf el reg abl ma3mel write 3aleh)
		//validate new data
		value = (value<<pos) & mask; //bashafeto w ba3melo and ma3 el mask ashan law geeh input aktar men l max beta3 ek mask yehsal trim
		//write new data
		loc_portData |= value;
		DIO_PORTD_REG = loc_portData;
		break;
	}
	
}

/******************************************************************************
* \Syntax          :void dio_vidFlipChannel
						(dio_portId_t port, dio_channelId_t channel)
* \Description     : this service for fliping IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  -> MC port ID
					 channel  -> MC channel ID
* \Return value:   : None                            
*******************************************************************************/
void dio_vidFlipChannel(dio_portId_t port, dio_channelId_t channel)
{
	switch (port)
	{
	case DIO_PORTA:
		FLIP_BIT(DIO_PORTA_REG,channel);
		break;

	case DIO_PORTB:
		FLIP_BIT(DIO_PORTB_REG,channel);
		break;

	case DIO_PORTC:
		FLIP_BIT(DIO_PORTC_REG,channel);
		break;

	case DIO_PORTD:
		FLIP_BIT(DIO_PORTD_REG,channel);
		break;
	}
}

/******************************************************************************
* \Syntax          :dio_level_t Dio_dioLevelReadChannel
						(dio_portId_t port, dio_channelId_t channel)
* \Description     : this service for reading IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port     -> MC port ID
					 channel  -> MC channel ID
* \Return value:   : loc_pinRead   -> IO channel level                           
*******************************************************************************/
dio_level_t dio_dioLevelReadChannel(dio_portId_t port, dio_channelId_t channel)
{
	dio_level_t readdata = 0xFF;
	switch(port){
		case DIO_PORTA:
		readdata = CHECK_BIT(DIO_PINA_REG,channel);
		break;
		case DIO_PORTB:
		readdata = CHECK_BIT(DIO_PINB_REG,channel);
		break;
		case DIO_PORTC:
		readdata = CHECK_BIT(DIO_PINC_REG,channel);
		break;
		case DIO_PORTD:
		readdata = CHECK_BIT(DIO_PIND_REG,channel);
		break;
	}
	return readdata;
}

/******************************************************************************
* \Syntax          :void dio_vidEnablePullUp
						(dio_portId_t port, dio_channelId_t channel)
* \Description     : this service for enabling pull up resistor for IO channel                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : port  -> MC port ID
					 channel  -> MC channel ID
* \Return value:   : None                            
*******************************************************************************/
void dio_vidEnablePullUp(dio_portId_t port, dio_channelId_t channel)
{
		switch(port){
			case DIO_PORTA:
			SET_BIT(DIO_PORTA_REG,channel);
			break;
			case DIO_PORTB:
			SET_BIT(DIO_PORTB_REG,channel);
			break;
			case DIO_PORTC:
			SET_BIT(DIO_PORTC_REG,channel);
			break;
			case DIO_PORTD:
			SET_BIT(DIO_PORTD_REG,channel);
			break;
		}
}
/**********************************************************************************************************************
 *  END OF FILE: dio.c
 *********************************************************************************************************************/
