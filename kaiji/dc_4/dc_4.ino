#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
int value = 10;
boolean updown = true;
void setup() {
  config_init();
  serial_init();

}
ISR(TIMER3_COMPA_vect){
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
  if(sTime > 5000){
    if(updown){
      value = value + 10;
      DMcw(value);
    }else{
      value = value - 10;
      DMcw(value);
    }
    if(value == 100){
      updown = false;
    }else if(value == 0){
      updown = true;
    }
    sTime = 0;
  }
}
