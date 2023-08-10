/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  keypad_cfg.h
 *       Module:  keypad
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef KEYPAD_CFG_H
#define KEYPAD_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*	Rows Configurations	*/

#define KEYPAD_ROW1_PORT				DIO_PORTC
#define KEYPAD_ROW1_CHANNEL				DIO_PIN5

#define KEYPAD_ROW2_PORT				DIO_PORTC
#define KEYPAD_ROW2_CHANNEL				DIO_PIN4

#define KEYPAD_ROW3_PORT				DIO_PORTC
#define KEYPAD_ROW3_CHANNEL				DIO_PIN3

#define KEYPAD_ROW4_PORT				DIO_PORTC
#define KEYPAD_ROW4_CHANNEL				DIO_PIN2

/*	Columns Configurations	*/

#define KEYPAD_COL1_PORT				DIO_PORTD
#define KEYPAD_COL1_CHANNEL				DIO_PIN7

#define KEYPAD_COL2_PORT				DIO_PORTD
#define KEYPAD_COL2_CHANNEL				DIO_PIN6

#define KEYPAD_COL3_PORT				DIO_PORTD
#define KEYPAD_COL3_CHANNEL				DIO_PIN5

#define KEYPAD_COL4_PORT				DIO_PORTD
#define KEYPAD_COL4_CHANNEL				DIO_PIN3
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* KEYPAD_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: keypad_cfg.h
 *********************************************************************************************************************/
