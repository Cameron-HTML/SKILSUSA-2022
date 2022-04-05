#ifndef _LIFT_HPP_
#define _LIFT_HPP_

//#include "okapi/api.hpp"

namespace lift {
    extern std::shared_ptr<okapi::AsyncPositionController<double, double>> liftControl;
    extern okapi::Motor motor;

    extern okapi::ControllerButton btnL1;
    extern okapi::ControllerButton btnL2;

    void init();
    void move(int height, int speed);
    void opcontrol();
}

#endif // _LIFT_HPP_