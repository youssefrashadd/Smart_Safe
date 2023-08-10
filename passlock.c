/*
* passlock.c
*
* Created: 8/6/2023 1:54:34 PM
*  Author: youssef rashad
*/
#include "passlock.h"
#include "keypad.h"
void passlock_init(void)
{
	keypad_vidInit(); //initialize keypad
	keypad_videnpullup(); //for proteus
	lcd_vidInit(); //initialize lcd
	check_registeredpass(); //check if there's saved password in lcd
	GICR |= (1<<INT1); // enable int1 pin for change password
	sei(); //enable global interrupt
	MCUCR |= (1<<ISC10); //any logical change on INT1 triggers an interrupt
}
void setlockpass(void)
{
	u8 passctr = 0 , passchar , num_of_pass = 0;
	const u16  pass_add [4] = {0x70,0x71,0x72,0x73}; //password address in eeprom
	lcd_vidClrDislay(); //clear lcd
	lcd_vidDisplyStr("Set lock password");
	while(num_of_pass<min_identical_entered_pass) //user shall enter password twice identical
	{
		
	
	while(passctr < passlen) //iterate over entered digits from keypad 
	{

		
		while(!keypad_bolIsPressed()); //wait untill key is pressed
		passchar = keypad_u8GetKey(); //copy pressed key into variable
		_delay_ms(250);
		set_password[passctr] = passchar; //copy variable value (pressed key) into array
		_delay_ms(250);
		EEPROM_write(pass_add[passctr],set_password[passctr]); //write in eeprom the value of the element in the array
		_delay_ms(250);
		lcd_vidGotoRowColumn(1,passctr);
		lcd_vidDisplyChar(EEPROM_read(pass_add[passctr])); //display entered key
		_delay_ms(100);
		lcd_vidGotoRowColumn(1,passctr);
		lcd_vidDisplyChar('*'); //display password shape
		passctr++; //increment pass counter that 1 key is entered and saved in eeprom
		
	}
	
	lcd_vidClrDislay(); //clear lcd
	lcd_vidDisplyStr("Re-enter password"); //re-enter lock password as minimum is twice identical
	input_password(); // get password from user
	if (checkpass(glob_userpass)) //check if they're identical
	{
		lcd_vidClrDislay();
		_delay_ms(100);
		lcd_vidDisplyStr("Password is set");
		num_of_pass+=2; //increment counter to exit loop as passwords are identical
		
	}
	else
	{
		lcd_vidClrDislay();
		lcd_vidDisplyStr("Passwords don't match");
		_delay_ms(250);
		lcd_vidClrDislay();
		lcd_vidDisplyStr("Set lock password");
		passctr = 0;
		num_of_pass = 0; // reset both counters to begin to set password from beginning as passwords don't match
	}
	
	}
	
}
void print_savedpass()
{
	u8 counterr = 0,loccx;
	while(counterr < passlen)
	{
		loccx = set_password[counterr] ;
		lcd_vidDisplyChar(loccx);
		_delay_ms(500);
		counterr++;
	}
}
boolean checkpass (u16 pass[])
{
	u8 chckpassctr = 0 ,checkres = 1;
	const u16  pass_add [4] = {0x70,0x71,0x72,0x73}; // password address in eeprom
	for (chckpassctr = 0 ; chckpassctr < passlen ; chckpassctr++)
	{
		if ( pass[chckpassctr] != EEPROM_read(pass_add[chckpassctr]) ) //if an element in entered password doesn't equal the stored password
		{
			checkres = 0; //set flag =0
			break;
		}
		
	}
	lcd_vidClrDislay();
	return checkres; //return flag value
}
void show_correctpass(void)
{
	lcd_vidGotoRowColumn(0,0);
	lcd_vidDisplyStr("Correct password");
// 	lcd_vidGotoRowColumn(4,0);
// 	lcd_vidDisplyStr("Status:Unlocked");
/*	_delay_ms(1000);*/
}
void show_wrongpass(void)
{
	lcd_vidGotoRowColumn(0,0);
	lcd_vidDisplyStr("Incorrect password");
// 	lcd_vidGotoRowColumn(4,0);
// 	lcd_vidDisplyStr("Status:LOCKED");
/*	_delay_ms(1000);*/
}
void check_registeredpass(void)
{
	if (EEPROM_read(userpassadd) == 0XFF) //read eeprom value if it equals 0xFF then there's no password set
	{
		setlockpass(); //set lock password
		_delay_ms(300);
		lcd_vidSendCmd(0x01);
		lcd_vidDisplyStr("Enter password to    ");
		lcd_vidGotoRowColumn(1,0);
		lcd_vidDisplyStr("unlock");
		_delay_ms(100);
	}
	else
	{
		lcd_vidDisplyStr("Hello User");
		_delay_ms(500);
		lcd_vidSendCmd(0x01);
		lcd_vidDisplyStr("Enter password to    ");
		lcd_vidGotoRowColumn(1,0);
		lcd_vidDisplyStr("unlock");
		_delay_ms(100);

	}
	
}
void input_password(void)
{
	u8 loc_passctr = 0,loc_passchar;
	while(loc_passctr<passlen)
	{
		while(!keypad_bolIsPressed()); // wait until key is pressed
		loc_passchar = keypad_u8GetKey(); // save entered key in variable
		lcd_vidGotoRowColumn(2,loc_passctr);
		lcd_vidDisplyChar('*');
		_delay_ms(250);
		glob_userpass[loc_passctr] = loc_passchar; //
		loc_passctr++;
	}
}
void reset_password(void)
{
	EEPROM_write(0X70,0XFF);
	EEPROM_write(0X71,0XFF);
	EEPROM_write(0X72,0XFF);
	EEPROM_write(0X73,0XFF);
}
void print_lockstatus(u8 lockflag)
{
	if(lockflag == 0)
	{
		lcd_vidGotoRowColumn(3,0);
		lcd_vidDisplyStr("Status:locked");
	}
	else
	{
		lcd_vidGotoRowColumn(3,0);
		lcd_vidDisplyStr("Status:unlocked");
	}
}