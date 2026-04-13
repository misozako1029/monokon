#define USE_TIMER3_ISR
#include "mono_con.h"
word time,ctime;
int index = 0;
int dir = 1;
int ex = 0;
int speed[10] = {100,90,80,70,60,50,40,30,20,10};
void setup(){
  config_init();
  serial_init();
}

ISR(TIMER3_COMPA_vect){
  ctime++;
  time++;
}

void loop(){
  if(ctime > 5000){
      ctime = 0;
//    if(index >= 9 || index <= 0){
//      dir = -dir;
//    }
      if(index >= 9) dir = -1;
      if(index <= 0) dir = 1;
      index += dir;
  }
  if(time > speed[index]){
    time = 0;
    lm.bit.SM = stepm_init(ex);
    led_stepmotor(lm.b8);
    ex++;
    if (ex > 3) ex = 0;
  }
  
}