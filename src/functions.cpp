#include "funtions.h"
#include "math.h"
#include "setup.h"

float reduce_negative_180_to_180(float angle) {
  while(!(angle >= -180 && angle < 180)) {
    if(angle < -180) {
        angle += 360; 
    }
    if(angle >= 180) {
        angle -= 360; 
    }
  }
  return(angle);
}

float reduce_0_to_360(float angle) {
  while(!(angle >= 0 && angle < 360)) {
    if( angle < 0 ) { angle += 360; }
    if(angle >= 360) { angle -= 360; }
  }
  return(angle);
}

float accurate_angle(){
    float x = imu_sensor.get_rotation()/360;
    float angle = reduce_0_to_360(reduce_negative_180_to_180(imu_sensor.get_heading()) + 9.221*x); //(0.862-4.7*x-0.043*pow(x,2)+0.0073*pow(x,3))
    return angle;
}