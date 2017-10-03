#ifndef Timer_h
#define Timer_h
#include <Arduino.h>

class Timer
{
  private:
  unsigned long _interval;            //intervalo del timer
  unsigned long _pre_millis;          //milllis de referencia
  public:
  Timer(unsigned long interval);      //constructor

  bool read ();                        //fucion que retorna el estado del timer, si devuelve un true entonces el timer se resetea*/

  bool check ();                        //funcion que retorna el tiempo que falta para que activie el timer, pero sin resetearlo en ninguna circunstancia

  void reset ();
};


#endif
