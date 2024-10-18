/*
 * File:   pushbutton.c
 * Author: afier
 *
 * Created on September 22, 2022, 6:00 PM
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

void main(void) {
    TRISC=1;
    TRISB=0;
    PORTB=0;
    PORTC=0;
    if (PORTC==1)
    {
        PORTB=1;
    }
    return;
}
