#pragma once
#include "Config.h"
#include "IMU/IMU.hpp" 
#include "DriveController/DriveController.hpp"
#include "Motors/Motors.hpp"
#include "PIDCore/PIDCore.hpp"
#include "PsxController/PsxLib.hpp"

#ifdef _enable_IMU
IMU imu;
#endif
MotorPair<__MOTOR_PAIRS> motors(__MOTOR_PINS[0],__MOTOR_PINS[1]);

PIDGains PIDDrive_gains = {2.5,0,0};
PIDCore PIDDrive(PIDDrive_gains,-255.0,255.0);

PIDGains PIDRotate_gains = {2.7,0.1,0.1};
PIDCore PIDRotate(PIDRotate_gains,-200.0,200.0);

#ifdef _enable_IMU
DriveController<__MOTOR_PAIRS> drive_motors(&motors,&imu,&PIDDrive);
#else
DriveController<__MOTOR_PAIRS> drive_motors(&motors,&PIDDrive);
#endif

#ifdef _enable_PSX
Psx psx(_PSX_CLK,_PSX_CMD,_PSX_CMD,_PSX_DAT,_PSX_Delay);
#endif