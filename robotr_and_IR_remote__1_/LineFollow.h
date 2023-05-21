#ifndef LINEFOLLOW_H
#define LINEFOLLOW_H
#include "Arduino.h"
class LineFollow{
  private:
  //LIGHT SENSORS
  int sensor_right;
  int sensor_left;
  int sensor_middle;
  //time
  unsigned long current_millis = millis();
  unsigned long previous_millis;
  public:
  LineFollow(){};
  void follow();
  
};
#endif
