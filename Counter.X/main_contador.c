#include <xc.h>
#include <plib/timers.h>       // include header files
#include "config.h"             // define configuration bits in this file

unsigned char timerconfig;

void main(void) 
    {
        TRISB=0x00;                 // make PORTB as output
        LATB0=1;                    // make PORTB high
        /* set timer configuration 
         * Timer interrupt on
         * Set timer 16 bit
         *setting prescalar 256
         */ 
        timerconfig= TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256 ;
        
        OpenTimer0(timerconfig); // Load timer 0 configuration
        WriteTimer0(0xB3B4);     // Load starting value to the timer 0
        INTCONbits.TMR0IF = 1;   // Enable timer interrupts
    
        ei();                    // enabling interrupt
    
        while(1);                 // Runs forever (wait here)
    }
   

void interrupt TimerOverflow()  // Interrupt service routine
    {
        di();                        // disable interrupt forawhile 
        if(INTCONbits.TMR0IF == 1)   // When timer overflows
        {
            LATB0 = ~LATB0;          // make PORTB LOW
            INTCONbits.TMR0IF = 0;   // clear the timer0 interrupt flag
            WriteTimer0(0xB3B4);     // load the timer value
        }
        ei();                       // Enable interrupt

    }

 