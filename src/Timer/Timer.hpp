#pragma once
#include "Timer.h"

inline void FlagTimer::set(){
    this->current_timepoint = millis();
    this->next_timepoint = millis() + this->interval;
}

inline void FlagTimer::set(const uint64_t &ms){
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

inline uint64_t FlagTimer::gap(){
    uint64_t last_timepoint = current_timepoint;
    return (current_timepoint=millis() - last_timepoint);
}
