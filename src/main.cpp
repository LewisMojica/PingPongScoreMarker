#include <Arduino.h>

#include <Timer.h>

#define led 13
#define button 7
#define but2 2

bool push_botton_falling(byte pin);
bool push_botton_rissing(byte pin);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(but2, INPUT_PULLUP);
}



void loop() {
  if (push_botton_falling(button) == 1){
    Serial.println("pulsado");
    digitalWrite(led,!digitalRead(led));
  }
  if (push_botton_rissing(but2)==1){
    Serial.println("bot2puldsadpamdf");
  }
}


bool push_botton_falling(byte pin) {
  static bool est_ant;
  bool pulsado;

  if ((digitalRead(pin) == 0) && (est_ant == 1)) {
    pulsado = 1;
    est_ant = 0;
  }
  else {
    pulsado = 0;
    est_ant = digitalRead(pin);
  }
  delay(50);
  return pulsado;

}

bool push_botton_rissing(byte pin) {
  static bool est_ant;
  bool pulsado;

  if ((digitalRead(pin) == 1) && (est_ant == 0)) {
    pulsado = 1;
    est_ant = 1;
  }
  else {
    pulsado = 0;
    est_ant = digitalRead(pin);
  }
  delay(50);
  return pulsado;

}
