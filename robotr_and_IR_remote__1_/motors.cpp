#include"motors.h"
motors :: motors(int x,int y,int z,int a){//constructor receives values for pins
  motors1 = x;//setting values from object to variables in class
  speed1 = y;//setting values from object to variables in class
  motors2 = z;//setting values from object to variables in class
  speed2 = a;//setting values from object to variables in class
}
void motors :: move(int b,int c,int d,int e){//move method used in class
  digitalWrite(motors1,b);//changing values of motors depending on b
  analogWrite(speed1,c);//changing values of speed depending on c
  digitalWrite(motors2,d);//changing values of motors depending on d
  analogWrite(speed2,e);//changing values of speed depending on c
}
void motors :: init(){//initializes motors
  pinMode(motors1,OUTPUT);//initializes digital pin motors1 as output
  pinMode(motors2, OUTPUT);//initializes digital pin motors2 as output
}
void motors :: standby(int x){//function to be able to not move
  digitalWrite(3,x);//turns pin 3 on
}
void motors :: forward(int x){//function for forward moving
  move(1,x,1,x); // turns on all motors at x speed
}
void motors :: left(int x){//function for left moving
  
  move(1,x,0,0); // turns on left motors at x speed
}
void motors :: right(int x){//function for right moving
  move(0,0,1,x); // turns on right at x speed
}
void motors :: right_onplace(int x){//function for right_onplace moving
  move(0,x,1,x); // turns on all motors at x speed, right forward and left backwards
}
void motors :: left_onplace(int x){//function for left_onplace moving
  move(1,x,0,x); // turns on all motors at x speed, left forward and right backwards
}
void motors :: left_forward(int x){//function for left_forward moving
  
  move(1,x,1,x/2);   // turns on left at x speed, and right at half x speed
}
void motors :: right_forward(int x){//function for right_forward moving
  move(1,x/2,1,x);// turns on right at x speed, and left at half x speed
}
void motors :: backward(int x){//function for backward moving
  move(0,x,0,x); // turns on all motors at x speed backwards
}
void motors :: stop(){//function for backward moving
  move(0,0,0,0); // turns on all motors at x speed backwards
}

