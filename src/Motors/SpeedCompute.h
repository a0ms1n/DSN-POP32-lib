#pragma once
#include "../utils/Core.hpp"

/// @brief Class for computing speed values with acceleration.
///        You can use .current_speed to assign to motor speed.
class SpeedCompute{
    public:
        double_t raw_speed=0,_acceleration=0;
        int16_t current_speed=0,target_speed=0,min_speed=0,max_speed=255;   

        SpeedCompute(double_t){};

        /// @brief Update raw_speed, and rounded to current_speed.
        void update();

        /// @brief Set current_speed, raw_speed and target_speed to speed.
        void set(const int16_t &);

        /// @brief set target_speed.
        void set_acc(const int16_t &);
        
};