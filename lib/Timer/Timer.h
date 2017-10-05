#ifndef Timer_h
#define Timer_h
#include <Arduino.h>

class Timer
{
  private:
  unsigned long _interval;            //intervalo del timer
  unsigned long _pre_millis;          //milllis de referencia
  bool _init;
  public:
  Timer(unsigned long interval);      //constructor
  void init();                          //funcion que habilita el timer para que retorne un 1 y resetea el timer

  bool check ();                        //funcion que retorna el tiempo que falta para que activie el timer, pero sin resetearlo en ninguna circunstancia

  bool read ();                         //fucion que retorna el estado del timer, si devuelve un true entonces el timer se resetea*/

  void reset ();                        //funcion que comienza la cuenta desde el momento en que se llama

  void end();                           //funcion deshabilita el timer a retornar 1
};


#endif
