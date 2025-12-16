#pragma once
#include "../PIDCore/PIDCore.hpp"
#include "../utils/Core.hpp"
#include "../Motors/Motors.hpp"
#include "../IMU/IMU.hpp"
#include "../Timer/Timer.hpp"


/// @brief Attach to MotorPair, to control robot drive, can only do ONE drive mode at a time.
template<size_t N=2>
class DriverController{
    public:
        MotorPair<N> *motors = nullptr;
        void (*CurrentUpdate)() = nullptr;

        int16_t base_speed = 100;
        int16_t max_speed = 200;
        int16_t min_speed = 10;
        
        /// @brief Call this function periodically to update.
        void Update();

        /// @brief Terminate all driving.
        void Stop();

        void Rotate()
        
};