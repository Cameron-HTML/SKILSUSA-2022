#ifndef _INTAKE_HPP_
#define _INTAKE_HPP_

//#include "okapi/api.hpp"

namespace intake {
    extern okapi::ControllerButton btnY;
    extern okapi::ControllerButton btnRight;

    extern okapi::Motor motor;

    void init();
    void move(int speed);
    void opcontrol();
}

#endif // _INTAKE_HPP_