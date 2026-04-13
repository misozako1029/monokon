#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime = 0;
int ex = 0;
int index = 0;
void setup() {
  config_init();
  serial_init();
}

ISR(TIMER3_COMPA_vect){
  sTime++;
}

void loop() {
  if(index < 120){
    if(sTime > 30){
      lm.bit.SM = stepm_init(ex);
      led_stepmotor(lm.b8);
      index++;
      if(60 < index && index <= 120){
        ex--;
        if (ex < 0) ex = 3;
      }else{
        ex++;
        if (ex > 3) ex = 0;
        
      }
      sTime = 0;
    }
  }else{
    index = 0;
  }
  
}
