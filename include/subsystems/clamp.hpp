#ifndef _CLAMP_HPP_
#define _CLAMP_HPP_

//#include "okapi/api.hpp"

namespace clamp {
    extern okapi::ControllerButton  btn;

    extern pros::ADIDigitalOut piston;
    
    void init();
    void toggle();
    void opcontrol();
}

#endif // _CLAMP_HPP_