#include "mono_con.h"
int ledPara[] = { B000, B001, B010, B100, B011, B110, B101, B111 }; 
void setup() {
  config_init();
}

void loop() {
  lm.color.GBR = ledPara[2];
  led_stepmotor(lm.b8);
}

