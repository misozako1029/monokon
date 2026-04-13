#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime,time;
bool tcsw = false;
bool prev_sw = false;
bool sw = false;
bool check = false;
int ex;
int click = 0;


void setup() {
  config_init();
  serial_init();
  tcsw = digitalRead(18);
}

ISR(TIMER3_COMPA_vect){
  if(sTime > 5){
    sTime = 0;
    tcsw = digitalRead(18);
  }  
  sTime++;
  time++;
}

void loop() {
  prev_sw = sw;
  sw = tcsw;
  if(sw == LOW && prev_sw == HIGH){
    if(click == 0){
      click = 1;
    }else{
      click = 0;
    }
  }
  if(click == 1){
    if(time > 30){
      lm.bit.SM = stepm_init(ex);
      led_stepmotor(lm.b8);
      ex++;
      time = 0;
      if(ex > 3) ex = 0;
    }
  }else{
    lm.bit.SM = stepm_init(4);
    led_stepmotor(lm.b8);
  }
}
