#include <Arduino.h>
#include "Timer.h"

Timer::Timer(unsigned long interval)
{
  _interval=interval;
}

bool Timer::read()
{
  bool result;
  if((millis() - _pre_millis) >= (_interval)){
    result=1;
	_pre_millis=millis();
  }
  else {result=0;}
  return result;
}

bool Timer::check()
{
  bool result;
  if((millis() - _pre_millis) >= (_interval)){
    result=1;
  }
  else {result=0;}
  return result;
}

void Timer::reset()
{
  _pre_millis=millis();
}
