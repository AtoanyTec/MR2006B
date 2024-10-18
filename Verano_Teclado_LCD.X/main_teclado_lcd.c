/*
 * File:   teclado.c
 * Author: Asus
 *
 * Created on 13 de abril de 2020, 12:02 PM
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <plib/xlcd.h>
#include <plib/delays.h>
 
//BITS DE CONFIGURACION.....
#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, VREGEN = OFF
#pragma config WDT = OFF, WDTPS = 32768
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
 
#define _XTAL_FREQ 48000000

void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD(void);

void escribir_eeprom(char direccion, char dato){
    while(EECON1bits.WR==1);  //1. esperar a que no haya una escritura en curso
                              
    EEADR=direccion;          //2. cargar la direccion
    EEDATA=dato;              //3. cargar el dato
    EECON1bits.EEPGD=0;       //4. setear EEPGD a 0
    EECON1bits.WREN=1;        //5. se habilita la escritura en la EEPROM 
    INTCONbits.GIE=0;         //6. deshabilitar las interrupcione
    EECON2=0x55;              //7. cargar en EECON2 0x55
    EECON2=0xaa;              //8. cargar en EECON2 0xaa
    EECON1bits.WR=1;          //9. iniciar la escritura en la EEPROM
    INTCONbits.GIE=1;         //10. habilitar las interrupciones
    EECON1bits.WREN=0;        //11. deshabilitar la escritura en la EEPROM
    while(EECON1bits.WR==1);  //12. comprobar que la escritura terminó
}



char leer_eeprom(char direccion){
    EEADR=direccion;      //1. cargar la direccion
    EECON1bits.EEPGD=0;   //2. acceso a la EEPROM
    EECON1bits.RD=1;      //3. habilitar la lectura de la EEPROM
    return EEDATA;        //4. en el registro EEDATA se encuentra el dato
                          
}




void main(void) {
    
    //Configurando LCD
    OpenXLCD(FOUR_BIT & LINES_5X7);
    //Esperar hasta que el display esté disponible.
    while(BusyXLCD());
    //Mover cursor a la derecha...
    WriteCmdXLCD(0x06);
    //Desactivando el cursor.
    WriteCmdXLCD(0x0C);



    char dato; 
    
    TRISB = 0;
    TRISD = 0b11110000;
    
    //Datos de EEPROM
    escribir_eeprom(0, 'W');
    dato = leer_eeprom(0);
    
    SetDDRamAddr(0x00);
    putcXLCD(dato);
    
    do{
    
    LATDbits.LD0= 1;
    LATDbits.LD1= 0;
    LATDbits.LD2= 0;
    LATDbits.LD3= 0;
    if(PORTDbits.RD4 == 1)
    {  
        putcXLCD('7');
    }
    if(PORTDbits.RD5 == 1)
    {
        putcXLCD('8');
    }
    if(PORTDbits.RD6 == 1)
    {
       putcXLCD('9');
    }
    if(PORTDbits.RD7 == 1)
    {
        putcXLCD('/');
    }
    __delay_ms(10);
    
    
    
    
    
   
    LATDbits.LD0= 0;
    LATDbits.LD1= 1;
    LATDbits.LD2= 0;
    LATDbits.LD3= 0;
    __delay_ms(10);
    if(PORTDbits.RD4 == 1)
    {  
        putcXLCD('4');
    }
    if(PORTDbits.RD5 == 1)
    {
        putcXLCD('5');
    }
    if(PORTDbits.RD6 == 1)
    {
        putcXLCD('6');
    }
    if(PORTDbits.RD7 == 1)
    {
        putcXLCD('X');
    }
    __delay_ms(10);
    
    
   
    LATDbits.LD0= 0;
    LATDbits.LD1= 0;
    LATDbits.LD2= 1;
    LATDbits.LD3= 0;
    __delay_ms(10);
    if(PORTDbits.RD4 == 1)
    {  
        putcXLCD('1');
    }
    if(PORTDbits.RD5 == 1)
    {
        putcXLCD('2');
    }
    if(PORTDbits.RD6 == 1)
    {
        putcXLCD('3');
    }
    if(PORTDbits.RD7 == 1)
    {
        putcXLCD('-');
    }
    __delay_ms(10);
    
    
   
    LATDbits.LD0= 0;
    LATDbits.LD1= 0;
    LATDbits.LD2= 0;
    LATDbits.LD3= 1;
    __delay_ms(10);
    if(PORTDbits.RD4 == 1)
    {  
        putcXLCD('O');
    }
    if(PORTDbits.RD5 == 1)
    {
        putcXLCD('0');
    }
    if(PORTDbits.RD6 == 1)
    {
        putcXLCD('=');
    }
    if(PORTDbits.RD7 == 1)
    {
        putcXLCD('+');
    }
    __delay_ms(10);
    
    }while(1);
    

   
    return;
}


void DelayFor18TCY(void)
{
Delay10TCYx(120);
}
 
void DelayPORXLCD(void)
{
Delay1KTCYx(180);
return;
}
 
void DelayXLCD(void)
{
Delay1KTCYx(60);
return;
}