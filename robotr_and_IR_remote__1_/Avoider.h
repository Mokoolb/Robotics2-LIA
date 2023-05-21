#ifndef AVOIDER_H
#define AVOIDER_H
#include "Arduino.h"
//SERVO
#include <Servo.h>//add servo library
class avoider{
  private:
  //ULTRASONIC
  Servo myservo;  // create servo object to control a servo
  #define trigPin 13//defines the output ultrasonic value pin
  #define echoPin 12//defines the input ultrasonic value pin 
  float duration, distance;//setting up variables for the duration before the wave is received and calculates the distance
  //time
  unsigned long current_millis = millis();
  unsigned long previous_millis;
  public:
  avoider(){};
  void init();
  void read();
  void avoid();
};
#endif  
