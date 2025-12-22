#pragma once
#include "../Config.h"
#ifdef _enable_Servo
#include "ServoController.h"


void ServoController::Update(){
    if(ftimer.check()){
        cDeg = targetDeg;
        servo(CH,(int16_t)cDeg);
        return;
    }
    cDeg = deltaDeg*ftimer.gap(false);
    servo(CH,(int16_t)cDeg);
}

inline void ServoController::set(int16_t degrees, int32_t time_ms){
    ftimer.set();
    targetDeg = degrees;
    deltaDeg = (targetDeg - (int16_t)cDeg)/(double_t)time_ms;
}

inline void ServoController::set(int16_t degrees){
    servo(CH,degrees);
}

inline void ServoController::setInit(int32_t time_ms){
    ftimer.set();
    cDeg = initDeg;
    targetDeg = initDeg;
    deltaDeg = (targetDeg - cDeg)/(double_t)time_ms;
}

inline void ServoController::setInit(){
    servo(CH,initDeg);
}

#endif