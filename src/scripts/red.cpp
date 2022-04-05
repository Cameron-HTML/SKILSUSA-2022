#include "main.h"
#include "ARMS/arc.h"

void redRight() {
    // Move toward the right neutral mogo
    chassis::moveAsync(4.7, 100);

    // Delay next movement till robot is close enough to mogo
    while(chassis::position() < 1700) pros::delay(10);

    // Clamp down on the mogo
    clamp::move(100);

    // Wait till the robot has settled to continue
    chassis::waitUntilSettled();
    
    // Raise fourbar and backup
    fourbar::posMove(100, 100);

    chassis::move(-1.8, 100);

    // Delay next movement to make sure we secured the mogo
    pros::delay(300);
    clamp::move(0);

    // Lower lift for next mogo and turn toward it
    lift::move(1410, 100);
    chassis::turnAbsolute(139, 100);

    // Move toward the next mogo and wait till settled
    chassis::move(-3.0, 100);
    chassis::waitUntilSettled();

    // Lift middle neurtal mogo 
    lift::move(800, 100);

    // Wait for lift to be at right height before backing up
    pros::delay(600);
    chassis::move(3.9, 100);

    // lift::move(1530, 100);
    // pros::delay(500);

    // fourbar::posMove(2300, 100);
    // pros::delay(1250);

    // chassis::move(1.7, 80);

    // chassis::turnAbsolute(236, 90);
}

void redLeft() {
    // Move toward the right neutral mogo
    chassis::moveAsync(4.0, 100);

    // Delay next movement till robot is close enough to mogo
    while(chassis::position() < 2260) pros::delay(10);

    // Clamp down on the mogo
    clamp::move(100);

    // Wait till the robot has settled to continue
    chassis::waitUntilSettled();
    
    // Raise fourbar and backup
    fourbar::posMove(300, 100);
    chassis::move(-1.8, 90);
}

void redWP() {
    // Move toward the right neutral mogo
    chassis::moveAsync(4.3, 100);

    // Delay next movement till robot is close enough to mogo
    while(chassis::position() < 1700) pros::delay(10);

    // Clamp down on the mogo
    clamp::move(100);

    // Wait till the robot has settled to continue
    chassis::waitUntilSettled();
    
    // Raise fourbar and backup
    fourbar::posMove(100, 100);

    chassis::move(-3.1, 100);

    // Delay next movement to make sure we secured the mogo
    pros::delay(300);
    clamp::move(0);

    lift::move(1370, 100);
    chassis::turnAbsolute(-110, 100);

    chassis::move(-2.3, 80);
    lift::move(580, 100);

    pros::delay(500);
    chassis::move(2, 100);
    intake::move(100);
    
    fourbar::posMove(400, 100);

    chassis::turnAbsolute(0, 100);
    chassis::move(-.7, 100);

    // fourbar::posMove(300, 100);
    // lift::move(1000, 100);
    // pros::delay(1250);

    // lift::move(600, 100);
    // chassis::move(1, 100);

    // chassis::turnAbsolute(-55, 100);
    // chassis::move(-1.6, 100);

    // chassis::turnAbsolute(13.5, 100);

    // lift::move(1555, 100);
    // chassis::move(-7.6, 100);

    // lift::move(600, 100);
    // pros::delay(1450);

    // intake::move(100);

    // chassis::turnAbsolute(14, 100);

    // chassis::waitUntilSettled();

    // pros::delay(4000);
}