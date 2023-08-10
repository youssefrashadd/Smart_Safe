/*
 * passlock.h
 *
 * Created: 8/6/2023 1:54:13 PM
 *  Author: youssef rashad
 */ 


#ifndef PASSLOCK_H_
#define PASSLOCK_H_
#include <avr/interrupt.h>
#include "eeprom.h"
#include "lcd.h"
#include "timer.h"
#include "keypad.h"
#define passlen 4
#define notpressed 0xFF
#define notstored 0xFF
#define userpassadd 0x70
#define min_identical_entered_pass 2
u8 passaddress, set_password[passlen];
u16 glob_userpass[passlen];
void setlockpass( void);
u8 changelockpass(u8 passaddress);
boolean checkpass (u16 pass[]);
void passlock_init(void);
void print_savedpass(void);
void show_correctpass(void);
void show_wrongpass(void);
void check_registeredpass(void);
void input_password(void);
void reset_password(void);
void print_lockstatus(u8 lockflag);
#endif /* PASSLOCK_H_ */