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


float base_red;
float base_blue;
float base_green;

int base_color(){
  pros::c::optical_rgb_s_t rgb_value;
  rgb_value = optical_sensor.get_rgb();
  base_red = rgb_value.red ;
  base_blue = rgb_value.blue;
  base_green = rgb_value.green;
  return 0;
}

int color(){
  // 0 = null 1 = red, 2= blue, 3 = green
  pros::c::optical_rgb_s_t rgb_value;
  rgb_value = optical_sensor.get_rgb();
  pros::lcd::clear_line(5);
	pros::lcd::clear_line(6);
	pros::lcd::clear_line(7);
	pros::lcd::print(5, "red %lf \n", rgb_value.red);
	pros::lcd::print(6, "greed %lf \n", rgb_value.green);
 	pros::lcd::print(7, "blue %lf \n", rgb_value.blue); 
  

  if (rgb_value.red > 0.84*(rgb_value.green+rgb_value.blue)){
    return 1;
  }
  if (rgb_value.blue > 0.4*(rgb_value.green+rgb_value.red)){
    return 2;
  }
  if (rgb_value.green > 0.55*(rgb_value.blue+rgb_value.red)){
    return 3;
  }
  return 0;
}