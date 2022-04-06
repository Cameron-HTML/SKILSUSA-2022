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
			//chassis::resetAngle(0.0);

			// Lower the lift to pick up mobile goal sitting on platform
			lift::move(1450, 100);
			pros::delay(750);

			// Move towards the mobile goal
			chassis::move(-1.4, 70);

			// Lift the mobile goal up
			lift::move(525, 100);
			pros::delay(750);

			// Turn 80 degrees to the left
			chassis::turnAbsolute(-80, 100);

			// Move foward to avoid hitting platform during next movement
			chassis::move(-1.4, 50);
			pros::delay(500);

			// Turn 173 degrees to the right to face the neutral mobile goal
			chassis::turnAbsolute(93, 100);

			// Move towards the neutral mobile goal
			chassis::moveAsync(7.5, 80);

			// Turn on the intake while moving foward to stack rings
			intake::move(100);

			// Delay the program until the robot is close enough to the mobile goal
			while(chassis::position() < 1700) pros::delay(10);

			// Clamp down on the mogo
			clamp::move(100);

			// Wait till the robot has settled to continue
			chassis::waitUntilSettled();

			// Turn down clamp speed to hold on to the mobile goal
			clamp::move(10);

			// Slightly raise the mobile goal so it does not drag during the next movement
			fourbar::posMove(200, 100);
			pros::delay(500);

			// Turn the robot to heading 180 degrees
			chassis::turnAbsolute(180, 100);

			// Move forward to center with blue platform
			chassis::moveAsync(3.5, 70);

			// Raise the fourbar so that the neutral mobile goal can be stacked
			fourbar::posMove(1000, 100);

			// Lower lift to release the blue mobile goal at the back
			lift::move(1450, 100);

			// Wait until the chassis has settled to continue
			chassis::waitUntilSettled();

			// Turn the robot to heading 78 degees
			chassis::turnAbsolute(78, 100);

			// Move foward without a PID to get in position to place the mobile goal
			chassis::fast(.05, 50);

			// Lower fourbar and raise lift
			pros::delay(500);
			fourbar::posMove(300, 100);
			lift::move(200, 100);
			pros::delay(1000);

			// Open the clamp to stack the neutral mobile goal
			clamp::move(-100);
			pros::delay(500);

			// Raise the fourbar to prepare for next movement
			fourbar::posMove(1000, 100);
			pros::delay(500);

			// Move backward to get in place for the next mobile goal
			chassis::move(-1.5, 70);

			// Lower the fourbar to be able to clamp down on mobile goal
			fourbar::posMove(10, 100);

			// Turn to heading 0 degrees
			chassis::turnAbsolute(0, 100);

			// Move toward the mobile goal
			chassis::moveAsync(3.0, 60);

			// Delay the code till close enough to the mobile to clamp down
			while(chassis::position() < 1200) pros::delay(10);

			// Clamp down on the mogo
			clamp::move(100);

			// Wait till the robot has settled to continue
			chassis::waitUntilSettled();

			// Raise fourbar after picking up mobile goal
			fourbar::posMove(1000, 100);

			// Slow down the clamp to keep hold
			clamp::move(10);

			// Move backward to center with the platform
			chassis::move(-3.5, 70);

			// Turn toward the platform
			chassis::turnAbsolute(78, 100);

			// Move toward the platform to place the mobile goal
			chassis::fast(.01, 50);
			pros::delay(1000);

			fourbar::posMove(300, 100);
			lift::move(200, 100);
			pros::delay(1000);

			clamp::move(-100);
			pros::delay(500);
			fourbar::posMove(1000, 100);
			pros::delay(500);

			chassis::move(-2.0, 70);

			chassis::turnAbsolute(180, 100);

			lift::move(0, 100);
			chassis::voltage(3000, 60, 60);

			chassis::move(-1.0, 70);
			fourbar::posMove(10, 100);

			chassis::turnAbsolute(-90, 100);
			chassis::voltage(4000, -60, -60);

			chassis::move(2.0, 70);

			fourbar::posMove(1000, 100);
			chassis::turnAbsolute(-42, 100);

			chassis::moveAsync(16, 80);

			// Wait till the robot has settled to continue
			chassis::waitUntilSettled();

			chassis::move(-1.5, 80);
			chassis::turnAbsolute(-3, 100);
			lift::move(1450, 100);

			chassis::move(-11, 80);

			lift::move(500, 100);

			pros::delay(1000);
			fourbar::posMove(10, 100);
			chassis::move(2.0, 80);
			chassis::turnAbsolute(91, 100);

			// Move towards the neutral mobile goal
			chassis::moveAsync(7.5, 80);

			// Delay the program until the robot is close enough to the mobile goal
			while(chassis::position() < 1700) pros::delay(10);

			// Clamp down on the mogo
			clamp::move(100);

			// Wait till the robot has settled to continue
			chassis::waitUntilSettled();

			clamp::move(10);

			chassis::turnAbsolute(0, 100);

			// Move forward to center with blue platform
			chassis::moveAsync(2.8, 70);

			// Raise the fourbar so that the neutral mobile goal can be stacked
			fourbar::posMove(1000, 100);

			// Lower lift to release the blue mobile goal at the back
			lift::move(1450, 100);

			// Wait until the chassis has settled to continue
			chassis::waitUntilSettled();

			// Turn the robot to heading 78 degees
			chassis::turnAbsolute(78, 100);

			// Move foward without a PID to get in position to place the mobile goal
			chassis::fast(.05, 50);

			// Lower fourbar and raise lift
			pros::delay(500);
			fourbar::posMove(300, 100);
			lift::move(200, 100);
			pros::delay(1000);

			// Open the clamp to stack the neutral mobile goal
			clamp::move(-100);
			pros::delay(500);

			// Raise the fourbar to prepare for next movement
			fourbar::posMove(1000, 100);
			pros::delay(500);

			// Move backward to get in place for the next mobile goal
			chassis::move(-2.0, 70);

			// Lower the fourbar to be able to clamp down on mobile goal
			fourbar::posMove(10, 100);

			// Turn to heading 0 degrees
			chassis::turnAbsolute(180, 100);

			// Move toward the mobile goal
			chassis::moveAsync(2.6, 60);

			// Delay the code till close enough to the mobile to clamp down
			while(chassis::position() < 900) pros::delay(10);

			// Clamp down on the mogo
			clamp::move(100);

			// Wait till the robot has settled to continue
			chassis::waitUntilSettled();
			

			pros::delay(10000000);

			// lift::move(1450, 100);
			// pros::delay(750);
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

		

		//driveControl->getModel()->tank(master.getAnalog(okapi::ControllerAnalog::leftY), master.getAnalog(okapi::ControllerAnalog::rightY));

		chassis::tank(master.getAnalog(okapi::ControllerAnalog::leftY) * (double)100, master.getAnalog(okapi::ControllerAnalog::rightY) * (double)100);

		pros::delay(20);
	}
}
