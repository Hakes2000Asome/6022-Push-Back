#include "auton.h"
#include "Drive.h"
#include "api.h"
#include "Odometry.h"
#include "setup.h"

using namespace pros;

float auton_1_cord[3][3] = 
{
    //x     y      heading
    {10, 10, 45}, //0
    {0, 0, 225}, //1
    {5, 10, 180} //2
    
};

int num = 0;

void auton1(){
    if (1){
        if (num == 3){
            return;
        }
        pros::lcd::clear_line(0);
		pros::lcd::clear_line(1);
		pros::lcd::clear_line(2);
		pros::lcd::print(0, "x: %f", current_x_pose());
		pros::lcd::print(1, "y: %f", current_y_pose());
        pros::lcd::print(2, "num: %d", num);
        trackposition();
    
        if (!drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2])){
            drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2]);
           return;
        }
//        motor_group_right.move(0);
//        motor_group_left.move(0);
//            //add all actions that happen at a point here
//            /*
//            if (num == 0){
//            //deploy ball removere
//            }
//
//            if (num == 5){
//            //move intake
//            }*/
        num ++;
//       pros::Task::delay(10);

        first(0);
    }  
}