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

void resetAll(){
  jug_B.punt = 0;
  jug_A.punt = 0;
}

void resetPunt(){
  jug_B.punt = 0;
  jug_A.punt = 0;
}
