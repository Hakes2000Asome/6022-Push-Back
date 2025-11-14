#include "auton.h"
#include "Drive.h"
#include "api.h"
#include "Odometry.h"
#include "setup.h"
#include "funtions.h"

using namespace pros;
bool task0 = 0;
bool task1 = 0;
bool task2 = 0;
bool task1_5 = 0;
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
/*1*/    {44, 18, 180}, // first position

/*2*/    {49, 15, 179},  //moving towards the loader
//needs to back up 
/*3*/    {50.8, 32, 0}, //Scoring top 4x
//needs to back up
/*4*/    {28, 32, 0}, //get to the position before rotating to get the next two pieces in the middle
/*5*/    {28, 54, 0}, //get the two pieces
/*6*/    {16, 55, 315}, //scoring in the bottom 2x 
//needs to back up
/*7*/    {-6, 48, 270}, // position before picking up the next three pieces 
/*8*/    {-24, 48, 45}, //picking up the next three pieces and angle for scoring
/*9*/    {-11, 59.5, 45} // scoring on middle 3x
    
};

int num = 0;

void auton_red(){
    if (1){
        pros::lcd::clear_line(4);
        pros::lcd::print(4, "num: %d", num);

        if (num == 1 && !task1){
            piston.set_value(true); //down
            intake.move(-127);  //in
            storage.move(-127);  //in
            task1 = 1;
        }

        if (num == 2 && !task2){
            intake.move(-127);  //in
            storage.move(-127);  //in
            motor_group_left.move(100); 
            motor_group_right.move(100); 
            delay(50);
            motor_group_left.move(0); 
            motor_group_right.move(0); 
            if (!(color() == 2) && millis() < 5000){
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
            motor_group_left.move(-127); 
            motor_group_right.move(-127); 
            delay(125);
            motor_group_left.move(0); 
            motor_group_right.move(0); 
            task3 = 1;
            return;
        }
        if (num == 2){
            piston.set_value(false); //up
        }
        if (num == 3 && !task4){
			intake.move(-127);	//in
			storage.move(127);	//out
			top.move(-127);		//top
            float time = millis();
            while ((millis()-time) < 3000){
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

        if (num == 4){
            intake.move(-127); //in
            storage.move(-127); //in
        }


        if (num == 6 && !task7){
            intake.move(110);	//out
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


        if (num == 7){
            intake.move(-127); //in
            storage.move(-127); //in
        }


        if (num == 9){
            intake.move(-127);	//out
			storage.move(127);	//out
            top.move(127);
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

float auton_test_cord[][3] = 
{
    //x     y      heading
/*1*/       {0, 30, 0}, // first position
/*2*/       {30,}
/*10*/
    
};

void auton_test(){
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
