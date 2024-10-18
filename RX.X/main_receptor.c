#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, VREGEN = OFF
#pragma config WDT = OFF, WDTPS = 32768
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
 
#define _XTAL_FREQ 20000000

#include <xc.h>

void main(void) {
    ADCON1 = 0b1111111;
    
     char voltaje;
     char LED1 = 'A';
     char LED2 = 'A';
     char LED3 = 'A';
    
    TRISCbits.RC7 = 1; //PIN RC7 como entrada de digital rx
    RCSTAbits.RC9 = 0; // Modo 8bits
    RCSTAbits.SREN = 1;//Habilita Recepcion
    RCSTAbits.CREN = 0; //Recepcion asincrona
    BAUDCONbits.BRG16 = 0; // Baudios modo-8bits
    RCSTAbits.SPEN = 1; //Habilita el modulo SSP como uart
    TRISB=0 ;
    
    //while(1){
    while(!RCIF);
    voltaje = RCREG;
    
    if (voltaje == LED1){
        PORTBbits.RB0 =1;
        
    }
    else{
        PORTBbits.RB0=0;
    }
    
    
    
    }
    
