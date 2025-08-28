#include "Drive.h"
#include <math.h>
#include "api.h"
#include "funtions.h"
#include "setup.h"
#include "Odometry.h"
double pi = 3.1415926535;


float turn_p = 127/180;
float turn_i = 1;
float turning_threshold = 3;

float drive_p = 1;
float drive_threshold = 1;

int drive_cord(int x_cord, int y_cord, int heading){
    while (turn(atan2(y_cord, x_cord)*36000/(2*pi)) == 0){
        delay(5);
    }
    if ( sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ) > drive_threshold ){
        float delta_distance = (sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ));
        motor_group_left.move(delta_distance * drive_p);
        motor_group_left.move(delta_distance * drive_p);
        return 0;
    }
    else{
        motor_group_left.move(0);
        motor_group_right.move(0);
        return 1;
    }
    
}

int turn(int angle){
    if (abs(angle-imu_sensor.get_heading())>turning_threshold){
        float delta_angle = reduce_negative_180_to_180(angle-imu_sensor.get_heading());
        if(delta_angle < 0){
            motor_group_right.move(-delta_angle * turn_p);
            motor_group_left.move(delta_angle * turn_p);
        }
        if(delta_angle > 0){
            motor_group_right.move(-delta_angle * turn_p);
            motor_group_left.move(delta_angle * turn_p);
        }
        return 0;
    }
    else{
        return 1;
    }
}

int turn2(int angle){
    if (abs(angle-imu_sensor.get_heading())>turning_threshold){
        float delta_angle = reduce_negative_180_to_180(angle-imu_sensor.get_heading());
        if(delta_angle < 0){
            motor_group_right.move(-delta_angle * turn_p);
            motor_group_left.move(delta_angle * turn_p);
        }
        if(delta_angle > 0){
            motor_group_right.move(-delta_angle * turn_p);
            motor_group_left.move(delta_angle * turn_p);
        }
        return 0;
    }
    else{
        motor_group_left.move(0);
        motor_group_right.move(0);
        return 1;
    }
}
