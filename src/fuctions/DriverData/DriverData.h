void jug_A_winPoint();
void jug_A_losePoint();
void jug_A_winSet();
void jug_A_winGame();

void jug_B_losePoint();
void jug_B_losePoint();
void jug_B_winSet();
void jug_B_winGame();

void resetAll();
void resetPunt();
void winSet();

void jug_A_winPoint(){
    jug_A.punt++;
}

void jug_A_losePoint(){
    jug_A.punt--;
}

void jug_B_winPoint(){
  jug_B.punt++;
}

void jug_B_losePoint(){
  jug_B.punt--;
}

void jug_A_winGame(){
  resetAll();
  timeWin.initOn();
  byte i = 0;
  while (i != 5){
    if (timeWin.read() == 1){
      Serial.println("Jugador A gana el partido!");
      i++;
    }
  }
}

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
void jug_B_winGame(){
  resetAll();
  timeWin.initOn();
  byte i = 0;
  while (i != 5){
    if (timeWin.read() == 1){
      Serial.println("Jugador B gana el partido!");
      i++;
    }
  }
}

void jug_B_winSet(){
  if (jug_B.win_set == game_data.win_set - 1){
    jug_B_winGame();
  }
  else{
    set++;
    jug_B.win_set++;
    resetPunt();
    byte i;
    timeWin.initOn();
    while (i != 5){
      if (timeWin.read() == 1){
        Serial.println("Jugador B gana el set");
        i++;
      }
    }
  }
}

void winSet(){
  if (((jug_A.punt >= game_data.min_punt || jug_B.punt >= game_data.min_punt)) || (jug_A.punt == game_data.KO && jug_B.punt == 0) || (jug_B.punt == game_data.KO && jug_A.punt == 0) ){
    if(jug_A.punt - jug_B.punt >= game_data.min_diff){
      jug_A_winSet();
    }
    if(jug_B.punt - jug_A.punt >= game_data.min_diff){
      jug_B_winSet();
    }
  }
}

void resetPunt(){
  jug_B.punt = 0;
  jug_A.punt = 0;
}

void resetAll(){
  jug_A.punt = 0;
  jug_A.win_set = 0;
  jug_B.punt = 0;
  jug_B.win_set = 0;
  set = 1;
}
