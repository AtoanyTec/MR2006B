/*
 * File:   bin_7seg_main.c
 * Author: afier
 *
 * Created on August 22, 2022, 11:54 AM
 */

#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDT = ON // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRT = OFF // Power-up Timer Enable bit (PWRT disabled)
//#pragma config BORN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#include <xc.h>

#define _XTAL_FREQ 20000000

void main(void) {
    ADCON1 = 0b1111111;
    
    int display[10]={0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7D, 0x07, 0x7f, 0x6f};
    
    TRISD = 1;
    TRISB = 0;
    
    PORTB = 0;
    
    do{
    
    if(PORTD == 0)
    {
        //LATB = 0b00111111;
        LATB = display[0];
        __delay_ms(30);
    }
    else if(PORTD == 1)
    {
        LATB = 0b00000110;
        __delay_ms(30);
    }
    else
    {
        __delay_ms(30);
    }
    
    }while(1);
    
    return;
}
