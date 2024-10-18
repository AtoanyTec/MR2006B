/*
 * File:   teclado.c
 * Author: Asus
 *
 * Created on 13 de abril de 2020, 12:02 PM
 */



#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <plib/xlcd.h>
#include <plib/delays.h>
 
//BITS DE CONFIGURACION.....
#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, VREGEN = OFF
#pragma config WDT = OFF, WDTPS = 32768
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
 
#define _XTAL_FREQ 48000000

void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD(void);

void main(void) {
    TRISB = 0;
    TRISD = 0b11110000;
    
    LATDbits.LD0= 1;
    LATDbits.LD1= 0;
    LATDbits.LD2= 0;
    LATDbits.LD3= 0;
    if(PORTDbits.RD4 == 1)
    {  
        PORTB = 7;
    }
    if(PORTDbits.RD5 == 1)
    {
        PORTB = 8;
    }
    if(PORTDbits.RD6 == 1)
    {
        PORTB = 9;
    }
    if(PORTDbits.RD7 == 1)
    {
        PORTB = 10;
    }
    __delay_ms(10);
    
    
    
    
    
   
    LATDbits.LD0= 0;
    LATDbits.LD1= 1;
    LATDbits.LD2= 0;
    LATDbits.LD3= 0;
    __delay_ms(10);
    if(PORTDbits.RD4 == 1)
    {  
        PORTB = 4;
    }
    if(PORTDbits.RD5 == 1)
    {
        PORTB = 5;
    }
    if(PORTDbits.RD6 == 1)
    {
        PORTB = 6;
    }
    if(PORTDbits.RD7 == 1)
    {
        PORTB = 11;
    }
    __delay_ms(10);
    
    
   
    LATDbits.LD0= 0;
    LATDbits.LD1= 0;
    LATDbits.LD2= 1;
    LATDbits.LD3= 0;
    __delay_ms(10);
    if(PORTDbits.RD4 == 1)
    {  
        PORTB = 1;
    }
    if(PORTDbits.RD5 == 1)
    {
        PORTB = 2;
    }
    if(PORTDbits.RD6 == 1)
    {
        PORTB = 3;
    }
    if(PORTDbits.RD7 == 1)
    {
        PORTB = 12;
    }
    __delay_ms(10);
    
    
   
    LATDbits.LD0= 0;
    LATDbits.LD1= 0;
    LATDbits.LD2= 0;
    LATDbits.LD3= 1;
    __delay_ms(10);
    if(PORTDbits.RD4 == 1)
    {  
        PORTB = 15;
    }
    if(PORTDbits.RD5 == 1)
    {
        PORTB = 0;
    }
    if(PORTDbits.RD6 == 1)
    {
        PORTB = 14;
    }
    if(PORTDbits.RD7 == 1)
    {
        PORTB = 13;
    }
    __delay_ms(10);
    

   
    return;
}
