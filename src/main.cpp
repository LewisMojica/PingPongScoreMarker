#include <Arduino.h>
#include <EEPROM.h>

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
#include <fuctions/EEPROM/EEPROM.h>//funciones de configutacion de datos de juego en la EEPROM

void setup() {

  /*Asignación de game_data a partir de los valores de la EEPROM*/
  game_data.min_diff = EEPROM.read(0);
  game_data.win_set  = EEPROM.read(1);
  game_data.min_punt = EEPROM.read(2);
  game_data.KO = EEPROM.read(3);

  Serial.begin(19200);
}



void loop() {
  if (Serial.available () > 0) {
    switch (Serial.read()) {                    //4 = + jug. a 5 = set   6 = + jug. b
      case 'w':                                 //1 = - jug. a 2 = reset 3 = - jug. b
      if (jug_A.punt != 255){
        Serial.println("+ 1 al jugador a");
        jug_A_winPoint();
      }
      else {
        Serial.println("El puntaje no puede ser mayor que 255");
      }
      printData();
      break;

      case 'e':
      Serial.println("set");
      winSet();
      printData();
      break;

      case 'r':
      if (jug_B.punt != 255){
        Serial.println("+ 1 al jugador b");
        jug_B_winPoint();
      }
      else {
        Serial.println("El puntaje no puede ser mayor que 255");
      }
      printData();
      break;

      case 's':
      if (jug_A.punt != 0){
        Serial.println("-1 al jugador a");
        jug_A_losePoint();
      }
      else{
        Serial.println("El puntaje no puede ser menor que 0");
      }
      printData();
      break;

      case 'd':
      Serial.println("reset");
      resetAll();
      printData();
      break;

      case 'f':
      if (jug_B.punt != 0){
        Serial.println("-1 al jugador b");
        jug_B_losePoint();
      }
      else{
        Serial.println("El puntaje no puede ser menor que 0");
      }
      printData();
      break;

      case 'p':
      printData();
      break;

      case 'g':
      pintDataGame();
      break;

      case 'c':
      config();
      break;

      default:
      Serial.println("caracter inválido -__- presiona la <p> para imprimir los datos :D");
      break;
    }
  }
}
