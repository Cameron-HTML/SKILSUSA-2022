#include "main.h"

#include "okapi/api.hpp"

namespace clamp {
    okapi::ControllerButton btnB(okapi::ControllerDigital::B);
    okapi::ControllerButton btnDown(okapi::ControllerDigital::down);

    okapi::Motor motor(CLAMP);

    void init() {
        motor.setGearing(okapi::AbstractMotor::gearset::green);
        motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
        motor.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
    }

    void move(int speed) {
        motor.moveVelocity(speed);
    }
    
    void opcontrol() {
        if(btnB.isPressed()) {
            move(200);
        } else if(btnDown.isPressed()) {
            move(-200);
        } else {
            move(0);
        }
    }
}