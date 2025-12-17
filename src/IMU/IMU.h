#pragma once
#include "../Timer/Timer.hpp"

class IMU{
    public:
        double_t currentYaw,currentPitch,currentRoll;
        bool status = false;
        FlagTimer TimeoutFlag;
        uint8_t rxBuf[8];
        double_t precision = 0.1f;

        inline void ZeroYaw();
        inline void ZeroPitch();
        inline void ToggleQueryMode();
        inline void ToggleAutoMode();
        inline void Start();
        void AutoZero(const double_t &);
        void AutoZero();
        bool Update();
        inline void UpdateTimeoutMS(const int64_t &ms);
};
