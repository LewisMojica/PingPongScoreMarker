void printData(){
                              Serial.print("Jugador A ------ ");                               Serial.print("Set ------ ");                                   Serial.println("Jugador B");
  Serial.print("   ");    Serial.print(jug_A.punt);              Serial.print("              ");  Serial.print(set);               Serial.print("          ");      Serial.println(jug_B.punt);
}

void pintDataGame(){
  Serial.print("min_diff ------ ");                                           Serial.print("win_set ------ ");                                            Serial.print("min_punt ------ ");                                   Serial.println("KO");
  Serial.print("   "); Serial.print(game_data.min_diff);  Serial.print("               "); Serial.print(game_data.win_set); Serial.print("              "); Serial.print(game_data.min_punt);  Serial.print("            "); Serial.println(game_data.KO);
}
