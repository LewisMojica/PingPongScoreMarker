#include <Arduino.h>
#include "Timer.h"

Timer::Timer(unsigned long interval){
  _interval=interval;
}

bool Timer::read(){
  bool result;
  if(((millis() - _pre_millis) >= _interval) && _init==1){
    result=1;
	_pre_millis=millis();
  }
  else {
    result=0;
  }
  return result;
}

bool Timer::check(){
  bool result;
  if(((millis() - _pre_millis) >= _interval) && _init==1){
    result=1;
  }
  else {
    result=0;
  }
  return result;
}

void Timer::reset(){
  _pre_millis=millis();
}

void Timer::init(){
  _init=1;
  reset();
}

void Timer::initOn(){
  _init=1;
  _pre_millis=millis() + _interval;
}

void Timer::end(){
  _init=0;
}
