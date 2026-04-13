#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
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
    if(sTime > 70){
      lm.bit.SM = stepm_init(ex);
      led_stepmotor(lm.b8);
      ex++;
      index++;
      if (ex > 3) ex = 0;
      sTime = 0;
    }
  }
}
