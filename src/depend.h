#include <Arduino.h>

#include <Button.h>

#include <struct/jugData.h>
/*Instanciaciones de la estructura player_data*/
player_data jug_A;
player_data jug_B;

#include <Timer.h>
/*Instanciaciones de Timer*/


/*Definiciones*/
byte set = 1;  //set actual

//constantes

/*Declaraciones de funciones*/
//void
void jug_A_winPoint();
void jug_B_winPoint();
void jug_A_losePoint();
void jug_B_losePoint();
void resetAll();
void resetPunt();
void printData();

#include <fuctions/DriverData.h>//funciones que modifican la data
#include <fuctions/dataSerial.h>//funcion que imprime los datos del juego
