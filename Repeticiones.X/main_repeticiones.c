/*
 * File:   main_repeticiones.c
 * Author: afier
 *
 * Created on June 13, 2022, 4:08 PM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "fuses.h"
#define _XTAL_FREQ 20000000


void retardo(n)
{
    __delay_ms(1);
}



void main(void) {
    
    ADCON1 = 0b11111111; //todos los puertos configurados como digitales
    
    //Configuración de puertos como entrada/salida
    TRISB = 0b00000001;
    TRISD = 0;
    
    int unidades = 0;
    int decenas = 0;
    
    int numeros[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
    
    
    while(1)
    {
        retardo(5000);
        LATB = numeros[decenas];
        LATD = numeros[unidades];
        
        if(PORTCbits.RC0 == 1)
        {
            
            unidades = unidades + 1;
            
            if(unidades == 10)
            {
                decenas = decenas + 1;
                unidades = 0;
            }
        }
    }
    
    

    
    return;
}






