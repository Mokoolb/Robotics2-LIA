#include "Arduino.h"
#include "LineFollow.h"
#include "motors.h"
motors robo(7,5,8,6);//creating object robot using pins 7,5,8,6
void LineFollow :: follow(){
  current_millis = millis();
  sensor_right = analogRead(A0);
  sensor_left = analogRead(A2);
  sensor_middle = analogRead(A1);
  // put your main code here, to run repeatedly:
 if(sensor_middle >50){
  robo.forward(75);
 }
 else if(sensor_right >50){
  robo.right(250);

 }
 else if(sensor_left >50){
  robo.left(250);


 }
 else{

  //search
  previous_millis = millis();
   while((current_millis-previous_millis) <100){
    current_millis = millis();
      robo.right_onplace(100);
      if(sensor_middle >50){
        break;
      }
   }

 }
}
