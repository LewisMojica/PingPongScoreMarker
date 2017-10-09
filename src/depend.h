#include <Arduino.h>

#include <Button.h>

#include <struct/jugData.h>
/*Instanciaciones de la estructura player_data*/
player_data jug_A;
player_data jug_B;

#include <struct/game.h>
/*Instanciaciones de la estructura player_data*/
game game_data;

#include <Timer.h>
/*Instanciaciones de Timer*/
Timer timeWin(750); //para las funciondes de jug_winGame

/*Definiciones*/
byte set = 1;  //set actual
///////////////////////////

#include <fuctions/DriverData/DriverData.h>//funciones que modifican la data
#include <fuctions/dataSerial.h>//funcion que imprime los datos del juego
#include <fuctions/EEPROM.h>//funciones de configutacion de datos de juego en la EEPROM
