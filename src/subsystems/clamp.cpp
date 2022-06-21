#include "main.h"

#include "okapi/api.hpp"

namespace clamp {
    okapi::ControllerButton btn(okapi::ControllerDigital::L2);

    pros::ADIDigitalOut piston(FRONT_CLAMP);

    void init() {
        toggle();
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