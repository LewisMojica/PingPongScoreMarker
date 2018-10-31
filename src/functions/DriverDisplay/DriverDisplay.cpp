#include <Arduino.h>
#include "DriverDisplay.h"
#include <CodeBCD.h>
#include "../../struct/jugData.h"


extern CodeBCD display_jug_a[];
extern CodeBCD display_jug_b[];
extern struct jugData jug_A;
extern struct jugData jug_B;


void updateDisplayJug_A(){
    display_jug_a[0].write(jug_A.getPos0());
    display_jug_a[1].write(jug_A.getPos1());
}

void updateDisplayJug_B(){
    display_jug_a[0].write(jug_B.getPos0());
    display_jug_a[1].write(jug_B.getPos1());
}
