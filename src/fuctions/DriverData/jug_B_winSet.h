void jug_B_winSet(){
  if (jug_B.win_set == game_data.win_set - 1){
    jug_B_winGame();
  }
  else{
    set++;
    jug_B.win_set++;
    resetPunt();
  }
}
