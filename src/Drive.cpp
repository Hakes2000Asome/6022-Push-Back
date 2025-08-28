#include "Drive.h"
#include <math.h>
#include "api.h"
#include "funtions.h"
#include "setup.h"
double pi = 3.1415926535;


float turn_p = 1;
float turn_i = 1;
float drive_p = 1;
float turning_threshold = 3;

int drive_cord(int x_cord, int y_cord, int heading){
    int angle = atan2(y_cord, x_cord)*36000/(2*pi);
    return 0;
}

int drive_distance(int distance){
    int feetTo = distance/(3.25*pi);
    //while(distance)
    return 0;
}

int turn(int angle){
    while(abs(angle-imu_sensor.get_heading())>turning_threshold){
        float delta_angle = reduce_negative_180_to_180(angle-imu_sensor.get_heading());
        if(delta_angle < 0){
            motor_group_right.move(-delta_angle * turn_p);
            motor_group_left.move(delta_angle * turn_p);
        }
        if(delta_angle > 0){
            motor_group_right.move(-delta_angle * turn_p);
            motor_group_left.move(delta_angle * turn_p);
        }
    }
    return 0;
}

