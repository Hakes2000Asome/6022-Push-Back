#include "Odometry.h"
#include "math.h"
#include "setup.h"
#include "main.h"
#include "funtions.h"

float ycurrent = 0; //inches
float xcurrent = 0; //inches
float previous = 0; //centidegrees
int wheel_diameter = 2.625;
float wheel_ratio = (wheel_diameter*std::numbers::pi)/36000;
float angle_wheel_radius = 2.663;

float wheel_angle(){
    float arc_length =  (rotation2_sensor.get_position()) * wheel_ratio;
    float angle = arc_length / angle_wheel_radius;
    delay(10);
    return angle;
}
 
float current_y_pose(){
    return ycurrent;
}

float current_x_pose(){
    return xcurrent;
}

void trackposition(){
    float ytravel =  (rotation_sensor.get_position()-previous) * wheel_ratio * cos(0);
    ycurrent = ytravel + ycurrent;
    float xtravel =  (rotation_sensor.get_position()-previous) * wheel_ratio * sin(0);
    xcurrent = xtravel + xcurrent;
    previous = rotation_sensor.get_position();
    delay(10);
}
