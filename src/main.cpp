#include <Arduino.h>

#include <Timer.h>

#define led 13
#define button 7

bool push_botton(byte i);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}



void loop() {
  if (push_botton(button) == 1){
    Serial.println("pulsado");
    digitalWrite(led,!digitalRead(led));
  }
}


bool push_botton(byte pin) {
  static bool est_ant;
  bool pulsado;

  if ((digitalRead(pin) == 0) && (est_ant == 1)) {
    pulsado = 1;
    est_ant = 0;
  }
  else {
    pulsado = 0;
  }
  est_ant = digitalRead(pin);
  delay(50);
  return pulsado;

}
