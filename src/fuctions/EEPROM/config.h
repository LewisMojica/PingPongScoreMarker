void config() {
  Serial.println("Estás en el modo configuración, para salir pulsa <q>");
  bool quitConfig = 0;
  while(quitConfig == 0){
    if (Serial.available() > 0){
      switch (Serial.read()) {
        case 'q':
          quitConfig = 1;
          break;
        // case 'p':
        //   break;
        case 'd':
          configMinDiff();
          break;
        case 's':
        configWinSet();
          break;
        default:
          Serial.println("Estás en el modo configuración, para salir pulsa <q>");
          break;
      }
    }
  }
  Serial.println("Ha salido del modo configuración hacia el modo juego");
}
/*
<q> -> para salir de la configuración
<d> -> para entrar a la configuración de la diferencia mínima
<s> -> para entrar a la configuración de los set que hay que ganar para ganar el partido

*/
