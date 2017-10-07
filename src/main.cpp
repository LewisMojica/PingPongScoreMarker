#include <depend.h>
void setup() {
  Serial.begin(9600);
}



void loop() {
  if (Serial.available () !=0) {
    switch (Serial.read()) {                    //4 = + jug. a 5 = set   6 = + jug. b
      case '4':                                 //1 = - jug. a 2 = reset 3 = - jug. b
      if (jug_A_punt != 255){
        Serial.println("+ 1 al jugador a");
        jug_A_Win_Point();
      }
      else {
        Serial.println("El puntaje no puede ser mayor que 255");
      }
      printData();
      break;

      case '5':
      Serial.println("set");
      printData();
      break;

      case '6':
      if (jug_B_punt != 255){
        Serial.println("+ 1 al jugador b");
        jug_B_Win_Point();
      }
      else {
        Serial.println("El puntaje no puede ser mayor que 255");
      }
      printData();
      break;

      case '1':
      if (jug_A_punt != 0){
        Serial.println("-1 al jugador a");
        jug_A_punt--;
      }
      else{
        Serial.println("El puntaje no puede ser menor que 0");
      }
      printData();
      break;

      case '2':
      Serial.println("reset");
      printData();
      break;

      case '3':
      if (jug_B_punt != 0){
        Serial.println("-1 al jugador b");
        jug_B_punt--;
      }
      else{
        Serial.println("El puntaje no puede ser menor que 0");
      }
      printData();
      break;

      case 'r':
      resetAll();
      printData();
      break;

      case 'p':
      printData();
      break;

      default:
      Serial.println("caracter inválido -__- presiona la <p> para imprimir los datos :D");
      break;
    }
  }
}
