#pragma once
#include "../Timer/Timer.hpp"

class IMU{
    public:
        double_t cYaw=0,cPitch=0,cRoll=0;
        double_t pvYaw=0;
        double_t dYaw = 0;
        bool status = false;
        int64_t reset_timeout = 3500;
        uint8_t rxBuf[8];
        double_t precision = 0.7f;
        FlagTimer TimeoutFlag = FlagTimer(20);
        inline void ZeroYaw();
        inline void Reset();
        inline void ResetWaitZero(double_t precision);
        inline void ResetWaitZero();
        inline void ToggleQueryMode();
        inline void ToggleAutoMode();
        inline void Start();
        bool Update();
        inline void UpdateTimeoutMS(const int64_t &ms);
};
