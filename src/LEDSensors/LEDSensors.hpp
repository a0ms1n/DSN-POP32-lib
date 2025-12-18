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

inline void LEDSensor::reset(){
    #if __SENSOR_WB_VALUE == WHITE_BLACK
    whiteValue = INT32_MAX;
    blackValue = INT32_MIN;
    #elif #elif __SENSOR_WB_VALUE == BLACK_WHITE
    blackValue = INT32_MAX;
    whiteValue = INT32_MIN;
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

template <size_t N>
inline LEDSensorGroup<N>::LEDSensorGroup(std::array<LEDSensor*, N> sensors_ptr){
    for(uint8_t i=0;i<N;i++)sensors[i] = sensors_ptr[i];
}

template <size_t N>
inline void LEDSensorGroup<N>::set_white(){
    for(uint8_t i=0;i<N;i++)sensors[i]->set_white();
}

template <size_t N>
inline void LEDSensorGroup<N>::set_black(){
    for(uint8_t i=0;i<N;i++)sensors[i]->set_black();
}

template <size_t N>
inline void LEDSensorGroup<N>::calibrate(){
    for(uint8_t i=0;i<N;i++)sensors[i]->calibrate();
}

template <size_t N>
inline void LEDSensorGroup<N>::reset(){
    for(uint8_t i=0;i<N;i++)sensors[i]->reset();
}

template <size_t N>
inline void LEDSensorGroup<N>::readRaw(){
    for(uint8_t i=0;i<N;i++)sensors[i]->readRaw();
}

template <size_t N>
inline void LEDSensorGroup<N>::read(){
    for(uint8_t i=0;i<N;i++)sensors[i]->read();
}

template <size_t N>
inline int32_t &LEDSensorGroup<N>::get(uint8_t index){
    return this->sensors[index]->cValue;
}

template <size_t N>
inline int32_t& LEDSensorGroup<N>::getObj(uint8_t index){
    return this->sensors[index];
}
