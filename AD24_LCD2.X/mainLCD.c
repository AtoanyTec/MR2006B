/*
 * Interfacing PIC16F887 microcontroller with LCD screen
 * C Code for MPLAB XC8 compiler
 * Internal oscillator used @ 8MHz
 * This is a free software with NO WARRANTY
 * http://simple-circuit.com/
*/ 
 
 

 
 
#include <xc.h>
#define _XTAL_FREQ 4000000
#include <stdio.h>            // for sprintf
#include "LCD_Lib.c"          // include LCD driver source file
 
char i = 0, text[4];
 
void main(void)
{
    OSCCON =  0X70;    // set internal oscillator to 8MHz
 
    LCD_Begin();       // initialize LCD module
 
    LCD_Goto(4, 1);           // go to column 4, row 1
    LCD_Print("MPLAB XC8");
    LCD_Goto(3, 2);           // go to column 3, row 2
    LCD_Print("LCD Example");
 
    __delay_ms(5000);         // wait 5 seconds
 
    LCD_Cmd(LCD_CLEAR);       // clear the whole screen
    LCD_Goto(3, 1);           // go to column 3, row 1
    LCD_Print("Hello world!");
 
    while (1)
    {
      sprintf(text, "%03u", i);
 
      LCD_Goto(7, 2);      // go to column 7, row 2
      LCD_Print(text);
 
      i++;                 // increment i
      __delay_ms(500);     // wait 1/2 second
    }
}
// End of code.