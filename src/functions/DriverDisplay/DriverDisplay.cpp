#include <Arduino.h>
#include "DriverDisplay.h"
#include <CodeBCD.h>
#include "../../struct/jugData.h"
#include "../../definitions/pinConfig.h"


extern CodeBCD display_jug_a[];
extern CodeBCD display_jug_b[];
extern struct jugData jug_A;
extern struct jugData jug_B;


void updateDisplayJug_A(){
    //update display
    display_jug_a[0].write(jug_A.getPos0());
    display_jug_a[1].write(jug_A.getPos1());

    //update set indicators
    if(jug_A.win_set == 1){
        digitalWrite(set_indicator_jug_a_0,HIGH);
    }
    else if(jug_A.win_set == 2)
        digitalWrite(set_indicator_jug_a_1,HIGH);
    else if(jug_A.win_set == 0){
        digitalWrite(set_indicator_jug_a_0,LOW);
        digitalWrite(set_indicator_jug_a_1,LOW);
    }
}

void updateDisplayJug_B(){
    //update display
    display_jug_a[0].write(jug_B.getPos0());
    display_jug_a[1].write(jug_B.getPos1());

    //update set indicators
    if(jug_B.win_set == 1){
        digitalWrite(set_indicator_jug_b_0,HIGH);
    }
    else if(jug_B.win_set == 2)
        digitalWrite(set_indicator_jug_b_1,HIGH);
    else if(jug_B.win_set == 0){
        digitalWrite(set_indicator_jug_b_0,LOW);
        digitalWrite(set_indicator_jug_b_1,LOW);
    }
}

void updateAllDisplay(){
    updateDisplayJug_A();
    updateDisplayJug_B();
}
