#include "api.h"
using namespace pros;

    //right motors
    extern Motor motor_front_right;
    extern Motor motor_middle_right;
    extern Motor motor_back_right;
    extern MotorGroup motor_group_right;

    //left motors
    extern Motor motor_front_left;
    extern Motor motor_middle_left;
    extern Motor motor_back_left;
    extern MotorGroup motor_group_left;
 
    //inertial sensor
    extern Imu imu_sensor;

    //controller
    extern Controller master;

    //rotation sensor
    extern Rotation r_rotation_sensor;
    extern Rotation l_rotation_sensor;
    extern Rotation s_rotation_sensor;

    //intakae motor
    extern Motor intake;
    extern Motor storage;
    extern Motor top;

    //air
    extern ADIDigitalOut piston;

    //color sensor
    extern Optical optical_sensor;

