#include "mono_con.h"
unsigned long tf;
int ledPara[] = { B000, B001, B010, B100, B011, B110, B101, B111 }; 
void setup() {
  config_init();
  tf = millis(); 
}

void loop() {
  unsigned long t = millis();
  if(t - tf < 1000){
    lm.color.GBR = ledPara[6];
    led_stepmotor(lm.b8);
  }else if(t - tf <2000){
    lm.color.GBR = ledPara[0];
    led_stepmotor(lm.b8);
  }else{
    tf = t;
  }
}

