/*
 * File:   main.c
 * Author: Matti
 *
 * Created on July 28, 2021, 12:02 PM
 */


#include <pic18f26k83.h>
#include <stdbool.h>
#include <stdint.h>
#include "setup.h"

 /* ****************** MAIN ****************** */
void main(void){
    // Define vars
    uint16_t results;
    uint16_t zero; 
    bool firstcross = false;
    uint8_t periods = [0, 0, 0, 0, 0];
    uint8_t count = 0;
    
    setpin();                 // PORT B Setting: Set all the pins in port B to Output    
    timer0_init();
    LED1_on();
    LED2_on();
    LED3_on();
    
    //setup ADC
    ADCON0bits.FM = 1; //right justify
    ADCON0bits.CS = 1; //FRC Clock
    ADPCH = 0x00; //RA0 is Analog channel  UPDATE
    TRISAbits.TRISA0 = 1; //Set RA0 to input UPDATE
    ANSELAbits.ANSELA0 = 1; //Set RA0 to analog UPDATE
    ADCON0bits.ON = 1; //Turn ADC On
 
    
    ADCON0bits.GO = 1; //Start conversion
    while (ADCON0bits.GO); //Wait for conversion done
    zero = (ADRESH<<8) + ADRESL; //Read result
    
    // Turn off lights to indicate 0 set
    LED1_off();
    LED2_off();
    LED3_off();
    
    while(true){
        //while (count < 5){
            
        ADCON0bits.GO = 1; //Start conversion
        while (ADCON0bits.GO); //Wait for conversion done
        results = (ADRESH<<8) + ADRESL; //Read result
        
        if (results*0.95 > zero){
            LED1_on();
        }
            
    }

        
        
        
        /* Pseudo code time WOOO HOOO
         * Define vars and whatnot
         * [x]Setup ADC
         * [x]Define what our 0 crossing val is
         * []sample guitar input (probably within own loop so theres minimum commands between samples)
         * []determine freq
         * []determine which string we are probably tuning
         * []turn servo x degrees, proportional to how off the tuning
         * [] show lights whether high low on
         * [] restart loop until string tuned
         * [] loop some more so can do all strings
         * 
         * 
         * Timer things: set value in timer0 counter to 0 when we start timing, read value at end, convert to hz
         * 
         */
       
    }
}

static void __interrupt() interrupt_handler(){
    if (PIE3bits.TMR0IE == 1 && PIR3bits.TMR0IF == 1) {
        timer0_handle_interrupt();
        PIR3bits.TMR0IF = 0;
    }
}

/* THE END */
