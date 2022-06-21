#include "main.h"
#include "ARMS/chassis.h"

okapi::Controller master;
okapi::MotorGroup leftMotors = {DRIVE_LEFT_1, DRIVE_LEFT_2};
okapi::MotorGroup rightMotors = {DRIVE_RIGHT_1, DRIVE_RIGHT_2};

std::shared_ptr<okapi::ChassisController> driveControl =
	okapi::ChassisControllerBuilder()
		.withMotors(
			{DRIVE_LEFT_1, DRIVE_LEFT_2},
			{DRIVE_RIGHT_1, DRIVE_RIGHT_2}
		)
		.withDimensions(okapi::AbstractMotor::gearset::blue, {{4_in, 11.5_in}, okapi::imev5BlueTPR})
        .build();

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	selector::init();
	pid::init();
	chassis::init();
	
	chassis::reset();

	lift::init();
	intake::init();
	fourbar::init();
	clamp::init();
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
	switch(selector::auton) {
		case 1:
			redLeft();
		break;
		case 2:
			redRight();
		break;
		case 3:
			redWP();
		break;
		case 0:
			chassis::move(4.0, 100);
		break;
		
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
	while(true) {
		// button to start autonomous for testing
		if(master.getDigital(okapi::ControllerDigital::A) && !pros::competition::is_connected()) {
			std::cout << "Starting auto" << std::endl;
			autonomous();
		}

		lift::opcontrol();
		intake::opcontrol();
		fourbar::opcontrol();
		clamp::opcontrol();

		chassis::tank(master.getAnalog(okapi::ControllerAnalog::leftY) * (double)100, master.getAnalog(okapi::ControllerAnalog::rightY) * (double)100);

		pros::delay(20);
	}
}
