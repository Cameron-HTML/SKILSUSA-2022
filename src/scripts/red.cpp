#include "main.h"
#include "ARMS/arc.h"

void redRight() {
    chassis::reset();

    // Open clamp
    clamp::toggle();

    // Move toward the right neutral mogo
    chassis::moveAsync(4.7, 100);

    // Delay next movement till robot is close enough to mogo
    while(chassis::position() < 1700) pros::delay(10);

    // Clamp down on the mogo
    clamp::toggle();

    // Wait till the robot has settled to continue
    chassis::waitUntilSettled();
    
    // Raise fourbar and backup
    fourbar::posMove(100, 100);

    // Move back to get in-line with home mogo
    chassis::move(-1.8, 100);

    // Turn toward home mogo
    chassis::turnAbsolute(-110, 100);

    // Move toward home mogo
    chassis::move(-2.3, 80);
    pros::delay(500);
    lift::toggle();

    chassis::move(2, 100);
    intake::move(100);
    
    fourbar::posMove(400, 100);

    chassis::turnAbsolute(0, 100);
    chassis::move(-.7, 100);
}

void redLeft() {
    // Open clamp
    clamp::toggle();
    //pros::delay(100000);

    // Move toward the right neutral mogo
    chassis::moveAsync(3.7, 100);

    // Delay next movement till robot is close enough to mogo
    while(chassis::position() < 2350) pros::delay(10);

    // Clamp down on the mogo
    clamp::toggle();

    // Wait till the robot has settled to continue
    chassis::waitUntilSettled();
    
    // Raise fourbar and backup
    fourbar::posMove(100, 100);

    // Move back to get in-line with home mogo
    chassis::move(-2.5, 100);

    //Turn toward home mogo
    chassis::turnAbsolute(45, 100);

    // Move toward home mogo
    chassis::move(-1.0, 80);
    pros::delay(500);
    chassis::turnAbsolute(-54, 100);
    lift::toggle();

    pros::delay(500);
    chassis::move(-1.6, 100);
    lift::toggle();
    pros::delay(1000);
    intake::move(100);

    pros::delay(500);

    chassis::move(2.0, 80);
    lift::toggle();

    // chassis::move(2, 100);
    // intake::move(100);
    
    // fourbar::posMove(400, 100);

    // chassis::turnAbsolute(0, 100);
    // chassis::move(-.7, 100);
}

void redWP() {
    // Open clamp
    clamp::toggle();
    // Raise fourbar and backup
    fourbar::posMove(50, 100);
    intake::move(100);

    // Move toward the right neutral mogo
    chassis::move(6.5, 40);

    fourbar::posMove(0, 100);
    
    pros::delay(1000);

    chassis::moveAsync(1.0, 40);
    while(chassis::position() < 300) pros::delay(10);
    clamp::toggle();

    // Wait till the robot has settled to continue
    chassis::waitUntilSettled();

    // Move back to get in-line with home mogo
    chassis::move(-2.5, 100);

    //Turn toward home mogo
    chassis::turnAbsolute(45, 100);

    // Move toward home mogo
    chassis::move(-1.0, 80);
    pros::delay(500);
    chassis::turnAbsolute(-54, 100);
    lift::toggle();

    pros::delay(500);
    chassis::move(-1.6, 100);
    lift::toggle();
    pros::delay(1000);
    intake::move(100);

    pros::delay(500);

    chassis::move(2.0, 80);
    lift::toggle();

    // chassis::move(2, 100);
    // intake::move(100);
    
    // fourbar::posMove(400, 100);

    // chassis::turnAbsolute(0, 100);
    // chassis::move(-.7, 100);
}