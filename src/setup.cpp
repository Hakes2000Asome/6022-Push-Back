#include "setup.h"
#include "api.h"
using namespace pros;

Motor motor_front_right (20);
Motor motor_middle_right (19);
Motor motor_back_right (18);
MotorGroup motor_group_right ({20, 19, 18});

//left motors
Motor motor_front_left (13);
Motor motor_middle_left (12);
Motor motor_back_left (14);
MotorGroup motor_group_left({-13, -12, -14});

//Scoring Motors
Motor motor_conveyor (16);
 
//inertial sensor
Imu imu_sensor(1);

//controller
Controller master (E_CONTROLLER_MASTER);

//rotation sensor
Rotation rotation_sensor(2);
