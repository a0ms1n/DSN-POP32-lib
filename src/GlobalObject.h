#pragma once
#include "IMU/IMU.hpp" 
#include "DriveController/DriveController.hpp"
#include "Motors/Motors.hpp"
#include "PIDCore/PIDCore.hpp"
#include "Config.h"

IMU imu;
MotorPair<__MOTOR_PAIRS> motors(__MOTOR_PINS[0],__MOTOR_PINS[1]);

PIDGains drive_pid_gains = {0.1,0,0};
PIDCore drive_pid(drive_pid_gains,-255.0,255.0);
DriveController<__MOTOR_PAIRS> drive_motors(motors,imu,drive_pid);

