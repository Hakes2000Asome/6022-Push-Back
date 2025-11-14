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
MotorGroup motor_group_left({-11, -12, -13}, pros::v5::MotorGears::blue);
 
//inertial sensor
// Imu imu_sensor(21);

//controller
Controller master (E_CONTROLLER_MASTER);

//rotation sensor
// Rotation r_rotation_sensor(2);
// Rotation l_rotation_sensor(3);
// Rotation s_rotation_sensor(5);

//intakae motor
<<<<<<< HEAD
Motor intake(1);
Motor railgun(2);
=======
// Motor intake(9);
// Motor storage(20);
// Motor top(10);
Motor conveyor(1);
Motor railGun(2);
>>>>>>> 3ea4bf85abb572bfa303ac524f1c60cce786a76d

//air
ADIDigitalOut piston ('G');

//color sensor
// Optical optical_sensor (4);