#pragma once
#include "DriveController.h"

template <size_t N>
inline DriveController<N>::DriveController(MotorPair<N> *motors,IMU *imu,PIDCore *pid)
:motors(motors),drive_imu(imu),drive_pid(pid){}

template <size_t N>
inline void DriveController<N>::Init(MotorPair<N> &motors_ptr)
{
    motors = &motors_ptr;
}

template <size_t N>
inline bool DriveController<N>::Update()
{
    if(CurrentUpdate==nullptr)return false;
    if(CurrentUpdate()){
        CurrentUpdate = nullptr;
        motors->stop();
        return false;
    }
    return true;
}

template <size_t N>
inline void DriveController<N>::Stop(){
    motors->stop();
    CurrentUpdate = nullptr;
}

template <size_t N>
inline void DriveController<N>::StraightDrive(PIDCore &pid){
    CurrentUpdate = StraightDriveRoutine;
    drive_pid = &pid;
    drive_pid->Init(drive_setpoint,drive_current);
    drive_pid->Start();
    drive_imu->Reset();
}

template <size_t N>
inline void DriveController<N>::RotateDrive(PIDCore &pid){
    drive_pid = RotateDriveRoutine;
    drive_pid->Init(drive_setpoint,drive_current);
    drive_pid->Start();
    drive_imu->Reset();
}

template <size_t N>
inline void DriveController<N>::CustomDrive(bool (*updateRoutine)()){
    CurrentUpdate = updateRoutine;
}

template <size_t N>
inline void DriveController<N>::SetSpeed(const int16_t &base_speed, const int16_t &max_speed){
    this->base_speed = base_speed;
    this->max_speed = max_speed;
}

template <size_t N>
inline bool DriveController<N>::StraightDriveRoutine(){
    drive_imu->Update();


    return false;
}

template <size_t N>
inline bool DriveController<N>::RotateDriveRoutine(){
    drive_imu->Update();
    

    return false;
}
