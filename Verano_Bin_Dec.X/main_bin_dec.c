/*
 * File:   main_bin_dec.c
 * Author: afier
 *
 * Created on July 14, 2022, 4:29 PM
 */

// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDT = ON // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRT = OFF // Power-up Timer Enable bit (PWRT disabled)
//#pragma config BORN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
//#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
//#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG

#define _XTAL_FREQ 20000000

#include <xc.h>

void main(void) {
    
    ADCON1 = 0b11111111;
    
    TRISB = 0;
    TRISD = 1;
    
    PORTB = 0;
    
    if(PORTD == 0)
    {
        //encender un cero en el display 7SEG
        //LATB = 0b00111111;
        LATB = 0x3f;
        __delay_ms(35);
    }
    else if(PORTD == 1)
    {
        //LATB = 0b00000110;
        LATB = 0x06;
        __delay_ms(35);
    }
    else if(PORTD == 2)
    {
        //LATB = 0b00000110;
        LATB = 0x5b;
        __delay_ms(35);
    }
    else if(PORTD == 3)
    {
        //LATB = 0b00000110;
        LATB = 0x4f;
        __delay_ms(35);
    }
    
    else if(PORTD == 4)
    {
        //LATB = 0b00000110;
        LATB = 0x66;
        __delay_ms(35);
    }
    
    else if(PORTD == 5)
    {
        //LATB = 0b00000110;
        LATB = 0x6D;
        __delay_ms(35);
    }
    else if(PORTD == 6)
    {
        //LATB = 0b00000110;
        LATB = 0x7D;
        __delay_ms(35);
    }
    else if(PORTD == 7)
    {
        //LATB = 0b00000110;
        LATB = 0x07;
        __delay_ms(35);
    }
    else if(PORTD == 8)
    {
        //LATB = 0b00000110;
        LATB = 0x7F;
        __delay_ms(35);
    }
    else if(PORTD == 9)
    {
        //LATB = 0b00000110;
        LATB = 0x6F;
        __delay_ms(35);
    }
    
    return;
}
