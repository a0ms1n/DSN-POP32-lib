#pragma once
#include "../utils/Core.hpp"

/**
 * @brief Control speed of two motors, using left_speed/right_speed 
 */
class MotorPair {
    public:
        int8_t left_motor, right_motor;
        int16_t left_speed=0, right_speed=0;
        MotorPair(const int8_t left_motor,const int8_t right_motor):left_motor(left_motor),right_motor(right_motor){}


};