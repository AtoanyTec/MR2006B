/*
 * File:   receptor_main.c
 * Author: afier
 *
 * Created on November 3, 2022, 10:50 AM
 */
#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, VREGEN = OFF
#pragma config WDT = OFF, WDTPS = 32768
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF

#include <xc.h>
#define _XTAL_FREQ 20000000



void main(void) {
    
    TRISB = 0;
    ADCON1 = 0b1111111;
    
    TRISCbits.RC7 = 1;         	    // Pin RC7 como entrada digital para RX
    RCSTAbits.RC9=0;      	   	       //Modo 8bits
    RCSTAbits.SREN=1;      	  	//Habilita recepcion
    RCSTAbits.CREN=0;       	  	//Recepcion asincrona
    BAUDCONbits.BRG16 = 0;   	      // Baudios modo-8bits.
    RCSTAbits.SPEN = 1;                //Hbilita el Módulo SSP como UART.
    
    char voltaje;
    
    //LATBbits.LATB0=1;
    
    while(!RCIF);
    voltaje = RCREG;
    
    if(voltaje=='B')
    {
        PORTB=1;
    }
    else
    {
        PORTB=0;
    }
    
  
    return;
}

