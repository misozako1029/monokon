#define USE_TIMER3_ISR
#include "mono_con.h"
int a = 8;
int b = 8;
int key = 1;
word sTime;
void setup(void) {
  config_init();
}

ISR(TIMER3_COMPA_vect){
  sTime++;
}



void loop() {
  if (sTime > 500) {
    sTime = 0;
    if(key == 1){
      a = 8;
      b = 8;
      disp(num[a],num[b]);
    }else{
      a = 10;
      b = 10;
      disp(num[a],num[b]);
    }
    if(key == 1){
      key = 2;
    }else{
      key = 1;
    }
  }

  
}