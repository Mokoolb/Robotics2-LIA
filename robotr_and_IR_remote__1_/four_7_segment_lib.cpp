#include "Arduino.h"
#include "four_7_segment_lib.h"
void FOUR_7_SEGMENT :: number(int a, int b, int c, int d){
  digitalWrite(25, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(22, LOW);
  digitalWrite(latch, LOW);
   shiftOut(data, cs, MSBFIRST, digits[a]);
  digitalWrite(latch, HIGH);

  delay(5);

//Secon digit
  digitalWrite(25, HIGH);
  digitalWrite(24, HIGH);
  digitalWrite(23, LOW);
  digitalWrite(22, HIGH);
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[b]);
  digitalWrite(latch, HIGH);
  delay(5);

//Third digit
  digitalWrite(25, HIGH);
  digitalWrite(24, LOW);
  digitalWrite(23, HIGH);
  digitalWrite(22, HIGH);
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[c]);
  digitalWrite(latch, HIGH);
  delay(5);

//Four digit
digitalWrite(25, LOW);
  digitalWrite(24, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(22, HIGH);
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[d]);
  digitalWrite(latch, HIGH);
  delay(5);
}
