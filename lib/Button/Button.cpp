#include <Arduino.h>
#include "Button.h"

Button::Button(byte pin, byte anti_bounce) {
  _pin=pin;
  _anti_bounce=anti_bounce;
}

  bool Button::rissing() {                                          //Funcion que retorna un 1 cuando se detecta un rissing en el pin <_pin>
  bool puls;
  if ((digitalRead(_pin) == 1) && (est_ant == 0)) {
    puls = 1;
    est_ant = 1;
  }
  else {
    puls = 0;
    est_ant = digitalRead(_pin);
  }
  delay(_anti_bounce);
  return puls;
}

bool Button::falling() {                                          //Funcion que retorna un 1 cuando se detecta un falling en el pin <_pin>
  bool puls;
  if ((digitalRead(_pin) == 0) && (est_ant == 1)) {
    puls = 1;
    est_ant = 0;
  }
  else {
    puls = 0;
    est_ant = digitalRead(_pin);
  }
  delay(_anti_bounce);
  return puls;
}
bool Button::check(){                                             //Funcion que retorna el estado actual del pin <_pin>
  return digitalRead(_pin);
}
