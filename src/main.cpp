#include "main.h"
#include "setup.h"
#include "api.h"
#include "Odometry.h"
#include "funtions.h"

using namespace pros;


	
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
 //right motors
   

void initialize() {
	imu_sensor.reset();
	pros::lcd::initialize();
	imu_sensor.tare_heading();
	rotation_sensor.reset_position();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	while(imu_sensor.is_calibrating() == 1){
    printf("imu_sensor is calibrating");
  	}
	while (true) {
/*
		//drive
		motor_group_right.move(master.get_analog(ANALOG_RIGHT_Y));
		motor_group_left.move(master.get_analog(ANALOG_LEFT_Y));
	
		//intake
		if (master.get_digital(DIGITAL_R2)) {
			motor_intake.move(100);  // forward 
		} 
		else if (master.get_digital(DIGITAL_R1)) {
			motor_intake.move(-100); //backward
		} 
		else {
			motor_intake.move(0);  
		}

		//ball remover
		if (master.get_digital(DIGITAL_Y)) {
			piston.set_value(true);  // down 
		} 
	 	if (master.get_digital(DIGITAL_B)) {
			piston.set_value(true); //up
		} 


*/
int wheel_diameter = 2.625;
float wheel_ratio = (wheel_diameter*3.14159)/36000;
		pros::lcd::clear_line(0);
		pros::lcd::clear_line(1);
		pros::lcd::clear_line(2);
		pros::lcd::clear_line(3);
		pros::lcd::print(0, "x: %d\n", current_x_pose());
		pros::lcd::print(1, "y: %d\n", current_y_pose());
		pros::lcd::print(2, (2*3*rotation_sensor.get_position())/36000);		
		pros::lcd::print(3, "Heading: %f degrees\n", accurate_angle());
		trackposition();
		delay(50);
	}
}