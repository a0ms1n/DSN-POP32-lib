#pragma once
#include "../Timer/Timer.hpp"

/// @brief PID gains (Kp, Ki, Kd).
struct PIDGains{
    double_t Kp=0,Ki=0,Kd=0;
};

/// @brief PID Controller class.
class PIDCore{
    public:

        enum class pMode : uint8_t {pOnError, pOnMeas, pOnErrorMeas};     // proportional mode
        enum class dMode : uint8_t {dOnError, dOnMeas};                   // derivative mode
        enum class iAwMode : uint8_t {iAwCondition, iAwClamp, iAwOff};    // integral anti-windup mode
        pMode pmode = pMode::pOnError;
        dMode dmode = dMode::dOnMeas;
        iAwMode iawmode = iAwMode::iAwClamp;

        PIDGains gains;
        double_t error=0,prev_error=0,last_input=0,output_sum=0;
        double_t dt=0;

        double_t pTerm=0,iTerm=0,dTerm=0;

        /// @brief Reference this to the desired setpoint.
        double_t *setpoint = nullptr;

        /// @brief Reference this to the current process variable.
        double_t *current = nullptr;

        FlagTimer dtTimer;
        uint64_t dt_ms=1;

        double_t outMin=-255.0f,outMax=255.0f;
        
        /// @brief Ignore iTerm if error is less than... (set to -1 to turn off)
        double_t IErrorTreshold = 0;

        /// @brief PID output value.
        double_t output=0;

        PIDCore(const PIDGains &,const double_t&,const double_t&);

        /// @brief Update PID controller, to current setpoint.
        bool Compute();

        /// @brief Initialize PID controller with setpoint and current references.
        /// @warning Make sure the references are valid during the whole PIDCore lifetime.
        void Init(double_t &setpoint, double_t &current);

        /// @brief Reset PID controller internal states.
        void Reset();
        
        /// @brief Start PID controller timer.
        inline void Start();

        inline void SetGains(const PIDGains &gains);
        inline void SetOutputLimits(const double_t &outMin, const double_t &outMax);
        inline void SetDt(const uint64_t &dt_ms);

        void SetProportionalMode(pMode pMode);
        void SetProportionalMode(uint8_t Pmode);
        
        void SetDerivativeMode(dMode dMode);
        void SetDerivativeMode(uint8_t Dmode);

        void SetAntiWindupMode(iAwMode iAwMode);
        void SetAntiWindupMode(uint8_t IawMode);
        

};