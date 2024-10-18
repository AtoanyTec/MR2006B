/*
 * File:   main_button.c
 * Author: afier
 *
 * Created on June 6, 2022, 11:12 AM
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


#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISB = 0;
    TRISC = 1;
    
    PORTB = 0b00000000;
    
    if(PORTC == 1)
    {
        PORTB = 1;
        __delay_ms(300);
    }
    else
    {
        PORTB = 0;
    }
    return;
}
