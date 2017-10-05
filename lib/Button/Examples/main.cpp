#include <Arduino.h>
#include <Button.h>
/*OBJETOS DE LA CLASE*/
Button l(7,20);
/*DEFINICIONES*/
#define led 13

/*DECLARACIONES DE FUNCIONES*/

/*DECLARACIONES DE VARIABLE*/

void setup(){
  pinMode(led, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}

void loop(){
  if (l.read() == 1){
    digitalWrite(led, !digitalRead(led));
  }
}
