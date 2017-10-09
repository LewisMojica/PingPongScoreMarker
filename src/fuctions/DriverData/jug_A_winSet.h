void jug_A_winSet(){
  if (jug_A.win_set == game_data.win_set - 1){
    jug_A_winGame();
  }
  else{
    set++;
    jug_A.win_set++;
    resetPunt();
    byte i;
    timeWin.initOn();
    while (i != 5){
      if (timeWin.read() == 1){
        Serial.println("Jugador A gana el set");
        i++;
      }
    }
  }
}
