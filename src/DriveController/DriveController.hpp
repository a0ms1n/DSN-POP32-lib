#pragma once
#include "DriveController.h"

template <size_t N>
inline DriveController<N>::DriveController(MotorPair<N> *motors,IMU *imu,PIDCore *pid)
:drive_motors(motors),drive_imu(imu),drive_pid(pid){}

template <size_t N>
inline void DriveController<N>::Init(MotorPair<N> &motors_ptr)
{
    drive_motors = &motors_ptr;
}

template <size_t N>
inline bool DriveController<N>::Update()
{

    if(userCurrentUpdate != nullptr){
        if(!userCurrentUpdate()){
            userCurrentUpdate = nullptr;
            drive_motors->stop();
            return false;
        }
        return true;
    }

    if(CurrentUpdate != nullptr){
        if(!(this->*CurrentUpdate)()){
            CurrentUpdate = nullptr;
            drive_motors->stop();
            return false;
        }
        return true;
    }

    return false;
    
}

template <size_t N>
inline void DriveController<N>::Stop(){
    drive_motors->stop();
    CurrentUpdate = nullptr;
    userCurrentUpdate = nullptr;
}

template <size_t N>
inline void DriveController<N>::StraightDrive(PIDCore &pid){
    CurrentUpdate = &StraightDriveRoutine;
    drive_pid = &pid;
    drive_pid->Init(drive_setpoint,drive_current);
    drive_pid->SetDt(1);
    drive_pid->Start();
    drive_imu->Reset();
}

template <size_t N>
inline void DriveController<N>::RotateDrive(double_t angle,PIDCore &pid,double_t direction=__LEFT_ROTATE){
    CurrentUpdate = &RotateDriveRoutine;
    drive_pid = &pid;
    drive_pid->Init(drive_setpoint,drive_current);
    drive_imu->ResetWaitZero();
    drive_current = 0.0f;
    drive_setpoint = angle;
    drive_val[0] = direction;
}

template <size_t N>
inline void DriveController<N>::CustomDrive(bool (*updateRoutine)()){
    userCurrentUpdate = updateRoutine;
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
    if(!drive_imu->Update())return true;
    drive_current += drive_imu->dYaw;
    if(drive_current >= drive_setpoint){
        Stop();
        return;
    }
    drive_pid->Compute();
    int32_t out = (int32_t)drive_pid->output;
    drive_motors->run_dir_minclamp(0,out,drive_val[0]);
    return true;
}
