void jug_A_winSet(){
  if (jug_A.win_set == game_data.win_set - 1){
    resetAll();
  }
  else{
    set++;
    jug_A.win_set++;
    resetPunt();
  }
}
