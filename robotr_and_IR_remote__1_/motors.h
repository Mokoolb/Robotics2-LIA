#include "Arduino.h"//include Arduino library
#ifndef MOTORS_H//checks if an instance has already been created
#define MOTORS_H//if an instance has already been created it will define that one
class motors{//creating the class motors
  private://everthing in here is only in the class
  int motors1;//variable that is only used in class for right motors
  int speed1;//variable that is only used in class for speed of right mototrs
  int motors2;//variable that is only used in class for left motors
  int speed2;//variable that is only used in class for speed of left motors
  public://can be accessed outside class
  motors(int x,int y,int z,int a);//constructor
  void move(int a,int b,int c,int d);//void function that is used by other methods
  void forward(int x);//method to move forward
  void left(int x);//method to move left
  void right(int x);//method to move right
  void right_onplace(int x);//method to move right onplace
  void left_onplace(int x);//method to move left onplace
  void left_forward(int x);//method to move left forward
  void right_forward(int x);//method to move right forward
  void backward(int x);//method to move backward
  void init();//method to initialized motors
  void standby(int x);//method for standby
  void stop();//method for standby
};
#endif// end the if
