#include "auton.h"
#include "Drive.h"
#include "api.h"
#include "Odometry.h"


float auton_1_cord[][3] = 
{
    //x     y      heading
    {150.0, 203.0, 165.0}, //0
    {249.0, 255.0, 253.0}, //1
    {5, 10, 13} //2
};


int num = 0;

void auton1(){
    while (1){
        trackposition();

        if (drive_cord(auton_1_cord[num][1], auton_1_cord[num][2], auton_1_cord[num][3]) == 1){
            //add all actions that happen at a point here
            /*
            if (num == 0){
            deploy ball removere
            }

            if (num == 5){
            move intake
            }*/
            num ++;
        }

        pros::delay(5);
    }  
}