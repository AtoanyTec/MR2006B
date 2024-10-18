// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
//#pragma config WDT = ON // Watchdog Timer Enable bit (WDT enabled)
//#pragma config PWRT = OFF // Power-up Timer Enable bit (PWRT disabled)
//#pragma config BORN = ON // Brown-out Reset Enable bit (BOR enabled)
//#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
//#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
//#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
//#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG

#define _XTAL_FREQ 4000000
#include <xc.h>

int main()
{
    int i = 0;
    
  TRISB = 0; 
  
  while(1)
  {
    RB0 = 1; 
   
    for(i = 0; i<200; i++)
    {
        RB1 = 1;
        __delay_ms(2); 
        RB1 = 0;
        __delay_ms(2); 
    }
    __delay_ms(500); 
    
    RB0 = 0;  
    __delay_ms(500); 
  }
  return 0;
}