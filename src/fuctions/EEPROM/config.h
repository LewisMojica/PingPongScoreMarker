void config() {
  bool quit;
  while(quit == 0){
    if (Serial.available() != 0){
      switch (Serial.read()) {
        case 'q':
          quit = 1;
      }
    }
  }
}
