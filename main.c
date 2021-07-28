/*
 * File:   main.c
 * Author: Matti
 *
 * Created on July 28, 2021, 12:02 PM
 */


#include <xc.h>
#include <pic18f26k83.h>
#include <setup.h>

/*  ***************  TIMER *************** */
       void delayzz(void)
        {              int i, j;
                        for(i=0;i<5000;i++)
                {         for(j=0;j<2;j++)
                      {     /* Well its Just a Timer */     }    }   }

            /* ****************** MAIN ****************** */
void main(void)
   {
                        setpin();                 // PORT B Setting: Set all the pins in port B to Output      
           while(1)  
                   {
                                LED1_on();                    // Glow led 1
                                LED2_off();                    // OFF led 2
                                LED3_on();                    // Glow Led 3
                        delayzz();
                                LED1_off();                     // OFF led 1
                                LED2_on();                    // Glow led 2
                                LED3_off();                    // OFF led 3
                       delayzz();
                 }
     }

/* THE END */
