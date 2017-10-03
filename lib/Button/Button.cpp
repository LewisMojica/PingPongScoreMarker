#include <Arduino.h>
#include "Button.h"

Button::Button(byte pin) {
  _pin=pin;
}

  bool Button::rissing() {
  bool puls;
  if ((digitalRead(_pin) == 1) && (est_ant == 0)) {
    puls = 1;
    est_ant = 1;
  }
  else {
    puls = 0;
    est_ant = digitalRead(_pin);
  }
  delay(50);
  return puls;
}

bool Button::falling() {
  bool puls;
  if ((digitalRead(_pin) == 0) && (est_ant == 1)) {
    puls = 1;
    est_ant = 0;
  }
  else {
    puls = 0;
    est_ant = digitalRead(_pin);
  }
  delay(50);
  return puls;
}
