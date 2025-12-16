#include "IMU.h"

/// @brief Set yaw to zero.
inline void IMU::ZeroYaw(){
    Serial1.write(0XA5);Serial1.write(0X55);
}

/// @brief Set pitch and roll to zero.
/// @warning Need to stay level when calling this function.
inline void IMU::ZeroPitch(){
    Serial1.write(0XA5);Serial1.write(0X54);
}

/// @brief Toggle IMU auto mode.
inline void IMU::ToggleAutoMode(){
    Serial1.write(0XA5);Serial1.write(0X52);
}

/// @brief Toggle IMU query mode.
inline void IMU::ToggleQueryMode(){
    Serial1.write(0XA5);Serial1.write(0X51);
}

/// @brief Start IMU, blocking function, start with AutoMode.
inline void IMU::Start(){
    Serial1.begin(115200);
    ToggleAutoMode();
    ZeroYaw();
    ZeroPitch();
}

/// @brief Auto zero yaw with given precision (in degrees). 
inline void IMU::AutoZero(const double_t &precision = 0.02f){
    ZeroYaw();
    TimeoutFlag.set();
    while(true){
        if(Update() && abs(currentYaw)<=precision)break;
        if(TimeoutFlag.check()){
            ZeroYaw();
            break;
        }
    }
}


inline bool IMU::Update(){
    static int8_t idx = 0;
    TimeoutFlag.set();
    while (Serial1.available()){
        uint8_t byte = Serial1.read();
        if (idx == 0 && byte != 0xAA) continue;
            rxBuf[idx++] = byte;
            if (idx == 8) {
                idx = 0;
                if (rxBuf[7] == 0x55) {
                    currentYaw = (int16_t)(rxBuf[1] << 8 | rxBuf[2]) / 100.0f;
                    currentPitch = (int16_t)(rxBuf[3] << 8 | rxBuf[4]) / 100.0f;
                    currentRoll = (int16_t)(rxBuf[5] << 8 | rxBuf[6]) / 100.0f;
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
