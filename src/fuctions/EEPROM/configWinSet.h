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
