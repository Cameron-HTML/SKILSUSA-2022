#include "main.h"

namespace lift {
    std::shared_ptr<okapi::AsyncPositionController<double, double>> liftControl = okapi::AsyncPosControllerBuilder().withMotor(LIFT).build();
    okapi::Motor motor(-LIFT);

    okapi::ControllerButton btnL1(okapi::ControllerDigital::L1);
    okapi::ControllerButton btnL2(okapi::ControllerDigital::L2);

    void init() {
        liftControl->tarePosition();
        liftControl->setMaxVelocity(200);
    }

    void move(int height, int speed) {
        liftControl->setMaxVelocity(speed);
        liftControl->setTarget(height);
    }

    void opcontrol() {
        static int height;
        static int speed;

        if(btnL1.isPressed()) {
            liftControl->flipDisable(true);
            motor.moveVelocity(200);

            height = -motor.getPosition();
        } else if(btnL2.changedToPressed()) {
            if(height != 1470) {
                height = 1470;
                speed = 100;
            } else if(height != 620) {
                height = 620;
                speed = 300;
            }
        } else {
            if(liftControl->isDisabled())
                motor.moveVelocity(0);

            liftControl->flipDisable(false);
        }

        move(height, speed);

    }
}