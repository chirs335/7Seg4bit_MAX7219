// ขา D7 D8   โหลดเซล
// ขา D16 D2  จอ LCD
// ขา A0   สวิต

#include "LedControl.h"
/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 MAX7219
 */
LedControl lc=LedControl(12,11,10,1); // MAX7219 
unsigned long delaytime=1000;
float data = 0;
String Sdata1,Sdata2,Sdata3,Sdata4,Sdata0;
int idata1=0,idata2=0,idata3=0,idata4=0 ;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

 Serial.begin(9600);
}


void loop() { 
  Tranferdata();
  writeArduinoOn7Segment();
  
}


void writeArduinoOn7Segment() {
  lc.setDigit(0,0,idata1,false);
    lc.setDigit(0,1,idata2,true);
    lc.setDigit(0,2,idata3,false);
    lc.setDigit(0,3,idata4,false);
    delay(delaytime);
     lc.clearDisplay(0);
 
} 

void Tranferdata() {
  data += 30.7356;
//if (data>=100){data=0;}

Sdata0 = String(data);
  
for (int i = 0; i < Sdata0.length(); i++) {
    if (Sdata0.substring(i, i + 1) == ".") {
      Sdata1 = Sdata0.substring(i-2,i-1);     
      Sdata2 = Sdata0.substring(i-1,i);
      Sdata3 = Sdata0.substring(i+1, i+2);
      Sdata4 = Sdata0.substring(i+2, i+3);
      
      break;
    }
}

if (Sdata1==Sdata0){(Sdata1="0");}
idata1 = Sdata1.toInt(); 
idata2 = Sdata2.toInt(); 
idata3 = Sdata3.toInt(); 
idata4 = Sdata4.toInt(); 
Serial.println(Sdata0);
Serial.println("---------------");

}
