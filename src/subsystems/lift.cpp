#include "main.h"

namespace lift {
    okapi::ControllerButton btn(okapi::ControllerDigital::L1);

    pros::ADIDigitalOut piston(BACK_CLAMP);

    void init() {
        //toggle();
    }

    void toggle() {
        static bool state = false;
        state = !state;

        piston.set_value(state);
    }
    
    void opcontrol() {
        if(btn.changedToPressed()) {
            toggle();
        }
    }
}