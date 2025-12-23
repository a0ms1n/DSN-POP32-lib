#pragma once
#include "../Config.h"
#ifdef _enable_Servo
#include "ServoController.h"


void ServoController::Update(){
    cDeg = constrain(cDeg,outMin,outMax);
    servo(CH,cDeg);
}


inline void ServoController::set(int16_t degrees){
    degrees = constrain(degrees,outMin,outMax);
    servo(CH,degrees);
}

inline void ServoController::setInit(){
    servo(CH,initDeg);
}

inline void ServoController::free(){
    servo(CH,-1);
}

#endif