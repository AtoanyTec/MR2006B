
#include "fuses.h"
#define _XTAL_FREQ 4000000
#include <xc.h>

void interrupcionGeneral(void);

unsigned char i = 0;

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
    }
}

void interrupt INT_EXT_0(void) {
    if (INTCONbits.INT0IF) {
        INTCONbits.INT0IF = 0;
        if (++i == 16) {
            i = 0;
        }
        LATD = i;
    }
}
