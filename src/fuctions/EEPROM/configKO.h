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
