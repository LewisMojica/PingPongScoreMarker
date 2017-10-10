void configMinPunt(){
  Serial.println("Está dentro de la configuración de minPunt, pulse <q> para salir hacia el modo configuración");
  bool quit_minPunt = 0;
  while (quit_minPunt == 0) {
    if (Serial.available() > 0){
      if (Serial.peek() == 'q'){
        quit_minPunt = 1;
      }
      else if ((Serial.available() == 2) && (Serial.peek() >= 48 && Serial.peek() <= 57)){
        static byte tmp_num;
        while ((Serial.available() <= 2) && (Serial.available() > 0)) {
          if (Serial.available() == 1){
            tmp_num = (Serial.read() - 48) * 10;
          }
          else if(Serial.available() == 1){
            tmp_num = tmp_num + (Serial.read() - 48);
          }
        }
      }
      else {
        Serial.print("Caracter/es <");
        while (Serial.available() > 0){
          Serial.write(Serial.read());
        }
        Serial.println("> es inválido");
      }
    }
  }
  Serial.println("Ha salido de la configutación de minPunt, pulse <q> para salir del modo configuración");
}
