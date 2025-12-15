#pragma once

/**
    @brief To self-config, copy this config file, and include this before #include <DSN-POP32.h>
    @warning To prevent errors DO NOT CHANGE any variable name.     
*/

#ifndef DSN_POP32_SELFCONFIG

// @config
/// @brief Number of motors (2 or 4)
#define _MotorNum 4

#if _MotorNum == 2
    #warning "_MotorNum == 2 isn't implemented yet."
    
    // @config
    /// @brief PIN of each motor in {left,right} format.
    constexpr int8_t _motorPINs[2] = {1,2};

#elif _MotorNum == 4
    // @config
    /// @brief PIN of each motor in {{front_left, front_right},{back_left,back_right}} format.
    constexpr int8_t _motorPINs[4][2] = {
        {1,2},   // Front
        {3,4}    // Back
    };

#else
    #warning "_MotorNum isn't set to either 2 or 4."
#endif
    

const 




#define DSN_POP32_SELFCONFIG
#endif