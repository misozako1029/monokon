#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime,cnt;
int ex = 0;
int value = 100;
void setup() {
  config_init();
  serial_init();
}

ISR(TIMER3_COMPA_vect){
  sTime++;
  cnt++;
}

void loop() {
  if(cnt > value){
    if(sTime < 5000){
      lm.bit.SM = stepm_init(ex);
      led_stepmotor(lm.b8);
      ex++;
      if (ex > 3) ex = 0;
    }else if(sTime > 5000 && sTime < 10000){
      lm.bit.SM = stepm_init(4);
      led_stepmotor(lm.b8);
    }else if(sTime > 10000){
      lm.bit.SM = stepm_init(ex);
      led_stepmotor(lm.b8);
      ex--;
      if(ex < 0) ex = 3;
    } 
    if(sTime > 15000) sTime = 0;
    cnt=0;
  }
}
  
