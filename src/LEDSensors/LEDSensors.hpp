#pragma once
#include "LEDSensors.h"

inline void LEDSensor::set_white(){
    whiteValue = readRaw();
}

inline void LEDSensor::set_black(){
    blackValue = readRaw();
}

inline void LEDSensor::calibrate(){
    readRaw();
    #if __SENSOR_WB_VALUE == WHITE_BLACK
    whiteValue = min(whiteValue,cValue);
    blackValue = max(blackValue,cValue);
    #elif __SENSOR_WB_VALUE == BLACK_WHITE
    whiteValue = max(whiteValue,cValue);
    blackValue = min(blackValue,cValue);
    #endif
}

inline int32_t LEDSensor::readRaw()
{
    cValue = analog(channel); 
    return cValue;
}

inline int32_t LEDSensor::read(){
    cValue = analog(channel);

    #if __SENSOR_WB_VALUE == WHITE_BLACK
    cValue = map(cValue,whiteValue,blackValue,0,1000);
    #elif __SENSOR_WB_VALUE == BLACK_WHITE
    cValue = map(cValue,blackValue,whiteValue,1000,0);
    #endif
    return cValue;
}

LEDSensorPair::LEDSensorPair(LEDSensor &left, LEDSensor &right)
:left(&left),right(&right){}

inline void LEDSensorPair::set_white(){
    left->set_white();
    right->set_white();
}

inline void LEDSensorPair::set_black(){
    left->set_black();
    right->set_black();
}

inline void LEDSensorPair::calibrate(){
    left->calibrate();
    right->calibrate();
}

inline int32_t LEDSensorPair::readRaw(){
    return (left->readRaw() + right->readRaw())/2;
}

inline int32_t LEDSensorPair::read(){
    return (left->read() + right->read())/2;
}

inline double_t LEDSensorPair::get_direction()
{
    return double_t();
}
