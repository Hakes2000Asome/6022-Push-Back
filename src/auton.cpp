#include "auton.h"
#include "Drive.h"
#include "api.h"
#include "Odometry.h"
using namespace pros;

float auton_1_cord[3][3] = 
{
    //x     y      heading
    {10, 10, 90}, //0
    {10, 20, 270}, //1
    {5, 10, 180} //2
    
};


int num = 0;

void auton1(){
    if (1){
        pros::lcd::clear_line(0);
		pros::lcd::clear_line(1);
		pros::lcd::clear_line(2);
		pros::lcd::print(0, "x: %f", current_x_pose());
		pros::lcd::print(1, "y: %f", current_y_pose());
        pros::lcd::print(2, "num: %f", (drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2])));
        trackposition();
    
        if (!drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2])){
            drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2]);
            return;
        }
        if(drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2])){

            //add all actions that happen at a point here
            /*
            if (num == 0){
            //deploy ball removere
            }

            if (num == 5){
            //move intake
            }*/
            delay(500);
            num ++;
            if (num == 4){
                return;
            }
        }
        pros::delay(100);
    }  
}