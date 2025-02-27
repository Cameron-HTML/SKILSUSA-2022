#ifndef _CONFIG_H_
#define _CONFIG_H_

// Drivetrain configuration constants
namespace chassis {
// negative numbers mean reversed motor
#define LEFT_MOTORS -16, 13, -11
#define RIGHT_MOTORS 6, -1, 2
#define GEARSET 257 // rpm of chassis motors

#define DISTANCE_CONSTANT 650 // ticks per distance unit
#define DEGREE_CONSTANT 2.3   // ticks per degree

// chassis settling constants
#define SETTLE_TIME 3
#define SETTLE_THRESHOLD_LINEAR 3
#define SETTLE_THRESHOLD_ANGULAR 1

// slew control (autonomous only)
#define ACCEL_STEP 8 // smaller number = more slew
#define ARC_STEP 5   // acceleration for arcs

// sensors
#define IMU_PORT 14            // port 0 for disabled
#define ENCODER_PORTS 0, 0, 0 // port 0 for disabled
#define EXPANDER_PORT 0
#define JOYSTICK_THRESHOLD 10 // min value needed for joystick to move drive
} // namespace chassis

namespace odom {
#define ODOM_DEBUG 1
#define LEFT_RIGHT_DISTANCE 0 // only needed for non-imu setups
#define MIDDLE_DISTANCE 0     // only needed if using middle tracker
#define LEFT_RIGHT_TPI 41.4       // Ticks per inch
#define MIDDLE_TPI 41.4           // Ticks per inch
#define SLEW_STEP 10              // point function slew
#define HOLONOMIC 0               // holonomic chassis odom
#define EXIT_ERROR 10 // exit distance for moveThru and holoThru movements
} // namespace odom

namespace pid {
#define PID_DEBUG false

// normal pid constants
#define LINEAR_KP 2.0
#define LINEAR_KI 0
#define LINEAR_KD 3.2
#define ANGULAR_KP 8.0
#define ANGULAR_KI 0
#define ANGULAR_KD 50.0
#define ARC_KP .05
#define DIF_KP .5

// odom point constants
#define LINEAR_POINT_KP 8
#define LINEAR_POINT_KI 0
#define LINEAR_POINT_KD 0
#define ANGULAR_POINT_KP 50
#define ANGULAR_POINT_KI 0
#define ANGULAR_POINT_KD 0
#define MIN_ERROR 5 // minimum error, stops robot from spinning around point
} // namespace pid

// Auton selector configuration constants
namespace selector {
// Names of autonomi, up to 10
#define AUTONS "Left", "Right", "MP Auto", "Do Nothing"
#define HUE 360   // Color of theme from 0-359(H part of HSV)
#define DEFAULT 1 // Default auton numbers
} // namespace selector

#endif
