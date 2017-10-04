#include <Arduino.h>
#include "Button.h"

Button::Button(byte pin, byte anti_bounce) {
  _pin=pin;
  _anti_bounce=anti_bounce;
}

  bool Button::rissing() {                                          //Funcion que retorna un 1 cuando se detecta un rissing en el pin <_pin>
  bool puls;
  if ((digitalRead(_pin) == 1) && (_est_ant == 0)) {
    puls = 1;
    _est_ant = 1;
  }
  else {
    puls = 0;
    _est_ant = digitalRead(_pin);
  }
  delay(_anti_bounce);
  return puls;
}

bool Button::falling() {                                          //Funcion que retorna un 1 cuando se detecta un falling en el pin <_pin>
  bool puls;
  if ((digitalRead(_pin) == 0) && (_est_ant == 1)) {
    puls = 1;
    _est_ant = 0;
  }
  else {
    puls = 0;
    _est_ant = digitalRead(_pin);
  }
  delay(_anti_bounce);
  return puls;
}

bool Button::check(){                                             //Funcion que retorna el estado actual del pin <_pin>
  return digitalRead(_pin);
}
/*inicio de funciones de timer*/
void Button::init(){
_init=1;
_pre_millis=millis();
}

void Button::end(){
  _init=0;
}

bool Button::visit(unsigned long _interval){
  bool result;
  if(((millis() - _pre_millis) >= _interval) && _init==1){
    result=1;
  }
  else {
    result=0;
  }
  return result;
}
/*fin de funciones de timer*/


bool Button::large(unsigned long _interval){                            //Esta funcion retorna 1 cuando el boton fue preconado por mas de un tiempo determinado por la variable timer, cuando retorna 1 el boton debe dejae de ser pulsado para poder retornar otro 1
  if (_push == 1){
    return pushRef1(_interval);
  }
  else{
    if (!digitalRead(_pin) == 1){
      init();
      return pushRef1(_interval);
    }
  }
}

bool Button::pushRef1(unsigned long _interval){                                 //esta subfuncion la utiliza la funcion longPush varias veces
  if (!digitalRead(_pin) == 1){
    _push = 1;
    if (visit(_interval) == 1){
      end();
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    _push = 0;
    end();
    return 0;
  }
}
