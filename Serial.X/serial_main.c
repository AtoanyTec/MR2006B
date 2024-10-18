/*
 * File:   serial_main.c
 * Author: afier
 *
 * Created on October 11, 2022, 4:47 PM
 */

#define _XTAL_FREQ 20000000
#include <xc.h>

void main(void) {
    
    TRISCbits.RC6 = 0        //Pin RC6 como salida digital para Tx
    TXSTAbits.TX9 = 0;       // Modo-8bits.
    TXSTAbits.TXEN = 1;      // Habilita Transmisión.
    TXSTAbits.SYNC = 0;      // Modo-Asíncrono.
    TXSTAbits.BRGH = 0;       //Modo-Baja Velocidad de Baudios.
    BAUDCONbits.BRG16 = 0;   //Baudios modo-8bits.
    RCSTAbits.SPEN = 1;     //Habilita el Módulo SSP como UART.
    
    while (!TXSTAbits.TRMT);
    TXREG = 'A';
    __delay_ms(100);


    
    return;
}
