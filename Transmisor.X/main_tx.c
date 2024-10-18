#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, VREGEN = OFF
#pragma config WDT = OFF, WDTPS = 32768
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
 
#define _XTAL_FREQ 20000000
#define BAUD 9600

#include <xc.h>

void main(void) {
    TRISCbits.RC6 =0; //Pinc RC6 como salida para Tx
    TXSTAbits.TX9 =0; // Modo-8 bits
    TXSTAbits.TXEN= 1; // Habilita Transmision
    TXSTAbits.SYNC =0; // Modo- Asincrono
    TXSTAbits.BRGH = 0;//Modo baja velocidad de Baudios
    BAUDCONbits.BRG16= 0; // Baudios modo-8bits
    RCSTAbits.SPEN =1; // Habilita el Modulo SSP como UART 
    
    SPBRG = (unsigned char) (((_XTAL_FREQ / BAUD) / 64) - 1);
    
    while(1)
    {
    while (!TXSTAbits.TRMT){}
    
      TXREG = 'A';
    }
   
    
}