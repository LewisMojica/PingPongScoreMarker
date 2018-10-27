void updateDisplayJug_A();
void updateDisplayJug_B();
byte getPos_0(byte);


void updateDisplayJug_A(){
    display_jug_a[0].write(getPos_0(jug_A.punt));
    display_jug_a[0].write(getPos_0(jug_A.punt));
}

byte getPos_0(byte input){
    return input % 10;
}