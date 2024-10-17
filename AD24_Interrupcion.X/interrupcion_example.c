/*
 * File:   interrupcion_example.c
 * Author: afier
 *
 * Created on October 8, 2024, 11:49 AM
 */

#include "fusibles.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

void interrupcionGeneral(void);

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
        LATD = 1;
        retardo(500); 
        LATD = 0;
        retardo(500); 
    }
    
    
   // return;
}

void interrupt INT_EXT_0(void) {
    if (INTCONbits.INT0IF) {
        INTCONbits.INT0IF = 0;
        
        LATD = 2;
        retardo(500); 
        LATD = 0;
        retardo(500); 
    }
}
