#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
// --7セグ　A~F
int number[17] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f, 0x77, 0x7f, 0x39, 0x3f, 0x79, 0x71};
int value = 0;
void setup() {
  config_init();
  serial_init();
}

ISR(TIMER3_COMPA_vect){
  sTime++;
}
void loop() {  
  if(sTime > 500){
    disp(number[value/16],number[value%16]);
    sTime = 0;
    if (++value > 255) value = 0;
  }
}
