#include <Arduino.h>

#include <Button.h>

#include <Timer.h>
/*Instanciaciones de Timer*/


/*Definiciones*/

/*Declaraciones de variables y constantes*/
//variables
byte jug_A_punt; //almacena el puntaje del jugador A
byte jug_B_punt; //almacena el puntaje del jugador B

//constantes

/*Declaraciones de funciones*/
//void
void jug_A_Win_Point();
void jug_B_Win_Point();
void resetAll();
void resetPunt();
void printData();
