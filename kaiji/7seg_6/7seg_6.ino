#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
int value = 0;
int type = 10;
void setup() {
  config_init();
  serial_init();
}
ISR(TIMER3_COMPA_vect){
  sTime++;
}
void loop() {
  if(sTime > 1000){
    disp(num[type],num[value]);
    value++;
    if(value > 9){
      value = 0;
    }
    if(value == 0){
      type = 10;
    }else if(value%2 == 0){
      type = 1;
    }else{
      type = 2;
    }
    sTime = 0;
  }
}
