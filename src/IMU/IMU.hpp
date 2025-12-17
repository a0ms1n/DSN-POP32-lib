#pragma once
#include "IMU.h"

IMU imu;

/// @brief Set yaw to zero.
/// @warning delay for 120 ms, and ALWAYS use .Toggle before.
inline void IMU::ZeroYaw(){

    //Zero Pitch
    Serial1.write(0XA5);Serial1.write(0X54); 
    delay(60);
    //Zero Yaw
    Serial1.write(0XA5);Serial1.write(0X55);
    delay(60);
}

inline void IMU::Reset(){
    ZeroYaw();
    ToggleAutoMode();
}

/// @brief Toggle IMU auto mode.
/// @warning delay for 60 ms.
inline void IMU::ToggleAutoMode(){
    Serial1.write(0XA5);Serial1.write(0X52);
    delay(60);
}

/// @brief Toggle IMU query mode.
/// @warning delay for 60 ms.
inline void IMU::ToggleQueryMode(){
    Serial1.write(0XA5);Serial1.write(0X51);
    delay(60);
}

/// @brief Start IMU, blocking function, start with AutoMode.
/// @warning delay for 180 ms.
inline void IMU::Start(){
    Serial1.begin(115200);
    while(!Serial1.availableForWrite()){
        beep();
        delay(10);
    }
    Reset();
    
}

/// @brief Auto zero yaw with given precision (in degrees). 
void IMU::AutoZero(const double_t &_precision){
    precision = _precision;
    ZeroYaw();
    TimeoutFlag.set();
    while(true){
        if(Update() && abs(cYaw)<=precision)break;
        if(TimeoutFlag.check()){
            ZeroYaw();
            break;
        }
    }
}

/// @brief Auto zero yaw with given precision (in degrees). 
void IMU::AutoZero(){
    ZeroYaw();
    TimeoutFlag.set();
    while(true){
        if(Update() && abs(cYaw)<=precision)break;
        if(TimeoutFlag.check()){
            ZeroYaw();
            break;
        }
    }
}


bool IMU::Update(){
    static int8_t idx = 0;
    TimeoutFlag.set();
    while (Serial1.available()){
        uint8_t byte = Serial1.read();
        if (idx == 0 && byte != 0xAA) continue;
            rxBuf[idx++] = byte;
            if (idx == 8) {
                idx = 0;
                if (rxBuf[7] == 0x55) {
                    cYaw = (int16_t)(rxBuf[1] << 8 | rxBuf[2]) / 100.0f;
                    cPitch = (int16_t)(rxBuf[3] << 8 | rxBuf[4]) / 100.0f;
                    cRoll = (int16_t)(rxBuf[5] << 8 | rxBuf[6]) / 100.0f;
                    status = true;
                    return true;
                }
        }
        if(TimeoutFlag.check())break;
    }
    status = false;
    return false;
}

inline void IMU::UpdateTimeoutMS(const int64_t &ms){
    this->TimeoutFlag.set(ms);
}
