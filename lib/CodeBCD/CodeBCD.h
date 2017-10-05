#ifndef CodeBCD_h
#define CodeBCD_h
#include <Arduino.h>

class CodeBCD {
  private:
    byte _pin[4];

  public:
    CodeBCD(byte A, byte B, byte C, byte D);
    byte pin[4];
    void write(byte dec);
    void writeNeg(byte dec);
};
#endif
