#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime,time;
bool tcsw = false;
bool tsw = false;
bool sw = false;
bool prev_sw =false;
int value = 0;
int index = 0;
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
  prev_sw = sw;
  sw = tcsw;
  if(tsw = HIGH){
    value = 1;
  }else if(tsw = LOW){
    value = 0;
  }
  
  switch(value){
  case 0:
    if(index < 120){
      if(time > 20){
        time = 0;
        lm.bit.SM = stepm_init(ex);
        led_stepmotor(lm.b8);
        ex++;
        index++;
        if(ex > 3) ex = 0;
      }
    }  
  case 1:
    if(index < 120){
      if(time > 20){
        time = 0;
        lm.bit.SM = stepm_init(ex);
        led_stepmotor(lm.b8);
        ex--;
        index++;
        if(ex < 0) ex = 3;
      }
    }
  }
/*  prev_sw = sw;
  sw = tsw;
  if(type == 0 && ){
    if(){
      if(index < 120){
        if(time > 20){
          time = 0;
          lm.bit.SM = stepm_init(ex);
          led_stepmotor(lm.b8);
          ex++;
          index++;
          if(ex > 3) ex = 0;
        }
      }
    }else if(tsw == HIGH){
      if(index < 120){
        if(time > 20){
          time = 0;
          lm.bit.SM = stepm_init(ex);
          led_stepmotor(lm.b8);
          ex--;
          index++;
          if(ex < 0) ex = 3;
        }
      }
    }
  }else if(type == 1 && ){
    
  }
  if(sw == LOW && prev_sw == HIGH){
    index = 0;
    type = 1;
  }else if(sw == HIGH && prev_sw == LOW){
    index = 0;
    type = 0;
  }
*/
}