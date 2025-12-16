#include "Timer.h"

inline void FlagTimer::set(){
    this->next_timepoint = millis() + this->interval;
}

inline void FlagTimer::set(const int64_t &ms){
    this->interval = ms;
    this->next_timepoint = millis() + this->interval;
}

inline bool FlagTimer::check(){
    if(millis() >= this->next_timepoint){
        this->next_timepoint += this->interval;
        return true;
    }
    return false;
}