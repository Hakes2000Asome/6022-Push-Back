#include "Odometry.h"
#include "math.h"
#include "setup.h"
#include "main.h"
#include "funtions.h"

float xcurrent = 13 + 8; //inches
float ycurrent = 16.86; //inches
float previous = 0; //centidegrees
int wheel_diameter = 2.625;
float wheel_ratio = 1.389*(wheel_diameter*std::numbers::pi)/36000;

float wheel_angle(){
    
}
float accurate_angle(){
    return reduce_0_to_360(imu_sensor.get_heading()+90);
}
 
float current_y_pose(){
    return ycurrent;
}

float current_x_pose(){
    return xcurrent;
}

void trackposition(){
    float ytravel =  -(rotation_sensor.get_position()-previous) * wheel_ratio * cos(accurate_angle()*2*std::numbers::pi/360);
    ycurrent = ytravel + ycurrent;
    float xtravel =  -(rotation_sensor.get_position()-previous) * wheel_ratio * sin(accurate_angle()*2*std::numbers::pi/360);
    xcurrent = xtravel + xcurrent;
    previous = rotation_sensor.get_position();
    delay(10);
}
