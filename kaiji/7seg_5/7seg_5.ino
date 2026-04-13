#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
boolean updown = true;
int value = 0;
void setup() {
  config_init();
  serial_init();
}

ISR(TIMER3_COMPA_vect){
  sTime++;
}

void loop() {
/*
value ... 0 ~ 99
a ... value / 10
b ... value % 10
*/
  if(sTime > 200){
    disp(num[value/10],num[value%10]);
    if(updown){
      value++;
      if(value >= 99){
        updown = false;
      }    
    }else{
      value--;
    }
    if(value < 0){
      updown = true;
    }
    sTime = 0;
  }
}
