#ifndef _FOURBAR_HPP_
#define _FOURBAR_HPP_

//#include "okapi/api.hpp"

namespace fourbar {
    extern std::shared_ptr<okapi::AsyncPositionController<double, double>> liftControl;
    extern okapi::ControllerButton btnR1;
    extern okapi::ControllerButton btnR2;

    extern okapi::Motor motor;
    
    void init();
    void move(int speed);
    void posMove(int height, int speed);
    void opcontrol();
}

#endif // _FOURBAR_HPP_