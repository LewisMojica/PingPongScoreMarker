#include <Arduino.h>
#include <fuctions/EEPROM/EEPROM.h>
#include <fuctions/DriverData/DriverData.h>
#include <EEPROM.h>
#include <struct/game.h>

extern struct game game_data;

void config() {
  Serial.println("Estás en el modo configuración, para salir pulsa <q>");
  bool quitConfig = 0;
  while(quitConfig == 0){
    if (Serial.available() > 0){
      switch (Serial.read()) {
        case 'q':
          quitConfig = 1;
          break;
        case 'k':
          configKO();
          break;
        case 'd':
          configMinDiff();
          break;
        case 's':
          configWinSet();
          break;
        case 'p':
          configMinPunt();
        default:
          Serial.println("Estás en el modo configuración, para salir pulsa <q>");
          break;
      }
    }
  }
  Serial.println("Ha salido del modo configuración hacia el modo juego");
}
/*
<q> -> para salir de la configuración
<d> -> para entrar a la configuración de la diferencia mínima
<s> -> para entrar a la configuración de los set que hay que ganar para ganar el partido

*/
void configMinDiff(){
  Serial.println("Está dentro de la configutación de minDiff, pulse <q> para salir hacia el modo configuración");
  bool quit_MinDiff = 0;
  while (quit_MinDiff == 0){
    if (Serial.available() > 0){
      if (Serial.peek() == 'q'){
        Serial.read();
        quit_MinDiff = 1;
      }
      else if ((Serial.peek() >= 48) && (Serial.peek() <= 57)){
        game_data.min_diff = Serial.read() - 48;
        Serial.print("Mínima diferencia configurada a ");
        Serial.println(game_data.min_diff);
        EEPROM.update(0, game_data.min_diff);
        resetAll();
      }
      else {
        Serial.print("El caracter <");
        Serial.write(Serial.read());
        Serial.println("> es inválido");
      }
    }
  }
  Serial.println("Ha salido de la configutación de minDiff, pulse <q> para salir del modo configuración");
}
void configWinSet(){
  Serial.println("Está dentro de la configutación de winSet, pulse <q> para salir hacia el modo configuración");
  bool quit_winSet = 0;
  while (quit_winSet == 0){
    if (Serial.available() > 0){
      if (Serial.peek() == 'q'){
        Serial.read();
        quit_winSet = 1;
      }
      else if ((Serial.peek() >= 48) && (Serial.peek() <= 57)){
        game_data.win_set = Serial.read() - 48;
        Serial.print("Sets para ganar el partido configurado a ");
        Serial.println(game_data.win_set);
        EEPROM.update(1, game_data.win_set);
        resetAll();
      }
      else {
        Serial.print("Caracter/es <");
        while (Serial.available() > 0){
          Serial.write(Serial.read());
          delayMicroseconds(500);
        }
        Serial.println("> es inválido");
      }
    }
  }
  Serial.println("Ha salido de la configutación de winSet, pulse <q> para salir del modo configuración");
}

void configMinPunt(){
  Serial.println("Está dentro de la configuración de minPunt, pulse <q> para salir hacia el modo configuración");
  bool quit_minPunt = 0;
  while (quit_minPunt == 0) {
    if (Serial.available() > 0){
      delay(1);
      if (Serial.peek() == 'q'){
        Serial.read();
        quit_minPunt = 1;
      }
      else if ((Serial.available() == 2) && (Serial.peek() >= 48) && (Serial.peek() <= 57)){
        static byte tmp_num;
        while ((Serial.available() <= 2) && (Serial.available() > 0)) {
          if (Serial.available() == 2){
            tmp_num = (Serial.read() - 48) * 10;
          }
          else if(Serial.available() == 1){
            tmp_num = tmp_num + (Serial.read() - 48);
            game_data.min_punt = tmp_num;
            Serial.print("min_punt configurado a ");
            Serial.println(tmp_num);
            EEPROM.update(2, tmp_num);
            resetAll();
          }
        }
      }
      else {
        Serial.print("Caracter/es <");
        while (Serial.available() > 0){
          Serial.write(Serial.read());
          delayMicroseconds(500);
        }
        Serial.println("> es inválido");
      }
    }
  }
  Serial.println("Ha salido de la configutación de minPunt, pulse <q> para salir del modo configuración");
}

void configKO(){
  Serial.println("Está dentro de la configutación de KO, pulse <q> para salir hacia el modo configuración");
  bool quit_KO = 0;
  while (quit_KO == 0){
    if (Serial.available() > 0){
      if (Serial.peek() == 'q'){
        Serial.read();
        quit_KO = 1;
      }
      else if ((Serial.peek() >= 48) && (Serial.peek() <= 57)){
        game_data.KO = Serial.read() - 48;
        Serial.print("KO configurado a ");
        Serial.println(game_data.KO);
        EEPROM.update(3, game_data.KO);
        resetAll();
      }
      else {
        Serial.print("El caracter <");
        Serial.write(Serial.read());
        Serial.println("> es inválido");
      }
    }
  }
  Serial.println("Ha salido de la configutación de KO, pulse <q> para salir del modo configuración");
}
