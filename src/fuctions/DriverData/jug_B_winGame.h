void jug_B_winGame(){
  resetAll();
  timeWin.init();
  byte i = 0;
  while (i != 5){
    if (timeWin.read() == 1){
      Serial.println("Jugador B gana el partido!");
      i++;
    }
  }
  timeWin.end();
}
