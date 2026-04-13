#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime = 0;
boolean tsw = false;
boolean tcsw = false;
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
}

void DMcw(int speed) {
  analogWrite(FIN_PIN, speed);
  digitalWrite(RIN_PIN, LOW);
}

void DMccw(int speed) {
  digitalWrite(FIN_PIN, LOW);
  analogWrite(RIN_PIN, speed);
}

void loop() {
  if(tsw == LOW && tcsw == LOW){
    DMcw(100);
  }else if(tsw == HIGH && tcsw == LOW){
    DMccw(100);
  }
}
