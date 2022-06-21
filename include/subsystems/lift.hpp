#ifndef _LIFT_HPP_
#define _LIFT_HPP_

//#include "okapi/api.hpp"

namespace lift {
    extern okapi::ControllerButton btn;

    extern pros::ADIDigitalOut piston;
    
    void init();
    void toggle();
    void opcontrol();
}

#endif // _LIFT_HPP_