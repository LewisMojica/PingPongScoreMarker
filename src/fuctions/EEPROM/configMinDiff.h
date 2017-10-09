void configMinDiff(){
  Serial.println("Está dentro de la configutación de minDiff, pulse <q> para salir hacia el modo configuración");
  bool quitMinDiff = 0;
  while (quitMinDiff == 0){
    if (Serial.available() > 0){
      if (Serial.peek() == 'q'){
        Serial.read();
        quitMinDiff = 1;
      }
      else if ((Serial.peek() >= 48) && (Serial.peek() <= 57)){
        Serial.print("Mínima diferencia configurada a ");
        Serial.println(Serial.peek() - 48);
        game_data.min_diff = Serial.read() - 48;
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
