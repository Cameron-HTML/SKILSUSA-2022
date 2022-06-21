#include "main.h"

namespace fourbar {
    okapi::Motor motor(FOURBAR);

    std::shared_ptr<okapi::AsyncPositionController<double, double>> liftControl = okapi::AsyncPosControllerBuilder().withMotor(motor).build();

    okapi::ControllerButton btnR1(okapi::ControllerDigital::R1);
    okapi::ControllerButton btnR2(okapi::ControllerDigital::R2);

    void init() {
        motor.tarePosition();
        liftControl->tarePosition();

        motor.setGearing(okapi::AbstractMotor::gearset::red);
        motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
        motor.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);
    }

    void posMove(int height, int speed) {
        liftControl->flipDisable(false);
        liftControl->setMaxVelocity(speed);
        liftControl->setTarget(height);
    }

    void move(int speed) {
        liftControl->flipDisable(true);
        motor.moveVelocity(speed);
    }

    void opcontrol() {
        static int speed;

        if(btnR1.isPressed()) {
            speed = 100;
        } else if(btnR2.isPressed()) {
            speed = -100;
        } else {
            speed = 0;
        }

        move(speed);

    }
}