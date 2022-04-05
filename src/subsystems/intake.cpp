#include "main.h"

namespace intake {
    okapi::ControllerButton btnY(okapi::ControllerDigital::Y);
    okapi::ControllerButton btnRight(okapi::ControllerDigital::right);

    okapi::Motor motor(INTAKE);

    void init() {
        motor.setGearing(okapi::AbstractMotor::gearset::green);
        motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
        motor.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
    }

    void move(int speed) {
        motor.moveVoltage(speed * 120);
    }

    void opcontrol() {
        static bool run = false;  
        static int speed;

        if(!run && btnY.changedToPressed()) {
            speed = 100;
            run = true;  
        } else if(run && btnY.changedToPressed()) {
            run = false;
        } else if(btnRight.isPressed()) {
            run = false;
            speed = -100;
        } else if(!run) {
            speed = 0;
        }
        

        move(speed);
    }
}