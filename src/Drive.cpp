#include "Drive.h"
#include <math.h>
#include "api.h"
#include "funtions.h"
#include "setup.h"
#include "Odometry.h"
float pi = 3.1415926535;

int turning_threshold = 2;
int turn_slowdown = 75;
int turn_power = 7;
int turn_voltage = 90;
int turn_minimum = 20;

int drive_threshold = 5;
int drive_slowdown = 15;
int drive_power = 3;
int drive_voltage = 20;
int drive_minimum = 20;

bool first_turn = 0;
bool first_drive = 0;

void first(bool input){
    first_turn = input;
    first_drive = input;
}
int drive_cord(int x_cord, int y_cord, int heading){
    int theta = atan2((x_cord - current_x_pose()), (y_cord- current_y_pose()))*360/(2*pi);

    if ((!turn(theta)) && (!first_turn)){
        turn(theta);
        delay(5);
        return 0;
    }

    first_turn = 1;

    if ((sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ) > drive_threshold ) && (!first_drive)){
        
        float delta_distance = (sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ));
        float delta_angle = reduce_negative_180_to_180(theta-accurate_angle());

        float power = drive_voltage*pow((delta_distance/drive_slowdown), drive_power)+drive_minimum*abs(pow(delta_distance/drive_threshold,(1/drive_power)))*delta_distance/abs(delta_distance);
       float power_turn = turn_voltage*pow((delta_angle/turn_slowdown), turn_power)+turn_minimum*abs(pow(delta_angle/turning_threshold,(1/turn_power)))*delta_angle/abs(delta_angle);
       
       if (power >= 127){
            power = 127;
        }
        if (power <= -127){
            power = -127;
        }
        if (power_turn >= 127){
            power_turn = 127;
        }
        if (power_turn <= -127){
            power_turn = -127;
        }
        pros::lcd::clear_line(5);
		pros::lcd::clear_line(6);
        pros::lcd::print(5, "power %f", power);
        pros::lcd::print(6, "turn power %f", power_turn);

        motor_group_left.move(power+power_turn);
        motor_group_right.move(power-power_turn);  
        return 0;
    }

    first_drive = 1;

    if (!turn(heading) && first_turn){
        turn(heading);
        return 0;
    }

    motor_group_left.move(0);
    motor_group_right.move(0);
    return 1;
}

int turn(int angle){
    float delta_angle = reduce_negative_180_to_180(angle-accurate_angle());
    
    float power = turn_voltage*pow((delta_angle/turn_slowdown), turn_power)+turn_minimum*abs(pow(delta_angle/turning_threshold,(1/turn_power)))*delta_angle/abs(delta_angle);
    
    if (abs(delta_angle)>turning_threshold){
        motor_group_right.move(-power);
        motor_group_left.move(power);

        return 0;
    }
    else{
        motor_group_right.move(0);
        motor_group_left.move(0);
        return 1;
    }
}
bool moveBack(int x_cord, int y_cord){
    int theta = atan2((x_cord - current_x_pose()), (y_cord- current_y_pose()))*360/(2*std::numbers::pi); //calculating angle

    if ((sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) ) > drive_threshold ) ){
        
        float delta_distance = (sqrt( pow((x_cord - current_x_pose()), 2) + pow((y_cord - current_y_pose()), 2) )); //distance formula
        float delta_angle = reduce_negative_180_to_180(theta-accurate_angle()); //how much the bot needs to turn

        float power = drive_voltage*pow((delta_distance/drive_slowdown), drive_power)+drive_minimum*abs(pow(delta_distance/drive_threshold,(1/drive_power)))*delta_distance/abs(delta_distance);
        float power_turn = turn_voltage*pow((delta_angle/turn_slowdown), turn_power)+turn_minimum*abs(pow(delta_angle/turning_threshold,(1/turn_power)))*delta_angle/abs(delta_angle);
        
        //to keep power within range of -127 to 127
        if (power >= 127){
            power = 127;
        }
        if (power <= -127){
            power = -127;
        }
        if (power_turn >= 127){
            power_turn = 127;
        }
        if (power_turn <= -127){
            power_turn = -127;
        }
        motor_group_left.move(-power+turn_power); //**********IS THIS SUPPOSED TO BE (power+POWER_TURN)???
        motor_group_right.move(-power-turn_power);
        return 0;
    }

    motor_group_left.move(0);
    motor_group_right.move(0);
    return 1;

}

