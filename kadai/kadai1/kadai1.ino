#define USE_TIMER3_ISR
#include "mono_con.h"
word sTime;
#define hi 1320 - 200
bool tcsw = false;
bool prev_sw = false;
bool sw = false;
bool key = false;
bool click = false;
int seg[] = {0x00, 0x08, 0x40, 0x01};
int y;
int type = 3;
int check;
void setup() {
  config_init();
  serial_init();
  tcsw = digitalRead(18);
  y = analogRead(A2);
}

int stick(int y){
  if(y < hi){
    type = 1;
  }else if(y > hi){
    type = 2;
  }else{
    type = 3;
  }
}

ISR(TIMER3_COMPA_vect){
  if(sTime > 5){
    sTime = 0;
    tcsw = digitalRead(18);
    y = analogRead(A2);
  }
  sTime++;
}
void loop() {
  prev_sw = sw;
  sw = tcsw;
  stick(y);
  if(type == 1 && key == true){
    key = false;
    disp(seg[0],seg[2]);
  }else if(type == 2){
    key = false;
    disp(seg[0],seg[3]);
  }else if(type == 3 && key == false){
    key = true;
    disp(seg[0],seg[0]);
  }
  if(prev_sw == LOW && sw == HIGH){
    if(click == true){
      click = false;
    }else{
      click = true;
    }
  
    if(click == true && check == 0){
      check = 1;
      disp(seg[0],seg[1]);
    }else if(click == false && check == 1){
      check = 0;
      disp(seg[0],seg[0]);
    }

  }
}
