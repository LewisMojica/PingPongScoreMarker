#ifndef Timer_h
#define Timer_h
#include <Arduino.h>

class Button
{
private:
  byte _pin;
  bool est_ant;
public:
  Button(byte pin);
  bool falling();
  bool rissing();
};
#endif
