#pragma once
#include "../Timer/Timer.h"

class IMU{
    public:
        double_t currentYaw,currentPitch,currentRoll;
        bool status = false;
        FlagTimer TimeoutFlag;
        uint8_t rxBuf[8];

        void ZeroYaw();
        void ZeroPitch();
        void ToggleQueryMode();
        void ToggleAutoMode();
        void Start();
        void AutoZero(const double_t &);
        bool Update();
        void UpdateTimeoutMS(const int64_t &ms);
};
