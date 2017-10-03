#include <Arduino.h>

#include <Timer.h>
Timer l(1250);
Timer bl(50);

#define led 13
#define on 4
#define tim_blink on*2 //numero par

void caracterVoid();
void blink();

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}



void loop() {
  caracterVoid();
  blink();
}


void caracterVoid() {
  if (Serial.available () !=0) {
    bool inval_caract = 1;
    switch (Serial.read()) {                    //4 = + jug. a 5 = set   6 = + jug. b
      case '4':                                 //1 = - jug. a 2 = reset 3 = - jug. b
      Serial.println("+ 1 al jugador a");
      inval_caract = 0;
      break;
      case '5':
      Serial.println("set");
      inval_caract = 0;
      break;
      case '6':
      Serial.println("+ 1 al jugador b");
      inval_caract = 0;
      break;
      case '1':
      Serial.println("-1 al jugador a");
      inval_caract = 0;
      break;
      case '2':
      Serial.println("reset");
      inval_caract = 0;
      break;
      case '3':
      Serial.println("-1 al jugador b");
      inval_caract = 0;
      break;
    }
    if (inval_caract == 1){
      Serial.println("caracter inválido -_-");
    }
  }
}

void blink(){
  if (l.check() == 1){
    static byte time;
    if (bl.read()==1){
      digitalWrite(led, !digitalRead(led));
      time++;
    }
    if (time >= tim_blink) {
      l.reset();
      time = 0;
    }
  }
}
