#include "setup.h"
#include "api.h"
using namespace pros;

//right motors
Motor motor_front_right (16);
Motor motor_middle_right (15);
Motor motor_back_right (14);
MotorGroup motor_group_right ({14, 15, 16}, pros::v5::MotorGears::blue);

//left motors
Motor motor_front_left (1);
Motor motor_middle_left (12);
Motor motor_back_left (13);
MotorGroup motor_group_left({-1, -12, -13}, pros::v5::MotorGears::blue);
 
//inertial sensor
Imu imu_sensor(21);

//controller
Controller master (E_CONTROLLER_MASTER);

//rotation sensor
Rotation r_rotation_sensor(2);
Rotation l_rotation_sensor(3);
Rotation s_rotation_sensor(5);

//intakae motor
Motor intake(9);
Motor storage(20);
Motor top(10);

//air
ADIDigitalOut piston (8);

//color sensor
Optical optical_sensor (4);