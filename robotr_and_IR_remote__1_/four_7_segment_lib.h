#ifndef FOUR_7_SEGMENT_LIB_H
#define FOUR_7_SEGMENT_LIB_H
#include "Arduino.h"
class FOUR_7_SEGMENT{
  private:
  const byte digits[10] = {  //It indicates which pins have to be on and off to display each number
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B0000111,  // 7
  B01111111,  // 8
  B01101111,   // 9
};
int latch = 41; //pin to latch 4
int cs = 42; //clockpin 5
int data = 40; //pin to pass the information 3
int dPins[4] = {25, 24, 23, 22};  //pins that control the digits, the go in that order, 4-3-2-1

  public:
  FOUR_7_SEGMENT(){};
  void number(int a, int b,int c,int d);
  
};
#endif
