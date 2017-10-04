#ifndef Button_h
#define Button_h
#include <Arduino.h>

class Button
{
private:
  byte _pin;
  byte _anti_bounce;
  bool est_ant;
public:
  Button(byte pin, byte anti_bounce);
  bool falling();
  bool rissing();
  bool check();
};
#endif
