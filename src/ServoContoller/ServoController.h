#pragma once
#include "../utils/Core.hpp"
#include "../Config.h"
#include "../Timer/Timer.hpp"

class ServoController{
    int8_t CH = 0;
    int16_t initDeg = 0;
    double_t cDeg = 0;
    double_t deltaDeg = 0;
    int16_t targetDeg = 0;
    FlagTimer ftimer;

    ServoController(int8_t CH,int16_t init_deg = 0);

    inline void Update();
    inline void set(int16_t degrees,int32_t time_ms);
    inline void set(int16_t degrees);
    inline void setInit(int32_t time_ms);
    inline void setInit();
};