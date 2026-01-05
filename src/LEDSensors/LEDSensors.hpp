#pragma once
#include "LEDSensors.h"

inline void LEDSensor::set_white(){
    whiteValue = readRaw();
}

inline void LEDSensor::set_black(){
    blackValue = readRaw();
}

inline void LEDSensor::update_mid(){
    midValue = (blackValue+whiteValue)/2;
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
    cValue = constrain(cValue,0,1000);
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
inline void LEDSensorGroup<N>::update_mid()
{
    for(uint8_t i=0;i<N;i++)sensors[i]->update_mid();
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

template <size_t N>
inline int32_t LEDSensorLine<N>::readLine(bool do_read = true){
    if(do_read)this->read();
    cOnline = false;
    int32_t avg = 0;
    int32_t sum = 0;

    for (uint8_t idx = 0;idx < N;idx++){
        int32_t val = this->get(idx);
        if(val > __Track){
            cOnline = true; 
        }
        if(val > __Noise){
            avg += (int32_t)val*(idx*1000);
            sum += val;
        }
    }
    if(!cOnline){
        if(!__AutoRotate)return cPosition; 
        if (cPosition < __MIDDLE_VALUE){
            cPosition = 0;
            return 0;
		}
		else{
            cPosition = __RIGHT;
			return __RIGHT;
		}
    }
    cPosition = avg/sum;
    return cPosition;
}

template <size_t N>
inline int32_t LEDSensorLine<N>::errorFromMid(){
    return __MIDDLE_VALUE - cPosition;
}

template <size_t N>
inline int32_t LEDSensorLine<N>::posFromMid(double_t pos){
    return __MIDDLE_VALUE + pos*1000.0;
}

template <size_t N>
inline int32_t LEDSensorLine<N>::isTrack(int32_t pos){
    return get(pos) >= __Track;
}
