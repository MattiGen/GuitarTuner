/* 
 * File:   timer.h
 * Author: Matti
 *
 * Created on August 17, 2021, 8:07 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#include <stdint.h>

// utilities for handling the timer used in millis()
void timer0_init(void);

// should be called from the general ISR to increment the timer
// DOES NOT CLEAR PIR3bits.TMR0IF! This is the responsibility of the top level ISR.
void timer0_handle_interrupt(void);


uint32_t microtime(void);
#endif	/* PIC18F26K83_TIMER_H */