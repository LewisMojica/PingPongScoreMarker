#include <Arduino.h>
#include <EEPROM.h>
#include <CodeBCD.h>
#include <Button.h>
#include <Timer.h>

#include <DriverDisplay.h>
#include <DriverData.h>//funciones que modifican la data
#include <dataSerial.h>//funcion que imprime los datos del juego
#include <StaticConfig.h>//funciones de configutacion de datos de juego en la EEPROM
#include <Animations.h>


#include <struct/jugData.h>
#include <struct/game.h>

#include "definitions/pinConfig.h"
#include "definitions/otherDef.h"


/* SALIDAS BCD PARA LOS DISPLAYS */
CodeBCD display_jug_a[2] = {
  CodeBCD(bcd_jug_a_0A,bcd_jug_a_0B,bcd_jug_a_0C,bcd_jug_a_0D),
  CodeBCD(bcd_jug_a_1A,bcd_jug_a_1B,bcd_jug_a_1C,bcd_jug_a_1D)
};
CodeBCD display_jug_b[2] = {
  CodeBCD(bcd_jug_b_0A,bcd_jug_b_0B,bcd_jug_b_0C,bcd_jug_b_0D),
  CodeBCD(bcd_jug_b_1A,bcd_jug_b_1B,bcd_jug_b_1C,bcd_jug_b_1D)
};

/* SALIDAS BCD PARA EL DISPLY DEL SET*/
CodeBCD display_set(bcd_set_A,bcd_set_B,bcd_set_C,bcd_set_D);


/*INSTANCIACIONES DE LOS BOTONES*/
Button buton[6] = {Button(button0,antibounce_delay,Button::FLOATING),
                    Button(button1,antibounce_delay,Button::FLOATING),
                    Button(button2,antibounce_delay,Button::FLOATING),
                    Button(button3,antibounce_delay,Button::FLOATING),
                    Button(button4,antibounce_delay,Button::FLOATING),
                    Button(button5,antibounce_delay,Button::FLOATING)};

/*Instanciaciones de la estructura player_data*/
jugData jug_A;
jugData jug_B;

/*Instanciaciones de la estructura player_data*/
game game_data;

/*Instanciaciones de Timer*/
Timer timeWin(750); //para las funciondes de jug_winGame




void setup() {

  /*Asignación de game_data a partir de los valores de la EEPROM*/
  game_data.min_diff = EEPROM.read(0);
  game_data.win_set  = EEPROM.read(1);
  game_data.min_punt = EEPROM.read(2);
  game_data.KO = EEPROM.read(3);

  Serial.begin(19200);

  /* PIN CONFIGURATION */
  pinMode(buzzer,OUTPUT);

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
