#pragma once

// Include the Arduino POP32 library ONCE at the top level
// This prevents multiple definition errors from external library functions
#include "Config.h"
#include <POP32.h>

// Then include all DSN-POP32 components
#include "Motors/Motors.h"
#include "PIDCore/PIDCore.h"
#include "LightSensors/LightSensors.h"
#include "DriveController/DriveController.h"
#include "IMU/IMU.h"
//#include "NewIO/NewIO.h"
