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


#ifdef _enable_IMU

template <size_t N>
inline void DriveController<N>::StraightDrive(int32_t base_speed,PIDCore &pid){
    CurrentUpdate = &StraightDriveRoutine;
    drive_pid = &pid;
    drive_pid->Init(drive_setpoint,drive_current);
    drive_imu->ResetWaitZero();
    drive_current = 0.0f;
    drive_setpoint = 0.0f;
    this->drive_motors->base_speed = base_speed;
}

template <size_t N>
inline void DriveController<N>::RotateDrive(double_t angle,PIDCore &pid,double_t direction=__LEFT_ROTATE,double_t correct_ms = 500){
    CurrentUpdate = &RotateDriveRoutine;
    drive_pid = &pid;
    drive_pid->Init(drive_setpoint,drive_current);
    drive_imu->ResetWaitZero();
    drive_current = 0.0f;
    drive_setpoint = angle;
    drive_val[0] = direction; // direction
    drive_val[1] = 0; // correct flag
    drive_val[2] = correct_ms;
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
    drive_motors->run_dir_minclamp(0,out,drive_motors->base_speed);
    if(abs(drive_current-drive_setpoint) <= 0.5){
        drive_val[1]++;
        if(drive_val[1]>=drive_val[2]){
            Stop();
            return;
        }
    }
    return true;
}

#endif
