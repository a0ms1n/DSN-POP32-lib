#pragma once
#include "../utils/Core.hpp"
#include <array>

/**
 * @brief Control speed of two motor groups, using left_speed/right_speed for each motor in the same group.
 * @example MotorPair<1>({1},{2}).
 */
template<size_t N=2>
class MotorPair {
    public:
        std::array<int8_t, N> leftGroup, rightGroup;
        std::array<double_t, N> leftRatio, rightRatio;
        int16_t left_speed=0, right_speed=0;
        int16_t max_speed=255;
        int16_t min_speed=65;

        /// @brief Base speed for general purpose.
        int32_t base_speed = 100;

        MotorPair(const int8_t (&left_pins)[N], const int8_t (&right_pins)[N]) : leftGroup(), rightGroup() {
            for (size_t i = 0; i < N; ++i) {
                leftGroup[i] = left_pins[i];
                rightGroup[i] = right_pins[i];
                leftRatio[i] = 1.0;
                rightRatio[i] = 1.0;
            }
        }
        
        /// @brief Set speed of both motor groups to `left_speed` and `right_speed`
        inline void update();

        /// @brief Assign value to `left_speed` and `right_speed`
        inline void set(const int16_t &left_speed, const int16_t &right_speed);
        inline void set_minclamp(const int16_t &left_speed,const int16_t &right_speed);

        
        inline void run();
        /// @brief Assign value & set speed of both motor groups to `left_speed` and `right_speed`.
        inline void run(const int16_t &left_speed, const int16_t &right_speed);
        inline void run_minclamp(const int16_t &left_speed,const int16_t &right_speed);

        /// @brief Assign value & set normalized speed by direction [-1,1] (Left-Right)
        /// >0 : Left , <0 : Right  
        inline void run_dir(int16_t speed,const int16_t angular_vel,double_t direction);
        inline void run_dir_minclamp(int16_t speed,const int16_t angular_vel,double_t direction);

        /// @brief Stop both motor groups.
        inline void stop();

        /// @brief Set ratio for motors in both groups.
        void setRatio(const double_t (&left_ratio)[N], const double_t (&right_ratio)[N]);

        /// @brief Set speed to (max,min) speed (positive value)
        void setSpeedRange(const int16_t &min_speed=0,const int16_t &max_speed=255);
};

/// @brief Set power in the range [-255,255] to a motor.
void motor255(const int8_t ch, const int16_t pow);

