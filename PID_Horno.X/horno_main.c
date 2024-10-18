/*
 * File:   horno_main.c
 * Author: afier
 *
 * Created on November 30, 2022, 8:45 AM
 */


#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, VREGEN = OFF
#pragma config WDT = OFF, WDTPS = 32768
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
 
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <plib/adc.h>    



#define _XTAL_FREQ 20000000

float q0, q1, q2;
float R_s = 0.45;
float e=0, e_1=0, e_2=0;
float u=0, u_1=0;

float kp=0, ti=0, td=0;

float T=0.1;
float K=0.535, tao=10, theta=1;
int sensor, pre_sensor;
int controlador = 0;

int Temperatura;
int TempRef;
int Error;

int unidadT, decenaT;
int unidadRef, decenaRef;
int unidadError, decenaError;
int unidadTemp, decenaTemp, residuoTemp;

int voltaje=5;


void main(void) 
{
    
    //Calculo de parametros PID
    kp=(1.2*tao)/(K*theta);
    ti=2*theta;
    td=theta/2;
    
    q0= kp*( 1 + (T/(2*ti)) + (td/T) );
    q1= -kp*( 1 - (T/(2*ti)) + 2*(td/T));
    q2= ( (kp*td)/T );

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
    //OpenPWM1(0x37);
    SetDCPWM1(0); //duty cycle
    
//    SetDDRamAddr(0x00);
//    putrsXLCD("Control de TEMP");
    
//    SetDDRamAddr(0x00);
//    putrsXLCD("                ");



    while(1)
    {
        SelChanConvADC(ADC_CH0);
        while(BusyADC()); 
        
        pre_sensor = ReadADC();
        sensor = (pre_sensor*5000)/1023; //lectura en milivolts
        e = R_s - sensor;
        
        u = u_1 + (q0*e) + (q1*e_1) + (q2*e_2);
        
        if(u>1023){u = 1023;}
        if(u<0){u = 0;}
        
        e_2 = e_1;
        e_1 = e;
        u_1 = u;
        
        controlador = u/5;
        
        SetDCPWM1(controlador);
        
        //Visualización
        Temperatura = (pre_sensor * 5)/1023;
        Temperatura = Temperatura*100;
        
        decenaT = Temperatura/10;
        unidadT = Temperatura-decenaT*10;

        SetDDRamAddr(0x00);
        putrsXLCD("T: ");
        SetDDRamAddr(0x02);
        putcXLCD(decenaT+48);
        SetDDRamAddr(0x40);
        putcXLCD(voltaje+48);
        putrsXLCD(" C");
        
    }
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