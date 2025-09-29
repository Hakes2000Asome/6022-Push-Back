#include "funtions.h"
#include "math.h"
#include "setup.h"

float timeTracker = 0;
float angle = 0;
bool initialHeadingTracker = 0;
float heading1 = imu_sensor.get_rotation();
float heading2 = imu_sensor.get_rotation();

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

void updateMillis(){
    timeTracker = pros::millis();
  }

float accurate_angle(){
    float x = imu_sensor.get_rotation()/360;
    heading1 = imu_sensor.get_rotation();
    if (pros::millis() - timeTracker > 250) {
      updateMillis();
      initialHeadingTracker = 0;
      if (heading1 - heading2 >= 0){ //clockwise
        angle = reduce_0_to_360(reduce_negative_180_to_180(imu_sensor.get_heading()) - 9.66*x - 0.851); //(0.862-4.7*x-0.043*pow(x,2)+0.0073*pow(x,3))
      }
      else { //counterclockwise
        angle = reduce_0_to_360(reduce_negative_180_to_180(imu_sensor.get_heading()) - 9.66*x - 0.851); //(0.862-4.7*x-0.043*pow(x,2)+0.0073*pow(x,3))
      }      
      heading2 = imu_sensor.get_rotation();
    }
    return angle;    
}