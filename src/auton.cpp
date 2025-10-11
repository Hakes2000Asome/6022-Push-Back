#include "auton.h"
#include "Drive.h"
#include "api.h"
#include "Odometry.h"
#include "setup.h"

using namespace pros;

float auton_1_cord[][3] = 
{
    //x     y      heading
/*0*/    {48, 18, 180}, 
/*1*/    {48, 0, 180}, 
/*2*/    {48, 48, 0}, 
/*3*/    {24, 40, 0}, 
/*4*/    {24, 54, 0}, 
/*5*/    {12, 60, 315}, 
/*6*/    {-12, 48, 270},
/*7*/    {-24, 48, 45},
/*8*/    {-12, 12, 45}
};

int num = 0;

void auton1(){
    if (1){
        pros::lcd::print(4, "num: %d", num);

        if (num == sizeof(auton_1_cord)/sizeof(auton_1_cord[0])){
            return;
        }

        //add all actions that happen at a point here - will happen the second it is done with the number before
        if (num == 1 /*color senser*/){
            intake.move(-127);
            return;
        }
        if (num == 1){
            in
        }


        if (!drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2])){
            drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2]);
           return;
        } 
        num ++;
        first(0);
    }  
}



float auton_test_cord[][3] = 
{
    //x     y      heading
/*0*/    {0, 30,  180}, 
/*1*/    {30, 35, 270}, 
};

void auton_test(){
    if (1){
        pros::lcd::print(4, "num: %d", num);

        if (num == sizeof(auton_1_cord)/sizeof(auton_1_cord[0])){
            return;
        }

        //add all actions that happen at a point here - will happen the second it is done with the number before
        if (!drive_cord(auton_test_cord[num][0], auton_test_cord[num][1], auton_test_cord[num][2])){
            drive_cord(auton_test_cord[num][0], auton_test_cord[num][1], auton_test_cord[num][2]);
           return;
        } 
        num ++;
        first(0);
    }  
}