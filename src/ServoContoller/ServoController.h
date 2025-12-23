#pragma once
#include "../utils/Core.hpp"
#include "../Config.h"
#include "../Timer/Timer.hpp"

class ServoController{
    public:
    int8_t CH = 0;
    int16_t initDeg = 0;
    double_t cDeg = 0;
    int16_t outMin = 0, outMax = 180;

    ServoController(int8_t CH,int16_t init_deg = 0,int16_t outMin=0,int16_t outMax=180):
    CH(CH),cDeg(init_deg),initDeg(init_deg),outMin(outMin),outMax(outMax){initDeg = constrain(initDeg,outMin,outMax);}

    inline void Update();
    inline void set(int16_t degrees);
    inline void setInit();
    inline void free();
};