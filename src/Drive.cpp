#include "Drive.h"
#include <math.h>
#include "api.h"
#include "funtions.h"
#include "setup.h"
#include "Odometry.h"
double pi = 3.1415926535;


float turn_p = 2;
float turn_i = 1;
float turning_threshold = 3;

float drive_p = 15;
float drive_threshold = 1.5;

int drive_cord(int x_cord, int y_cord, int heading){
    pros::lcd::print(4, "here");
    int theta = atan2(y_cord, x_cord)*360/(2*pi);
    /*while (turn2(theta) == 0){
        turn2(theta);
        pros::lcd::print(5, "while");
        delay(5);
    }*/
    if ( sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ) > drive_threshold ){
        float delta_distance = (sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ));
        motor_group_left.move(delta_distance * drive_p);
        motor_group_right.move(delta_distance * drive_p);
        pros::lcd::print(5, "move");    
        return 0;
    }
    
    else{
    pros::lcd::print(6, "headding?");
        while (turn2(heading) == 0){
            turn2(heading);
            pros::lcd::print(4, "stuck");
            delay(5);
        }
      //  motor_group_left.move(0);
    //    motor_group_right.move(0);
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
    float delta_angle = reduce_negative_180_to_180(angle-imu_sensor.get_heading());

    if (abs(delta_angle)>turning_threshold){
        pros::lcd::print(5, "ran");
        motor_group_right.move(-delta_angle * turn_p);
        motor_group_left.move(delta_angle * turn_p);

        return 0;
    }
    else{
        pros::lcd::print(6, "nope");
        motor_group_left.move(0);
        motor_group_right.move(0);
        return 1;
    }
}
