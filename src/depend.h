#include<Arduino.h>
#include<Timer.h>
/*OBJETOS DE LA CLASE*/
Timer bot(2000);

/*DEFINICIONES*/
#define led 13

/*DECLARACIONES DE FUNCIONES*/
bool pushLong(byte pin);
bool pushRef1(byte pin);

/*DECLARACIONES DE VARIABLE*/
bool push;
