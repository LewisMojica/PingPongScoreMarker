#include <depend.h>

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
}



void loop() {
  if (pushLong(7) == 1){
    digitalWrite(led, !digitalRead(led));
    Serial.println("long!");
  }
}


bool pushLong(byte pin){
  if (push == 1){
    return pushRef1(pin);
  }
  else{
    if (!digitalRead(pin) == 1){
      bot.init();
      return pushRef1(pin);
    }
  }
}

bool pushRef1(byte pin){
  if (!digitalRead(pin) == 1){
    push = 1;
    if (bot.check() == 1){
      bot.end();
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    push = 0;
    bot.end();
    return 0;
  }
}
