#include "Odometry.h"
#include "math.h"
#include "setup.h"
#include "main.h"
#include "funtions.h"

float ycurrent = 1; //inches
float xcurrent = 5; //inches
float previous = 0; //centidegrees
int wheel_diameter = 2.625;
float wheel_ratio = (wheel_diameter*std::numbers::pi)/36000;

float current_y_pose(){
    return ycurrent;
}
float current_x_pose(){
    return xcurrent;
}
void trackposition(){
    float ytravel =  (rotation_sensor.get_position()-previous) * wheel_ratio * cos(accurate_angle());
    ycurrent = ytravel + ycurrent;
    float xtravel =  (rotation_sensor.get_position()-previous) * wheel_ratio * sin(accurate_angle());
    xcurrent = xtravel + xcurrent;
    previous = rotation_sensor.get_position();
    delay(10);
}
