#include "Odometry.h"
#include "math.h"
#include "setup.h"
#include "main.h"
#include "funtions.h"

float xcurrent = 0; //13 + 8; //inches
float ycurrent = 0; //16.86; //inches
float r_previous = 0; //centidegrees
float l_previous = 0; //centidegrees
float s_previous = 0; //centidegrees
float wheel_diameter = 2.625; //inches
float wheel_ratio = (wheel_diameter*std::numbers::pi)/36000; // inches / degrees
float side_wheel_diameter = 2.625; //inches
float side_wheel_ratio = (side_wheel_diameter*std::numbers::pi)/36000; // inches / degrees
float heading = 0; //degrees
float wheel_distance = 10; //inches between left and right drivetrain

float accurate_angle(){ //returns heading in degrees
    return reduce_0_to_360(heading * 180 / M_PI );  //converts radians to degrees
}
 
float current_y_pose(){ //returns y position
    return ycurrent;
}

float current_x_pose(){ //returns x position
    return xcurrent;
}

void trackposition(){
    float rtravel = -(r_rotation_sensor.get_position()-r_previous) * wheel_ratio; //right side drivetrain delta distance
    float ltravel = -(l_rotation_sensor.get_position()-l_previous) * wheel_ratio; //left side drivetrain delta distance
    float atravel = (rtravel + ltravel) / 2; //averages left and right side drivetrain delta distance to find distance moved

    float stravel = (s_rotation_sensor.get_position() - s_previous) * side_wheel_ratio; //finds sideways(perpendicualar to direction of motion) delta distance

    float heading = heading + (ltravel - rtravel) / wheel_distance; //calculates headding using equation from https://wiki.purduesigbots.com/software/odometry
    
    float ytravel =  atravel * cos(heading) + stravel * sin(heading); //calulates y delta travel by using forward distance moved and sideways (if pushed or smth)
    ycurrent = ytravel + ycurrent;  // calulates y current position
    
    float xtravel =  atravel * sin(heading) + stravel * cos(heading); //calulates y delta travel by using forward distance moved and sideways (if pushed or smth)
    xcurrent = xtravel + xcurrent; //calulates current x position


    r_previous = r_rotation_sensor.get_position();  //updates previous rotation sensor data to current
    l_previous = l_rotation_sensor.get_position();  //updates previous rotation sensor data to current
    s_previous = s_rotation_sensor.get_position();  //updates previous rotation sensor data to current
    delay(5); //delay to make happy
}
