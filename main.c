/*
* Password_lock_system.c

* Created: 8/5/2023 3:17:02 PM
* Author : youssef rashad
*/
#define F_CPU 16000000UL
#include <util/delay.h>
#include "passlock.h"
volatile u16 UnlockTime = 0;
u8 lockstatus_flag =0;



int main(void)
{
	
	boolean auth_flg;
	passlock_init();
	
	


	while (1)
	{
		print_lockstatus(lockstatus_flag);
		
		input_password();
		auth_flg = checkpass(glob_userpass);
		if (auth_flg)
		{
			show_correctpass();
			timer_init();
			lockstatus_flag = 1;
		}
		else if(auth_flg == FALSE)
		{
			show_wrongpass();
		}
		
	}
}
ISR(INT1_vect)
{
	 	u8 loc_flg = 0;
	 	lcd_vidClrDislay();
	 	_delay_ms(250);
		 lcd_vidDisplyStr("locked");
	 	lcd_vidDisplyStr("Enter old pass");
	 	input_password();
	 	if (checkpass(glob_userpass))
	 	{
			lcd_vidClrDislay();
	 		show_correctpass();
	 		loc_flg = 1;
	 	}
	 	else if(checkpass(glob_userpass) == FALSE)
	 	{
			lcd_vidClrDislay();
	 		show_wrongpass();
	 	}
	 	if(loc_flg == 1)
	 	{
	 		reset_password();
	 		check_registeredpass();
	 	}
	
}
ISR(TIMER1_COMPA_vect) {
	UnlockTime++; // Increment the timer counter
	if (UnlockTime >= 20) {
		// Reset operation: Jump to the reset vector address
		lcd_vidClrDislay();
		asm volatile ("jmp 0");
	}
}
