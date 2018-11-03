#include <Arduino.h>
#include <Animations.h>

void powerOnAnimation(){
    Serial.println("echo \"insert power animation\" > /dev/null");
}

void winSetAnimation(enum player jug){
    if(jug == jugA){
        //animacion de cuando el jugador a gana el set
        Serial.println("\n\n JUGADOR A GANA EL SET\n\n");
    }
    else{
        //animacion de cuando el jugador b gana el set
        Serial.println("\n\n JUGADOR B GANA EL SET\n\n");
    }
}

void winGameAnimation(enum player jug){
    if(jug == jugA){
        //animacion de cuando el jugador a gana el partido
        Serial.println("\n\n JUGADOR A GANA EL PARTIDO\n\n");
    }
    else{
        //animacion de cuando el jugador b gana el partido
        Serial.println("\n\n JUGADOR B GANA EL PARTIDO\n\n");
    }
}