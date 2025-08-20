#include "Odometry.h"
#include "math.h"
#include "setup.h"
#include "main.h"

float ycurrent; //inches
float xcurrent; //inches
float previous; //centidegrees
int wheel_diameter = 3.25;
float wheel_ratio = (wheel_diameter*std::numbers::pi)/36000;

float current_y_pose(){
    return ycurrent;
}
float current_x_pose(){
    return xcurrent;
}
void trackposition(){/*
    float ytravel =  (rotation_sensor.get_position()-previous) * wheel_ratio * cos(imu_sensor.get_heading());
    ycurrent = ytravel + ycurrent;
    float xtravel =  (rotation_sensor.get_position()-previous) * wheel_ratio * sin(imu_sensor.get_heading());
    xcurrent = xtravel + xcurrent;
    previous = rotation_sensor.get_position();*/
}
