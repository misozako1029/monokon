#USE_TIMER3_ISR
#include "mono_con.h"
bool ptit = false;
bool now_ptit = false;
bool prev_ptit = false;
bool tcsw = false;
bool prev_sw = false;
bool sw = false;
word sTime;
void setup() {
  config_init();
  serial_init();
  ptit = digitalRead(17);
  tcsw = digitalRead(18);
  disp(num[10],num[10]);
}
ISR(TIMER3_COMPA_vect){
  if(sTime > 5){
    sTime = 0;
    tcsw = digitalRead(18);
    ptit = digitalRead(17);
  }
  sTime++;
}
void DMcw(int speed){
  analogWrite(FIN_PIN,speed);
  digitalWrite(RIN_PIN,LOW);
}

void DMccw(int speed){
  digitalWrite(FIN_PIN,LOW);
  analogWrite(RIN_PIN,speed);
}
void loop() {
  prev_ptit = now_ptit;
  now_ptit = ptit;
  prev_sw = sw;
  sw = tcsw;
  if(prev_ptit == HIGH && now_ptit == LOW){
    disp(seg[])
  }
}
