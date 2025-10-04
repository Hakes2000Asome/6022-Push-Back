#include "Drive.h"
#include <math.h>
#include "api.h"
#include "funtions.h"
#include "setup.h"
#include "Odometry.h"
double pi = 3.1415926535;


float turn_p = 2.5;
float turn_i = 1;
float turning_threshold = 3;

float drive_p = 5;
float drive_slowdown = 5;
float drive_threshold = 4;
bool first_turn = 0;

void first(bool input){
    first_turn = input;
}
int drive_cord(int x_cord, int y_cord, int heading){
    int theta = atan2((x_cord - current_x_pose()), (y_cord- current_y_pose()))*360/(2*pi);

    if ((!turn2(theta)) && (!first_turn)){
        turn2(theta);
        delay(5);
        return 0;
    }
    if ((sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ) > drive_threshold ) && (!first_turn)){
        float delta_distance = (sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ));
        motor_group_left.move(127*pow(((delta_distance * drive_p)/drive_slowdown), 4));
        motor_group_right.move(127*pow(((delta_distance * drive_p)/drive_slowdown), 4));  
        return 0;
    }

    first_turn = 1;

    if (!turn2(heading) && first_turn){
        turn2(heading);
        return 0;
    }

    motor_group_left.move(0);
    motor_group_right.move(0);
    return 1;
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
        return 1;
    }
}
