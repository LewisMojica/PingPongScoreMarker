#include<Arduino.h>
#include<Button.h>
/*OBJETOS DE LA CLASE*/
Button l(7,20);
/*DEFINICIONES*/
#define led 13

/*DECLARACIONES DE FUNCIONES*/

/*DECLARACIONES DE VARIABLE*/

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(7, INPUT_PULLUP);
}

void loop(){
  if (l.large(1000) == 1){
    digitalWrite(led, !digitalRead(led));
    Serial.println("Dentro del if");
  }
}
