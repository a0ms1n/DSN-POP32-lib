#pragma once
#include "../PIDCore/PIDCore.hpp"
#include "../utils/Core.hpp"
#include "../Motors/Motors.hpp"
#include "../IMU/IMU.hpp"
#include "../Timer/Timer.hpp"


/// @brief Attach to MotorPair, to control robot drive, can only do ONE drive mode at a time.
template<size_t N=2>
class DriveController{
    public:
        using PrivateUpdateFunc = bool (DriveController<N>::*)();
        MotorPair<N> *drive_motors = nullptr;
        bool (*userCurrentUpdate)() = nullptr;
        PrivateUpdateFunc CurrentUpdate = nullptr;
        FlagTimer driveTimer;

        #ifdef _enable_IMU
        IMU *drive_imu = nullptr;
        #endif

        PIDCore *drive_pid;
        double_t drive_setpoint = 0.0f;
        double_t drive_current = 0.0f;
        double_t drive_val[5];

        #ifdef _enable_IMU
        DriveController(MotorPair<N> *,IMU*,PIDCore*);
        #else
        DriveController(MotorPair<N> *,PIDCore*);
        #endif
        
        /// @brief Initialize DriveController with MotorPair.
        /// @warning Make sure that motors_ptr is valid during the whole lifetime of DriveController.
        void Init(MotorPair<N> &motors_ptr);

        /// @brief Call this function periodically to update.
        bool Update();

        /// @brief Terminate all driving.
        void Stop();

        #ifdef _enable_IMU

        /// @brief  Start routine of straight driving.
        /// @param pid : PID controller reference for straight driving.
        void StraightDrive(int32_t base_speed,PIDCore &pid);
        void StraightDrive(int32_t base_speed,PIDCore *pid);
        void RotateDrive(double_t angle,PIDCore &pid,double_t direction,double_t correct_ms,double_t precision);

        #endif

        /// @brief Set a custom drive function, the function will be periodically called with Update().
        /// @warning Make sure that the function pointer is valid during the whole DriveController lifetime.
        /// @param updateFunc : Function to call, make sure it returns bool (false -> continue, true -> stop)
        void CustomDrive(bool (*updateRoutine)());
    
    //private:
        bool StraightDriveRoutine();
        bool RotateDriveRoutine();
};


