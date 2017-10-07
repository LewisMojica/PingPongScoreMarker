#include <depend.h>
void setup() {
  Serial.begin(9600);
}



void loop() {
  if (Serial.available () !=0) {
    switch (Serial.read()) {                    //4 = + jug. a 5 = set   6 = + jug. b
      case '4':                                 //1 = - jug. a 2 = reset 3 = - jug. b
      Serial.println("+ 1 al jugador a");
      jug_A_Win_Pint();
      printData();
      break;

      case '5':
      Serial.println("set");
      printData();
      break;

      case '6':
      Serial.println("+ 1 al jugador b");
      jug_B_Win_Pint();
      printData();
      break;

      case '1':
      Serial.println("-1 al jugador a");
      jug_A_punt--;
      printData();
      break;

      case '2':
      Serial.println("reset");
      printData();
      break;

      case '3':
      Serial.println("-1 al jugador b");
      jug_B_punt--;
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

void jug_A_Win_Pint(){
  jug_A_punt++;
}

void jug_B_Win_Pint(){
  jug_B_punt++;
}

void resetAll(){
  jug_B_punt = 0;
  jug_A_punt = 0;
}

void resetPunt(){
  jug_B_punt = 0;
  jug_A_punt = 0;
}

void printData(){
  Serial.print("punt. de jug. A = ");
  Serial.println(jug_A_punt);
  Serial.print("punt. de jug. B = ");
  Serial.println(jug_B_punt);
}
