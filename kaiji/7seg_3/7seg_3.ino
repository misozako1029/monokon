#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
int a = 0;
void setup() {
  config_init();
  serial_init();
}

ISR(TIMER3_COMPA_vect){
  sTime++;
}

void loop() {
  if(sTime > 1000){
    disp(num[a],num[a]);
    a++;
    sTime = 0;
  }
  if(a > 9){
    a = 0;
  }
}
