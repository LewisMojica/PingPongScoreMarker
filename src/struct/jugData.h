struct jugData{
  byte punt;
  byte win_set;
  byte getPos0(){
    return punt % 10;
  }
  byte getPos1(){
    return punt / 10;
  }
};
