/*
 * File:   main_interrupcion.c
 * Author: afier
 *
 * Created on October 17, 2024, 4:09 PM
 */


#include "fusibles.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

void interrupcionGeneral(void);
unsigned char i = 0;

void retarrdo(int a);

void retardo(int a)
{
    int i;
    
    for(i=0; i<a; i++)
    {
        __delay_ms(1);
    }
}

void main(void) {
    
    TRISD = 0x00; //  Configura el PUERTO D como salida.
    TRISBbits.TRISB0 = 1; //  Configura el pin RB0 como entrada.
    INTCONbits.INT0IE = 1; //  Habilita interrupcion Externa INT0.
    INTCON2bits.INTEDG0 = 0; //  Interrupcion por flanco de bajada.
    INTCONbits.INT0IF = 0; //  Borra el flag de INT0IF.
    RCONbits.IPEN = 0; //  Deshabilita las Interrupciones de Prioridad.
    INTCONbits.PEIE = 1; //  Habilita interrupciones PERIFERICAS.
    INTCONbits.GIE = 1; //  Habilita Interrupcion GLOBAL.
    
    while (1) {
        //LATD = 1;
        //retardo(500); 
        //LATD = 0;
        //retardo(500); 
    }
}

void __interrupt() ISR(void) 
{
    if (INTCONbits.INT0IF) {
        INTCONbits.INT0IF = 0;
        
        if (++i == 16) {
            i = 0;
        }
        LATD = i;
        
    }
    
return;
}