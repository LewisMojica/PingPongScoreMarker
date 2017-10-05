#include <Arduino.h>
#include <CodeBCD.h>
//
// #include <Timer.h>
CodeBCD bcd(8,9,10,11);
// Timer l(1250);
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() != 0){
    switch (Serial.read()) {
      case '0':
        bcd.write(0);
        Serial.println("Se ha escrito <0>");
      break;

      case '1':
        bcd.write(1);
        Serial.println("Se ha escrito <1>");
      break;

      case '2':
        bcd.write(2);
        Serial.println("Se ha escrito <2>");
      break;

      case '3':
        bcd.write(3);
        Serial.println("Se ha escrito <3>");
      break;

      case '4':
        bcd.write(4);
        Serial.println("Se ha escrito <4>");
      break;

      case '5':
        bcd.write(5);
        Serial.println("Se ha escrito <5>");
      break;

      case '6':
        bcd.write(6);
        Serial.println("Se ha escrito <6>");
      break;

      case '7':
        bcd.write(7);
        Serial.println("Se ha escrito <7>");
      break;

      case '8':
        bcd.write(8);
        Serial.println("Se ha escrito <8>");
      break;

      case '9':
        bcd.write(9);
      break;
      Serial.println("Se ha escrito <9>");

      default:
        Serial.println("Solo se pueden escribir números entre 0 y 9");
      break;
    }
  }
}
