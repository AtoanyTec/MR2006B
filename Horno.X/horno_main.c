/*
 * File:   horno_main.c
 * Author: afier
 *
 * Created on November 29, 2022, 9:13 AM
 */

#include <xc.h>
#include <XLCD.h>

#include <plib/delays.h>
#include <plib/adc.h> 
#include <plib/timers.h>
#include <plib/pwm.h>

#include <stdio.h>
#include <stdlib.h>


#include <xc.h>
#define _XTAL_FREQ 20000000

void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD(void);


int resultado, unidad, decena;

float q0, q1, q2;
float R_s = 1500;
float e=0, e_1=0, e_2=0;
float u=0, u_1=0;
float kp, ti, td;
float T=0.5;
float K=0.535, tao=10, theta=1;

void main(void) 
{
    //LCD initilization
    OpenXLCD(FOUR_BIT & LINES_5X7);
    while(BusyXLCD());
    WriteCmdXLCD(0x06);
    WriteCmdXLCD(0x0C);
    Delay10TCYx(5);
    
    //ADC
    OpenADC(ADC_FOSC_64 &
    ADC_RIGHT_JUST &
    ADC_16_TAD,
    ADC_CH0 &
    ADC_INT_OFF &
    ADC_VREFPLUS_VDD &
    ADC_VREFMINUS_VSS,
    14);
    
    //PWM
    TRISC = 0;
    unsigned char prescaler = T2_PS_1_16;
    OpenTimer2(prescaler);
    OpenPWM1(0x68);  //3khz
    SetDCPWM1(0); //duty cycle
    
    //Calculo de q's
    q0=kp*(1+T/(2*ti)+td/T);
    q1=-kp*(1-T/(2*ti)+(2*td)/T);
    q2=(kp*td)/T;
    
   
    
    while(1)
    {
        ConvertADC();   
        while(BusyADC());
        resultado = ReadADC();
        
        sensor = (resultado*5000)/1024;
                
        resultado = (resultado*5)/1023;
        unidad = resultado % 10;
        decena = (resultado - unidad)/10;
        
        SetDDRamAddr(0x00);
        putrsXLCD("Control de TEMP");
        SetDDRamAddr(0x40);
        putcXLCD(unidad+48);
    }
    
    
    
//    e = R_s - sensor
    
    return;
}

void DelayFor18TCY(void){
 Delay10TCYx(120);
}
void DelayPORXLCD(void){
 Delay1KTCYx(75);
 return;
}
void DelayXLCD(void){
 Delay1KTCYx(25);
 return;
}