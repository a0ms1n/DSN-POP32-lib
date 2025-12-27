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

PIDGains PIDStraight_gains = {3.5,0.2,0.2,1.0,0.5};
PIDCore PIDStraight(PIDStraight_gains,-200.0,200.0);

// Speed lim set to (100,255)
PIDGains PIDRotate_gains = {2.6,2.5,1.3,1.2,0};
PIDCore PIDRotate(PIDRotate_gains,-180.0,180.0);

#ifdef _enable_IMU
DriveController<__MOTOR_PAIRS> drive_motors(&motors,&imu,&PIDStraight);
#else
DriveController<__MOTOR_PAIRS> drive_motors(&motors,&PIDStraight);
#endif

#ifdef _enable_PSX
Psx psx(_PSX_DAT,_PSX_CMD,_PSX_SEL,_PSX_CLK,_PSX_Delay);
#endif

