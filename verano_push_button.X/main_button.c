/*
 * File:   main_button.c
 * Author: afier
 *
 * Created on July 13, 2022, 4:12 PM
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

void main(void) 
{
    ADCON1 = 0b11111111;
    
    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 1;
    
    PORTBbits.RB0 = 0;
    
    if(PORTBbits.RB1 == 1)
    {
        PORTBbits.RB0 = 1;
    }
    else
    {
        PORTBbits.RB0 = 0;
    }
   
    return;
}
