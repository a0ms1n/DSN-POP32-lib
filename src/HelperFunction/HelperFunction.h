#pragma once
#include "../IMU/IMU.hpp"
#include "../Motors/Motors.hpp"
#include "../DriveController/DriveController.hpp"
#include "../utils/Core.hpp"
#include "../FastOled/FastOled.hpp"
#include "../GlobalObject.h"

void POP32_INIT();

namespace HelperFunction{
void CallbackPlaceHolder();

void SensorTest();
void MotorTest();
#ifdef _enable_IMU
void IMUTest();
void SpinTest();
void StraightTest();
#endif
#ifdef _enable_PSX
void PsxTest();
#endif
void ServoTest();
};
