/*
 * File:   main_blink.c
 * Author: afier
 *
 * Created on July 11, 2022, 4:52 PM
 */

#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    
    //TRISB = 0; // 0uput
    //TRISB = 1; // 1nput
    
    TRISBbits.RB0 = 0; //el primer bit es de salida
    //TRISBbits.RB1 = 1; //el segundo bit como entrada
    
    PORTB = 0b00000001; //binario
    //PORTB = 0x01; // hexadecimal
    //PORTB = 1; // decimal
    __delay_ms(30);
    PORTB = 0b00000000;
    __delay_ms(30);
   
    return;
}
