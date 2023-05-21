#include "Arduino.h"
#include "Avoider.h"
//SERVO
#include <Servo.h>//add servo library

//MOTORS
#include "motors.h"
motors robot(7,5,8,6);//creating object robot using pins 7,5,8,6
void avoider :: init(){
  //ultrasonic
  robot.init();//initialize motors
  robot.standby(1);//set robot on standby
    pinMode(trigPin, OUTPUT);// setting pin 10 as an output
  pinMode(echoPin, INPUT);//setting pin 13 as an input
  
  //servo
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
}
void avoider :: read(){
  // Write a pulse to the HC-SR04 Trigger Pin 
  digitalWrite(trigPin, LOW);//sets pin 10 off
  delayMicroseconds(2);//delays for 2 microseconds
  digitalWrite(trigPin, HIGH);;//sets pin 10 on
  delayMicroseconds(10);//delays for 10 microseconds
  digitalWrite(trigPin, LOW);;//sets pin 10 off
  duration = pulseIn(echoPin, HIGH);;//reads the value returned from pin 13 and stores it in duration(of wave)
  distance = (duration / 2) * 0.0343;//converts duration into distance in metric centimeters
}
void avoider :: avoid(){  
  robot.forward(100);   
  myservo.write(90);                  
  read(); 
  if (distance <= 20) {//all checks if distance is less then 2 or greater then 400 which would be out of range
    robot.stop();
    myservo.write(180);
     delay(1000);
     read();
     myservo.write(90);   
     if (distance <= 20) {//all checks if distance is less then 2 or greater then 400 which would be out of range
     myservo.write(0);
     delay(1000);
     read();
     myservo.write(90);   
       if (distance <= 20) {
    robot.left_onplace(100);
     delay(1200);
  }
  else{
    robot.right_onplace(100);
     delay(600);
  }
  }
  else{
    robot.left_onplace(100);
    delay(600);
  }

  }
}
