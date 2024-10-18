/*
 * File:   LCD_example.c
 * Author: afier
 *
 * Created on October 15, 2024, 5:46 PM
 */

#include <xc.h>
#include "fusibles.h"
#define _XTAL_FREQ 4000000

void LCD_Init();
void LCD_Clear();
void LCD_SL();
void LCD_SR();
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_Set_Cursor(unsigned char, unsigned char);
void LCD_Write_Char(char);
void LCD_Write_String(char*);


void main(void) {
    
    int v = 3;
    
    LCD_Init();
    LCD_Clear();
    LCD_Set_Cursor(1,1);
    LCD_Write_String("Tecnologico");
    __delay_ms(300);
    LCD_Set_Cursor(2,1);
    //LCD_Write_String("de Monterrey");
    LCD_Write_String("Voltaje: ");
    LCD_Set_Cursor(2,9);
    LCD_Write_Char(v+48);
    LCD_Set_Cursor(2,11);
    LCD_Write_String("Volts");
    __delay_ms(300);
    while(1)
    {
        //for(int i=0; i<4; i++)
        //{
        //  __delay_ms(300);
        //  LCD_SR();
        //}
        //for(int i=0; i<4; i++)
        //{
         // __delay_ms(300);
          //LCD_SL();
        //}
    }
    return;
}
