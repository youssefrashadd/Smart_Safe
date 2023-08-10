/*
 * timer.c
 *
 * Created: 8/10/2023 3:53:31 AM
 *  Author: youssef rashad
 */ 
#include "timer.h"
void timer_init() {
	// Configure Timer/Counter 1 (16-bit) in CTC mode
	TCCR1B |= (1 << WGM12); // CTC mode
	OCR1A = 15624; // (16e6 / (1024 * 1)) - 1, for 1 second delay
	TCCR1B |= (1 << CS10) | (1 << CS12); // Set prescaler to 1024
	TIMSK |= (1 << OCIE1A); // Enable timer compare interrupt
}
