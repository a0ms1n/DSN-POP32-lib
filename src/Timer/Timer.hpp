#pragma once
#include "../FastOled/FastOled.hpp"
#include "Timer.h"

inline void FlagTimer::set(){
    this->current_timepoint = millis();
    this->next_timepoint = millis() + this->interval;
}

inline void FlagTimer::set(const int64_t &ms){
    this->interval = ms;
    this->current_timepoint = millis();
    this->next_timepoint = millis() + this->interval;
}

inline bool FlagTimer::check(){
    if(millis() >= this->next_timepoint){
        this->next_timepoint = millis() + this->interval;
        this->current_timepoint = millis();
        return true;
    }
    return false;
}

inline int64_t FlagTimer::gap(const bool _reset=true){
    if(!_reset)return (int64_t) millis() - this->current_timepoint;
    int64_t last_timepoint = this->current_timepoint;
    this->current_timepoint = (int64_t) millis();
    return ((int64_t)current_timepoint - (int64_t)last_timepoint);
}
