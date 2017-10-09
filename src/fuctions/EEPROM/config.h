void config() {
  bool quit;
  while(quit == 0){
    if (Serial.available() != 0){
      switch (Serial.read()) {
        case 'q':
          quit = 1;
          break;
        case 'p':
          break;
        case 'd':
          break;
        case 's':
          break;
        default:
          Serial.println("estás en el modo configuración, para salir pulsa <q>");
          break;
      }
    }
  }
}
