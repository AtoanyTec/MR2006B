/*
 * File:   main_LCD_4bits.c
 * Author: afier
 *
 * Created on September 20, 2022, 11:31 AM
 */


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
    
    TRISB = 0;
    ADCON1 = 0b1111111;
    
    LATB = 0;
    
    do{
    LATB=0b00000000;
    LATB=0b01000011;
    LATB=0b00000011;
    LATB=0b01000011;
    LATB=0b00000011;
    LATB=0b01000011;
    LATB=0b00000011;
    LATB=0b01000010;
    LATB=0b00000010;
    LATB=0b01000010;
    LATB=0b00000010;
    LATB=0b01000001;
    LATB=0b00000001;
    LATB=0b01000000;
    LATB=0b00000000;
    LATB=0b01001111;
    LATB=0b00001111;
    
    LATB = 0;
    
    
    //LATB=0b01010010;
    //LATB=0b00010010;
    //LATB=0b01010001;
    //LATB=0b00010001;
    
    }while(1);
  
    
    
    return;
}
