#include "mono_con.h"
unsigned long tf;
int value = 0;
boolean up_down = true;
int ledPara[] = { B000, B001, B010, B100, B011, B110, B101, B111 }; 
void setup() {
  config_init();
  tf = millis(); 
}

void loop() {
  unsigned long t = millis();
  if(t - tf < 1000){
    lm.color.GBR = ledPara[value];
    led_stepmotor(lm.b8);
  }else{
    if(up_down){
      value++;
      if(value > 7){
        up_down = false;
      }
    }else{
      value--;
    }
    if(value <= 0){
      up_down = true;
    }
    tf = t;
  }

}

