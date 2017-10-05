#include <Arduino.h>
#include "CodeBCD.h"

CodeBCD::CodeBCD(byte A, byte B, byte C, byte D){
  _pin[0] = A;
  _pin[0] = B;
  _pin[0] = C;
  _pin[0] = D;
  for (byte i = 0; i <  3; i++){
    pinMode(_pin[i],OUTPUT);
  }
}

void CodeBCD::write(byte dec) {
  digitalWrite(_pin[0], (dec & 1) == 1);
  digitalWrite(_pin[1], (dec & 2) == 2);
  digitalWrite(_pin[2], (dec & 4) == 4);
  digitalWrite(_pin[3], (dec & 8) == 8);
}

void CodeBCD::writeNeg(byte dec) {
  digitalWrite(_pin[0], !((dec & 1) == 1));
  digitalWrite(_pin[1], !((dec & 2) == 1));
  digitalWrite(_pin[2], !((dec & 4) == 1));
  digitalWrite(_pin[3], !((dec & 8) == 1));
}
