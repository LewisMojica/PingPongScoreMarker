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

#include "fuctions/DriverData.h"//funciones que modifican la data
void printData(){
  Serial.print("punt. de jug. A = ");
  Serial.println(jug_A_punt);
  Serial.print("punt. de jug. B = ");
  Serial.println(jug_B_punt);
}
