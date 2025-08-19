#include setup.h;

void setup(){

    //right motors
    pros::Motor motor_front_right (1);
    pros::Motor motor_middle_right (2);
    pros::Motor motor_back_right (3);
    pros::Motor_Group motor_group_right ({motor_front_right, motor_middle_right, motor_back_right});

    //left motors
    pros::Motor motor_front_left (4);
    pros::Motor motor_middle_left (5);
    pros::Motor motor_back_left (6);
    pros::Motor_Group motor_group_right ({motor_front_left, motor_middle_left, motor_back_left});

    //inertial sensor
    pros::Imu imu_sensor(IMU_PORT);
    imu_sensor.reset();
    
}