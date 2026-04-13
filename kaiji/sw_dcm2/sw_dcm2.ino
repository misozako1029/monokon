#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime = 0;
boolean tsw = false;
boolean tcsw = false;
//boolean tcswFlag = false;
boolean sw,prev_sw;
int dmPara[] = {25,51,77,102,128,153,179,204,230,255};
int value = 0;
int key;
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

/*int click(void){
  if(tcsw == HIGH){
    tcswFlag = true;
  }
  if(tcsw == LOW && tcswFlag == true){
    tcswFlag = false;
    return(1);
  }
  return (0);
}
*/
void DMcw(int speed) {
  analogWrite(FIN_PIN, speed);
  digitalWrite(RIN_PIN, LOW);
}


void loop() {
  // key = click();
  prev_sw = sw;
  sw = tcsw;
  if(tsw == LOW){
    DMcw(dmPara[value]);
    if(sw == LOW && prev_sw == HIGH){
      value++;
    }
  }
  if(value > 10) value = 0;
}

/*
sw  prev_sw

swを更新する前にprev_sw=swをする
-> sw == LOW && prev_sw == HIGH  ＝＞押した瞬間
*/
