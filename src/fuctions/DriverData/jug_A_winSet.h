void jug_A_winSet(){
  if (jug_A.win_set == game_data.win_set - 1){
    jug_A_winGame();
  }
  else{
    set++;
    jug_A.win_set++;
    resetPunt();
  }
}
