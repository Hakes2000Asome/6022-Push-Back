#include "auton.h"
#include "Drive.h"
#include "api.h"
#include "Odometry.h"
#include "setup.h"
#include "funtions.h"

using namespace pros;

bool task1 = 0;
bool task2 = 0;
bool task3 = 0;
bool task4 = 0;
bool task5 = 0;
bool task6 = 0;
bool task7 = 0;
bool task8 = 0;
bool task9 = 0;
bool task10 = 0;
bool task11 = 0;
bool task12 = 0;
bool task13 = 0;
bool task14 = 0;
bool task15 = 0;
bool task16 = 0;
bool task17 = 0;
bool task18 = 0;
bool task19 = 0;
bool task20 = 0;
bool task21 = 0;
bool task22 = 0;
bool task23 = 0;
bool task24 = 0;
bool task25 = 0;

float auton_red_cord[][3] = 
{
    //x     y      heading
/*0*/    {48, 28, 180}, // first position

/*1*/    {48, 11.2, 180},  //moving towards the loader
//needs to back up 
/*2*/    {47.5, 36, 0}, //Scoring top 4x
//needs to back up
/*3*/    {24, 43, 0}, //get to the position before rotating to get the next two pieces in the middle
/*4*/    {24, 54, 0}, //get the two pieces
/*5*/    {12, 60, 315}, //scoring in the bottom 2x 
//needs to back up
/*6*/    {-12, 48, 270}, // position before picking up the next three pieces 
/*7*/    {-24, 48, 45}, //picking up the next three pieces and angle for scoring
/*8*/    {-12, 12, 45} // scoring on middle 3x
    
};

int num = 0;

void auton_red(){
    if (1){
        pros::lcd::clear_line(4);
        pros::lcd::print(4, "num: %d", num);
        //add all actions that happen at a point here - will happen the second it is done with the number before
        // if (num == 0){
        //     motor_group_left.move(25); 
        //     motor_group_right.move(25);
        //     delay(50);
        //     motor_group_left.move(0); 
        //     motor_group_right.move(0);
        // }
        if (num == 1 && !task1){
            piston.set_value(true); //down
            task1 = 1;
        }

        if (num == 2 && !task2){
            intake.move(-127);  //in
            storage.move(-127);  //in
            if (!(color() == 2)){
                delay(20);
                return;
            }
            task2 = 1;
            return;
        }
        if (num == 2 && !task3){
            intake.move(127); //out
            storage.move(0);
            //back up 12 in
            /*if (!moveBack(48, 12, 0)){
                moveBack(48, 12, 0);
                return;
            }*/
            motor_group_left.move(-50); 
            motor_group_right.move(-50); 
            delay(250);
            motor_group_left.move(0); 
            motor_group_right.move(0); 
            task3 = 1;
            return;
        }
        if (num == 2){
            delay(50);
            piston.set_value(false); //up
        }
        if (num == 3 && !task4){
			intake.move(-127);	//in
			storage.move(127);	//out
			top.move(-127);		//top
            float time = millis();
            while ((millis()-time) < 500){
                int filler = 1;
            }
            task4 = 1;
            return;
        }

        if (num == 3 && !task5){
			intake.move(0);	    //in
			storage.move(0);	//out
			top.move(0);		//middle
            //back up 6 in
            // if (!moveBack(48, 42, 0)){
            //     moveBack(48,42, 0);
            //     return;
            // }
            motor_group_left.move(-50); 
            motor_group_right.move(-50); 
            delay(250);
            motor_group_left.move(0); 
            motor_group_right.move(0); 
            task5 = 1;
            return;
        } 

        if (num == 4 && !task6){
            intake.move(-127); //in
            storage.move(127); //in
            task6 = 1;
            return;
        }


        if (num == 6 && !task7){
            intake.move(127);	//out
			storage.move(127);	//out
            float time = millis();
            while ((millis()-time) < 1000){
                int filler2 = 1;
            }
            task7 = 1;
            return;
        }

        if (num == 6 && !task8){
			intake.move(0);	    //in
			storage.move(0);	//out
            //back up 6 in
            // if (!moveBack(16, 56, 315)){
            //     moveBack(16, 56, 315);
            //     return;
            // }
            motor_group_left.move(-50); 
            motor_group_right.move(-50); 
            delay(250);
            motor_group_left.move(0); 
            motor_group_right.move(0); 
            task8 = 1;
            return;
        }


        if (num == 7 && !task9){
            intake.move(-127); //in
            storage.move(127); //in
            task9 = 1;
            return;
        }


        if (num == 9 && !task10){
            intake.move(127);	//out
			storage.move(127);	//out
            task10 = 1;
            return;
        }

        if (num == sizeof(auton_red_cord)/sizeof(auton_red_cord[0])){
            return;
        }

        if (!drive_cord(auton_red_cord[num][0], auton_red_cord[num][1], auton_red_cord[num][2])){
            drive_cord(auton_red_cord[num][0], auton_red_cord[num][1], auton_red_cord[num][2]);
            return;
        }
        num ++;
        first(0);
    }  

}
