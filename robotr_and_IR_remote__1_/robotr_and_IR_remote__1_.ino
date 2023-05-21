#include "IRremote.h"
#include "four_7_segment_lib.h"
/*----- Variables, Pins -----*/

//IR
int receiver = 9; // Signal Pin of IR receiver to Arduino Digital Pin 6
IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'

//MODE
int mode = 0;


//LineFollow
#include "LineFollow.h"

//Avoider
#include "Avoider.h"

//MOTORS
#include "motors.h"
motors robt(7,5,8,6);//creating object robot using pins 7,5,8,6
FOUR_7_SEGMENT player;
//SERVO
#include <Servo.h>//add servo library

avoider ultra;
LineFollow follower;
Servo aservo;  // create servo object to control a servo
void setup()
{ 
  
  //Ultrasonic
  ultra.init();
  //robot
  for(int i=0; i<9; i ++){
    pinMode(i,OUTPUT);
  }
  digitalWrite(3, HIGH);

  //IR
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600);
  aservo.attach(11);  // attaches the servo on pin 11 to the servo object
  
}

int shoot = 0;
void loop() 
{
  player.number(6,5,4,3);
  //IR
if (irrecv.decode(&results)) // have we received an IR signal?

  {
    switch(results.value)
    {
      if(mode == 1){
      case 16736925: // UP button pressed
      robt.forward(100);                                          
      break;
      case 16720605: // LEFT button pressed
      robt.left_onplace(100);
      break;
      case 16754775: // DOWN button pressed
       robt.backward(100);                                           
      break;
      case 16761405: // RIGHT button pressed
       robt.right_onplace(100);                                            
      break;
      }     
      case 16724175: // 1 button pressed
      mode = 1;
      robt.stop();                                          
      break;
      case 16718055: // 2 button pressed
      mode = 2;                                           
      break;
      case 16743045: // 3 button pressed
       mode = 3;
       break;
      case 16712445: // OK button pressed
      if(shoot == 0){
       aservo.write(0); 
       shoot = 1;        
      }
      else if(shoot == 1){
       aservo.write(110);     
       shoot = 0;          
      }
       break;        
    }
      Serial.println(results.value);
      irrecv.resume(); // receive the next value
  } 

  //LINE FOLLOW
  if(mode == 2){
 follower.follow();
  }
  //ULTRASONIC
  else if(mode == 3){
ultra.avoid();
  }
  
}/* --end main loop -- */
