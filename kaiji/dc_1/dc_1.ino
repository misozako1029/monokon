#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
void setup() {
  config_init();
  serial_init();

}
ISR(TIMER3_COMPA_vect){
  if(sTime > 15000){
    sTime = 0;
  }
  sTime++;
}

void DMstop(void) {
  digitalWrite(FIN_PIN, HIGH);
  digitalWrite(RIN_PIN, HIGH);
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
  if(sTime < 5000){
    DMcw(100);
  }else if(sTime > 10000){
    DMccw(100);
  }else{
    DMstop();
  }
}
