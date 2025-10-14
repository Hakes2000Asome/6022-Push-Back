#include "auton.h"
#include "Drive.h"
#include "api.h"
#include "Odometry.h"
#include "setup.h"

using namespace pros;

float auton_1_cord[][3] = 
{
    //x     y      heading
/*0*/    {48, 16.86-7.5, 180}, // first position
/*1*/    {48, 0, 180},  //moving towards the loader
//needs to back up 
/*2*/    {48, 48, 0}, //Scoring top 4x
//needs to back up
/*3*/    {24, 40, 0}, //get to the position before rotating to get the next two pieces in the middle
/*4*/    {24, 54, 0}, //get the two pieces
/*5*/    {12, 60, 315}, //scoring in the bottom 2x 
//needs to back up
/*6*/    {-12, 48, 270}, // position before picking up the next three pieces 
/*7*/    {-24, 48, 45}, //picking up the next three pieces and angle for scoring
/*8*/    {-12, 12, 45} // scoring on middle 3x
    
};

int num = 0;

void auton1(){
    if (1){
        pros::lcd::print(4, "num: %d", num);
        //add all actions that happen at a point here - will happen the second it is done with the number before
        if (num == 2 /*&& Color sensor detects our color*/){
            intake.move(-127);  //in
            storage.move(127);  //in
            return;
        }
        if (num == 2 /*&& color sensor detects other color*/){
            intake.move(0); 
            storage.move(0);
            delay(10);
            //back up 6 in
            if (!moveBack(48, 6)){
                moveBack(48, 6);
                return;
            }
        }


        if (num == 3 /*&& not all pieces have been scored*/){
			intake.move(-127);	//in
			storage.move(127);	//out
			top.move(127);		//middle
            return;
        }
        if (num == 3 /*&& ALL pieces have been scored*/){
			intake.move(0);	    //in
			storage.move(0);	//out
			top.move(0);		//middle
            delay(0);
            //back up 6 in
            if (!moveBack(48, 42)){
                moveBack(48,42);
                return;
            }
        } 


        if (num == 4){
            intake.move(-127); //in
            storage.move(127); //in
        }


        if (num == 6 /*&& not all pieces have been scored*/){
            intake.move(127);	//out
			storage.move(127);	//out
            return;
        }
        if (num == 6 /*&& ALL pieces have been scored*/){
			intake.move(0);	    //in
			storage.move(0);	//out
            delay(0);
            //back up 6 in
            if (!moveBack(16, 56)){
                moveBack(16, 56);
                return;
            }
        }


        if (num == 7){
            intake.move(-127); //in
            storage.move(127); //in
        }


        if (num == 9 /*&& not all pieces have been scored*/){
            intake.move(127);	//out
			storage.move(127);	//out
            return;
        }
        if (num == 9 /*&& ALL pieces have been scored*/){
			intake.move(0);	    //in
			storage.move(0);	//out
            delay(0);
            //back up 6 in
        }
        if (num == sizeof(auton_1_cord)/sizeof(auton_1_cord[0])){
            //completed
            //DOESN'T IT NEED TO RETURN TO ORIGINAL LOCATION???
            return;
        }

        if (!drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2])){
            drive_cord(auton_1_cord[num][0], auton_1_cord[num][1], auton_1_cord[num][2]);
           return;
        } 
        num ++;
        first(0);
    }  

}
