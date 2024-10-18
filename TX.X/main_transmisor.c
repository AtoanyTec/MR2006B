#pragma config PLLDIV = 5, CPUDIV = OSC1_PLL2, USBDIV = 2
#pragma config FOSC = HSPLL_HS, FCMEN = OFF, IESO = OFF
#pragma config PWRT = OFF, BOR = OFF, VREGEN = OFF
#pragma config WDT = OFF, WDTPS = 32768
#pragma config MCLRE = ON, LPT1OSC = OFF, PBADEN = OFF
#pragma config STVREN = ON, LVP = OFF, ICPRT = OFF, XINST = OFF
 
#define _XTAL_FREQ 20000000

#include <xc.h>

void main(void) {
    
    ADCON1 = 0b111111;
     
    TRISD=0x0f;
    int i =1;
    int j =0;
    int z =0;
    int T = 100;
    int Place =64;
    TRISCbits.RC6 =0; //Pinc RC6 como salida para Tx
    TXSTAbits.TX9 =0; // Modo-8 bits
    TXSTAbits.TXEN= 1; // Habilita Transmision
    TXSTAbits.SYNC =0; // Modo- Asincrono
    TXSTAbits.BRGH = 0;//Modo baja velocidad de Baudios
    BAUDCONbits.BRG16= 0; // Baudios modo-8bits
    RCSTAbits.SPEN =1; // Habilita el Modulo SSP como UART 

int x[4]={1,0,0,0};/* Pines de salida del puerto B*/
int y[4];/* Pines de entrada del puerto B*/
long disp[4][4]={{'7','4','1','o'},
{'8','5','2','0'},{'9','6','3','='},{'/','x','-','+'}};    
                 
//instrucciones de operacion para LCD
while(1){
    
    
   PORTDbits.RD4= x[0];
   PORTDbits.RD5= x[1];
   PORTDbits.RD6= x[2];
   PORTDbits.RD7= x[3];
    
   __delay_ms(20);
   
   
  while (RD0 == 1){
      while (!TXSTAbits.TRMT);
      //TXREG = disp [0][i];
      TXREG = 'A';
      __delay_ms(10);
      while (z<T && RD1 ==1){
      __delay_ms(10);
      z=z++;}
  }        
    while (RD1 == 1){
       while (!TXSTAbits.TRMT);
      //TXREG = disp [1][i];
      TXREG = 'A';
      __delay_ms(10);
      while (z<T && RD1 ==1){
      __delay_ms(10);
      z=z++;}
  }       
   
    while (RD2 == 1){
       while (!TXSTAbits.TRMT);
      //TXREG = disp [2][i];
      TXREG = 'A';
      __delay_ms(10);
      while (z<T && RD1 ==1){
      __delay_ms(10);
      z=z++;}
    }
    while (RD3 == 1){
      while (!TXSTAbits.TRMT);
      //TXREG = disp [3][i];
      TXREG = 'A';
      __delay_ms(10);
      while (z<T && RD1 ==1){
      __delay_ms(10);
      z=z++;}
  }
   
  
   
  if (i<3){
  j=i;
  x[j]=0;
  i=i++;
  x[i]=1;
   }
  else{
  j=0;
  x[j]=0;
  i=0;
  x[i]=1;
   }
z=0;//Primera fila
}
    
}