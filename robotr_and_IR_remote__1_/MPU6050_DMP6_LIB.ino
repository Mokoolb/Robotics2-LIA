#include "MPU6050.h"
gyro MPU;
int x;
int y;
int z;
void setup(){
  MPU.init_gyro();
}
void loop(){
  MPU.read_pos();
  x = MPU.x_pos();
  y = MPU.y_pos();
  z = MPU.z_pos();
}
