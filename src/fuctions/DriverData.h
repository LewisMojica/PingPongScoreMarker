void jug_A_winPoint(){
    jug_A.punt++;
}

void jug_B_winPoint(){
  jug_B.punt++;
}

void jug_A_losePoint(){
    jug_A.punt--;
}

void jug_B_losePoint(){
  jug_B.punt--;
}

void winSet(){
  if ((jug_A.punt - jug_B.punt > game_data.min_diff) || (jug_B.punt - jug_A.punt > game_data.min_diff)){
    set++;
  }
}

void resetAll(){
  jug_B.punt = 0;
  jug_A.punt = 0;
  set = 1;
}

void resetPunt(){
  jug_B.punt = 0;
  jug_A.punt = 0;
}
