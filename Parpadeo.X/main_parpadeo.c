/*
 * File:   main_parpadeo.c
 * Author: afier
 *
 * Created on August 15, 2022, 11:40 AM
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
    
    // Definir el pin como salida (TRIS)
    // 1 1nput, 0 0utput
    ADCON1 = 0b1111111;
    
    TRISBbits.RB0 = 0; // el bit RB0 será salida
    TRISBbits.RB1 = 1; // el bit RB1 será entrada
    
    if (PORTBbits.RB1 == 1)
    {
        LATBbits.LATB0 = 1; // saca un 1 por RB0
        __delay_ms(35);
    }
    else
    {
        LATBbits.LATB0 = 0; // saca un 1 por RB0
        __delay_ms(35);
    }
    

    
    return;
}
