#define USE_TIMER3_ISR
#include "mono_con.h"
bool tcsw = false;
bool tsw = false;
word sTime,time;
int ex;
void setup() {
  config_init();
  serial_init();
  tcsw = digitalRead(18);
  tsw = digitalRead(19);
}

ISR(TIMER3_COMPA_vect){
  if(sTime > 5){
    sTime = 0;
    tcsw = digitalRead(18);
    tsw = digitalRead(19);
  }
  sTime++;
  time++;
}

void loop() {
  if(tcsw == LOW){
    if(tsw == LOW){
      if(time > 30){
        time = 0;
        lm.bit.SM = stepm_init(ex);
        led_stepmotor(lm.b8);
        ex++;
        if(ex > 3) ex = 0;
      }
    }else if(tsw == HIGH){
      if(time > 30){
        time = 0;
        lm.bit.SM = stepm_init(ex);
        led_stepmotor(lm.b8);
        ex--;
        if(ex < 0) ex = 3;
      }
    }
  }
}
