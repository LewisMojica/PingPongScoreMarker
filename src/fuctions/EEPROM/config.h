void config() {
  Serial.println("Estás en el modo configuración, para salir pulsa <q>");
  bool quit;
  while(quit == 0){
    if (Serial.available() != 0){
      switch (Serial.read()) {
        case 'q':
          quit = 1;
          break;
        // case 'p':
        //   break;
        case 'd':
          configMinDiff();
          break;
        case 's':
        configWinSet();
          break;
        default:
          Serial.println("Estás en el modo configuración, para salir pulsa <q>");
          break;
      }
    }
  }
}
