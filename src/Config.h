#ifndef __DSN_POP32_CONFIG
#define __DSN_POP32_CONFIG

/**
    @brief To self-config, copy this config file, and include this before #include <DSN-POP32.h>
    @warning To prevent errors DO NOT CHANGE any variable name.     
*/

// Robot Properties //

/* MOTOR */

/// @brief Type of robot moving part (Legs/Wheels).
//#define __USE_WHEELS
//#define __USE_LEGS

/// @brief Number of motor pairs.
#define __MOTOR_PAIRS 2

#if __MOTOR_PAIRS == 1
constexpr int8_t __MOTOR_PINS[__MOTOR_PAIRS][2] = {
    {1}, // (Left)
    {2}  // (Right)
};

#elif __MOTOR_PAIRS == 2
constexpr int8_t __MOTOR_PINS[__MOTOR_PAIRS][2] = {
    {1,2}, // (Front Left,  Back Left)
    {3,4}  // (Front Right, Back Right)
};
#endif

/* Sensors */

/// @brief Type of sensor, we're using (could be multiple)



// Features Configuration //

/// @brief Disable motor reverse speed configuration.
//#define __DISABLE_REVERSE 

/// @brief Disable IMU functions.
//#define __DISABLE_IMU

/// @brief Enable Maze Robot Menu/Function. (IMU Tester, 4-wheels motor tester, align tester, ...)
#define __ENABLE_MAZE_ROBOT_HELPER1

#endif