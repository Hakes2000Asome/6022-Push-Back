#include "auton.h"
#include "Drive.h"
#include "api.h"
#include "Odometry.h"
#include "setup.h"

using namespace pros;

float auton_1_cord[][3] = 
{
    //x     y      heading
    {0, 30, 270}, //0
    {30, 35, 0}, //1
    
};

int num = 0;

void auton1(){
    if (1){
        if (num == sizeof(auton_1_cord)/sizeof(auton_1_cord[0])){
            return;
        }
        pros::lcd::print(4, "num: %d", num);
        trackposition();

        //add all actions that happen at a point here - will happen the second it is done with the number before
        if (num == 1){
            intake.move(-127);
        }

        if (!drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2])){
            drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2]);
           return;
        } 
        num ++;
        first(0);
    }  
}