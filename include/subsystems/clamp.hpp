#ifndef _CLAMP_HPP_
#define _CLAMP_HPP_

//#include "okapi/api.hpp"

namespace clamp {
    extern okapi::ControllerButton btnB;
    extern okapi::ControllerButton btnDown;

    extern okapi::Motor motor;
    
    void init();
    void move(int speed);
    void opcontrol();
}

#endif // _CLAMP_HPP_