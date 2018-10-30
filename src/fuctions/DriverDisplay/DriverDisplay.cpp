#include <Arduino.h>
#include <fuctions/DriverDisplay/DriverDisplay.h>
#include <CodeBCD.h>
#include <struct/jugData.h>


extern CodeBCD display_jug_a[];
extern CodeBCD display_jug_b[];
extern struct player_data jug_A;
extern struct player_data jug_B;


void updateDisplayJug_A(){
    display_jug_a[0].write(getPos_0(jug_A.punt));
    display_jug_a[1].write(getPos_1(jug_A.punt));
}

void updateDisplayJug_B(){
    display_jug_a[0].write(getPos_0(jug_B.punt));
    display_jug_a[1].write(getPos_1(jug_B.punt));
}

byte getPos_0(byte input){
    return input % 10;
}
byte getPos_1(byte input){
    return input / 10;
}
