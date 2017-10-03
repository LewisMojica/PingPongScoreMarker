#include <Arduino.h>

// #include <Timer.h>
#include <Button.h>
#define led 13
Button bl(2,10);
Button b(7,10);


bool push_botton_falling(byte pin);
bool push_botton_rissing(byte pin);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
}



void loop() {
  if (bl.falling()==1){
    // digitalWrite(led, !digitalRead(led));
    Serial.println("bl pulsado");
  }
  if (b.falling()==1){
    // digitalWrite(led, !digitalRead(led));
    Serial.println("b pulsado :D");
  }
  digitalWrite(led, !digitalRead(led));
}
