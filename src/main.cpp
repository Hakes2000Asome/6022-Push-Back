#include "main.h"
#include "setup.h"
#include "api.h"
#include "Odometry.h"
#include "funtions.h"
#include "Drive.h"
#include "auton.h"
#include "PID.h"



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
	l_rotation_sensor.reset_position();
	r_rotation_sensor.reset_position();
	s_rotation_sensor.reset_position();
	motor_group_left.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	motor_group_right.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
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
void autonomous() {
	while(1){
	auton_red();
	delay(100);
	
/*
	motor_group_left.move(127); 
    motor_group_right.move(127); 
    delay(250);
    motor_group_left.move(0); 
    motor_group_right.move(0); 
	*/

	}
}

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
    printf("sensor is calibrating");
  	}

	//base_color();

	while (true) {

		pros::lcd::clear_line(0);
		pros::lcd::clear_line(1);
		pros::lcd::clear_line(2);
		pros::lcd::clear_line(3);
		pros::lcd::clear_line(4);
		pros::lcd::print(0, "x: %f", current_x_pose());
		pros::lcd::print(1, "y: %f", current_y_pose());
 		pros::lcd::print(2, "degrees %f", accurate_angle());   
		pros::lcd::print(3, "color %d", color());   
  

		//drive
		motor_group_right.move(pow(master.get_analog(ANALOG_RIGHT_Y), 2)/127 *master.get_analog(ANALOG_RIGHT_Y)/abs(master.get_analog(ANALOG_RIGHT_Y)));
		motor_group_left.move(pow(master.get_analog(ANALOG_LEFT_Y), 2)/127 *master.get_analog(ANALOG_LEFT_Y)/abs(master.get_analog(ANALOG_LEFT_Y)));

		//intake
		if (master.get_digital(DIGITAL_R2)) {
			intake.move(127); 	//out
			storage.move(127);	//out
		} 
		else if (master.get_digital(DIGITAL_R1)) {
			intake.move(-127);	//in
			storage.move(-127);	//in
		} 
		else if (master.get_digital(DIGITAL_L1)) {
			intake.move(-127);	//in
			storage.move(127);	//out
			top.move(-127);		//top
		}
		else if (master.get_digital(DIGITAL_L2)){
			intake.move(-110);	//in
			storage.move(127);	//out
			top.move(127);		//middle
		}
		else {
			intake.move(0);  
			storage.move(0);
			top.move(0);
		}
 
		//ball remover
		if (master.get_digital(DIGITAL_Y)) {
			piston.set_value(true);  //down 
		} 
	 	if (master.get_digital(DIGITAL_B)) {
			piston.set_value(false);  //up
		} 
		
		
		int wheel_diameter = 2.625;
		float wheel_ratio = (wheel_diameter*3.14159)/36000;

        trackposition();
		delay(100);

	}
}
