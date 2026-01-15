#pragma once
#include "DriveController.h"

#ifdef _enable_IMU
template <size_t N>
inline DriveController<N>::DriveController(MotorPair<N> *motors,IMU *imu,PIDCore *pid)
:drive_motors(motors),drive_imu(imu),drive_pid(pid){}
#else
template <size_t N>
inline DriveController<N>::DriveController(MotorPair<N> *motors,PIDCore *pid)
:drive_motors(motors),drive_pid(pid){}
#endif

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
inline void DriveController<N>::ClearDrive(){
    CurrentUpdate = nullptr;
    userCurrentUpdate = nullptr;
}


#ifdef _enable_IMU


template <size_t N>
inline void DriveController<N>::StraightDrive(int32_t base_speed,PIDCore *pid,bool _reset = true){
    CurrentUpdate = &StraightDriveRoutine;
    drive_pid = pid;
    if(_reset)drive_imu->ResetWaitZero();
    else drive_imu->Update();
    drive_current = 0.0f;
    drive_setpoint = 0.0f;
    drive_pid->Init(&drive_setpoint,&drive_current);
    this->drive_motors->base_speed = base_speed;
}

template <size_t N>
inline void DriveController<N>::RotateDrive(double_t angle,PIDCore *pid,bool _reset = true,double_t correct_ms = 500,double_t precision = 0.7){
    CurrentUpdate = &RotateDriveRoutine;
    drive_pid = pid;
    if(_reset)drive_imu->ResetWaitZero();
    drive_current = 0.0f;
    drive_setpoint = angle;
    drive_val[1] = precision; // correct flag
    drive_val[2] = correct_ms;
    drive_pid->Init(&drive_setpoint,&drive_current);
    driveTimer.gap(true);
}

#endif

template <size_t N>
inline void DriveController<N>::CustomDrive(bool (*updateRoutine)()){
    userCurrentUpdate = updateRoutine;
}

#ifdef _enable_IMU

template <size_t N>
inline bool DriveController<N>::StraightDriveRoutine(){
    if(!drive_imu->Update())return true;
    drive_current += drive_imu->dYaw;
    drive_pid->Compute();
    drive_motors->run_dir(this->drive_motors->base_speed,(int32_t)drive_pid->output,1);
    return true;
}

template <size_t N>
inline bool DriveController<N>::RotateDriveRoutine(){
    if(!drive_imu->Update())return true;
    drive_current += drive_imu->dYaw;
    drive_pid->Compute();
    int32_t out = (int32_t)drive_pid->output;
    drive_motors->run_dir_minclamp(0,out,1);
    if(abs(drive_current-drive_setpoint) <= drive_val[1]){
        if(driveTimer.gap(false)){
            Stop();
            return false;
        }
    }
    else driveTimer.gap(true);
    return true;
}

#endif
