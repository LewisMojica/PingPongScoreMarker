#ifndef Button_h
#define Button_h
#include <Arduino.h>

class Button
{
private:
  byte _pin;
  byte _anti_bounce;
  bool _est_ant;
  bool _push;

  /*inicio de variable de las funciones de timer*/
  bool _init;
  unsigned long _pre_millis;          //milllis de referencia
  /*fin de variable de las funciones de timer*/

  bool pushRef1();                            //esta subfuncion la utiliza la funcion longPush varias veces
  void init();
  void end();
  bool visit(unsigned long _interval);
public:
  Button(byte pin, byte anti_bounce);
  bool falling();
  bool rissing();
  bool check();
  bool Long(unsigned long interval);
};
#endif
