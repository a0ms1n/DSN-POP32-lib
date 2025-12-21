
#ifndef __DSN_POP32_CONFIG
#define __DSN_POP32_CONFIG

/**
    @brief To self-config, copy this config file, and include this before #include <DSN-POP32.h>
    @warning To prevent errors DO NOT CHANGE any variable name.     
*/

// Robot Properties //

/// @brief Define this when using IMU
//#define _enable_IMU

/// @brief Define this when using PSX
#define _enable_PSX

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
    {4,1}, // (Front Left,  Back Left)
    {3,2}  // (Front Right, Back Right)
};
#endif

/* Sensors */

/// @brief Choose which is Low/High value (White or Black);
#define __SENSOR_WB_VALUE WHITE_BLACK // White < Black
//#define __SENSOR_WB_VALUE BLACK_WHITE // Black < White

#define __SENSOR_NUM 6
constexpr int8_t __SENSOR_PINS[__SENSOR_NUM]={
    0,1,2,3,4,5
};

// Features Configuration //

/// @brief Disable motor reverse speed configuration.
//#define __DISABLE_REVERSE 

/// @brief Disable IMU functions.
//#define __DISABLE_IMU

/// @brief Enable Maze Robot Menu/Function. (IMU Tester, 4-wheels motor tester, align tester, ...)
#define __ENABLE_MAZE_ROBOT_HELPER1

/* PSX */
#define _PSX_DAT 0
#define _PSX_CMD 1
#define _PSX_SEL 2
#define _PSX_CLK 3
#define _PSX_Delay 10

// MACROS *DO NOT EDIT* //

#define __LEFT_ROTATE 1
#define __RIGHT_ROTATE -1

#endif