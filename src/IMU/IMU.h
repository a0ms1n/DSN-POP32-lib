#pragma once
#include "../Timer/Timer.h"

class IMU{
    public:
        double_t currentYaw,currentPitch,currentRoll;
        bool status = false;
        FlagTimer TimeoutFlag;
        uint8_t rxBuf[8];

        inline void ZeroYaw();
        inline void ZeroPitch();
        inline void ToggleQueryMode();
        inline void ToggleAutoMode();
        inline void Start();
        inline void AutoZero(const double_t &);
        inline bool Update();
        inline void UpdateTimeoutMS(const int64_t &ms);
};

IMU imu;