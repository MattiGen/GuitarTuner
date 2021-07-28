/* 
 * File:   setup.h
 * Author: Matti
 *
 * Created on July 28, 2021, 12:04 PM
 */

#ifndef SETUP_H
#define	SETUP_H

#ifdef	__cplusplus
extern "C" {
#endif


#define setpin() TRISB = 0;           //Setting all PORTB pins to output pin RB0-7

#define LD1 LATBbits.LATB5      // RB0
#define LD2 LATBbits.LATB4      // RB1
#define LD3 LATBbits.LATB3      // RB2

#define LED1_on() LD1 = 0;      
#define LED2_on() LD2 = 0;     
#define LED3_on() LD3 = 0;      

#define LED1_off() LD1 = 1;      
#define LED2_off() LD2 = 1;      
#define LED3_off() LD3 = 1;      

#ifdef	__cplusplus
}
#endif

#endif	/* SETUP_H */

