#pragma once
#include "PIDCore.h"

inline PIDCore::PIDCore(const PIDGains &gains, const double_t &outMin, const double_t &outMax)
:gains(gains),outMin(outMin),outMax(outMax){}

bool PIDCore::Compute()
{
    if(dtTimer.check()){
        double_t _input = *current;
        double_t dInput = _input - last_input;  
        switch(errormode){
            case errorMode::errorLinear:
                error = (*setpoint - _input)*gains.Knorm;
                break;
            case errorMode::errorAbsolute:
                error = abs((*setpoint - _input)*gains.Knorm);
                break;
            case errorMode::errorSquare:
                error = (*setpoint - _input)*gains.Knorm;
                error = (error<0)?(error)*(-error):error*error;
                break;
            case errorMode::errorSqaureAbsolute:
                error = (*setpoint - _input)*gains.Knorm;
                error = error*error;
                break;
        }  
        
        double_t dError = error - prev_error;
        double_t peTerm = gains.Kp * error;
        double_t pmTerm = gains.Kp * dInput;

        if (pmode == pMode::pOnError) pmTerm = 0;
        else if (pmode == pMode::pOnMeas) peTerm = 0;
        else { //pOnErrorMeas
            peTerm *= 0.5f;
            pmTerm *= 0.5f;
        }

        pTerm = peTerm - pmTerm; // used by GetDterm()
        if(abs(iTerm) <= IErrorTreshold)iTerm = 0;
        else iTerm = gains.Ki * error;
        if (dmode == dMode::dOnError) dTerm = gains.Kd * dError;
        else dTerm = -gains.Kd * dInput; // dOnMeas

        if (iawmode == iAwMode::iAwCondition) {
            bool aw = false;
            double_t iTermOut = (peTerm - pmTerm) + gains.Ki * (iTerm + error);
            if (iTermOut > outMax && dError > 0) aw = true;
            else if (iTermOut < outMin && dError < 0) aw = true;
            if (aw && gains.Ki != 0.0) iTerm = constrain(iTermOut, outMin, outMax);
        }

        output_sum += iTerm;
        if(abs(iTerm) <= IErrorTreshold)output_sum = 0;
        else if (iawmode == iAwMode::iAwOff) output_sum -= pmTerm;
        else output_sum = constrain(output_sum - pmTerm, outMin, outMax);   
        output = constrain(output_sum + peTerm + dTerm, outMin, outMax);  

        prev_error = error;
        last_input = _input;
        dtTimer.set(dt_ms);
        return true;
    }
    return false;
}

void PIDCore::Init(double_t &setpoint, double_t &current){
    this->setpoint = &setpoint;
    this->current = &current;
    dtTimer.set(dt_ms);
    Reset();
}

inline void PIDCore::Start(){
    dtTimer.set(dt_ms);
    Reset();
}

inline void PIDCore::Reset(){
    this->error = 0;
    this->prev_error = 0;
    this->output_sum = 0;
    this->iTerm = 0;
    this->pTerm = 0;
    this->dTerm = 0;
    dtTimer.set(dt_ms);
}

inline void PIDCore::SetGains(const PIDGains &gains){
    this->gains = gains;
}

inline void PIDCore::SetOutputLimits(const double_t &outMin, const double_t &outMax){
    this->outMin = outMin;
    this->outMax = outMax;
    output = constrain(output, outMin, outMax);
    output_sum = constrain(output_sum, outMin, outMax);
}

inline void PIDCore::SetDt(const uint64_t &dt_ms){
    this->dt_ms = dt_ms;
    dtTimer.set(dt_ms);
}

inline void PIDCore::SetProportionalMode(pMode pMode){
    this->pmode = pMode;
}

inline void PIDCore::SetProportionalMode(uint8_t Pmode){
    this->pmode = (pMode)Pmode;
}

inline void PIDCore::SetDerivativeMode(dMode dMode){
    this->dmode = dMode;
}

inline void PIDCore::SetDerivativeMode(uint8_t Dmode){
    this->dmode = (dMode)Dmode;
}

inline void PIDCore::SetAntiWindupMode(iAwMode iAwMode){
    this->iawmode = iAwMode;
}

inline void PIDCore::SetAntiWindupMode(uint8_t IawMode){
    this->iawmode = (iAwMode)IawMode;
}

inline void PIDCore::SetErrorMode(errorMode errorMode){
    this->errormode = errorMode;
}

inline void PIDCore::SetErrorMode(uint8_t ErrorMode){
    this->errormode = (errorMode)ErrorMode;
}
