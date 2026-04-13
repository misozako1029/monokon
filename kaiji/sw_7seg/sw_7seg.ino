#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
bool tcsw = false;
int type = 0;
void setup() {
  config_init();
  serial_init();
}

ISR(TIMER3_COMPA_vect){
  sTime++;
}

void loop() {
  prev_sw = sw;
  sw =tcsw;
  if(prev_sw == HIGH && sw == LOW){
    if(type == 0){
      type = 1;
    }else if(type == 1){
      type = 0;
    }
  }
  if(type =)
}
