/*
 * File:   main_seq.c
 * Author: afier
 *
 * Created on July 12, 2022, 4:08 PM
 * 
 * PIC18F4550
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

void retardo(int n)
{
    for(int i=0; i<n; i++)
    {
        __delay_ms(1);
    }
}

void main(void) {
    
    //TRIS configura los puertos como entrada o como salida
    // 0 0utput
    // 1 1nput
    //TRISB configura el puerto B como salida
    
    TRISB = 0;
    TRISD = 0;
    int i = 0;
    int k = 0;
    
    LATB = 0;
    
    do{
        
        for(i=0; i<300; i++)
        {
        PORTB = 1;
        PORTDbits.RD0 = 1;
        __delay_us(500);
        PORTDbits.RD0 = 0;
        __delay_us(500);
        }
   
        
        for(i=0; i<300; i++)
        {
        PORTB = 2;
        PORTDbits.RD0 = 1;
        __delay_us(600);
        PORTDbits.RD0 = 0;
        __delay_us(600);
         }
        
        for(i=0; i<300; i++)
        {
        PORTB = 4;
        PORTDbits.RD0 = 1;
        __delay_us(800);
        PORTDbits.RD0 = 0;
        __delay_us(800);
         }

        
        
    }while(1);
    

    
    return;
}
