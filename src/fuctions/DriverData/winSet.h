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
