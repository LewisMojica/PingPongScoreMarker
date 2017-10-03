#include <Arduino.h>

#include <Timer.h>
Timer l(1250);
Timer bl(50);
Timer pr(500);

#define led 13
#define button 7
#define on 4
#define tim_blink on*2 //numero par

void blink();

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}



void loop() {

  blink();
  if (pr.read()==1){
    Serial.println(digitalRead(button));
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
