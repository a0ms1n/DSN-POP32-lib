#pragma once
#include "Timer.h"

void FlagTimer::set(){
    this->next_timepoint = millis() + this->interval;
}

void FlagTimer::set(const int64_t &ms){
    this->interval = ms;
    this->next_timepoint = millis() + this->interval;
}

bool FlagTimer::check(){
    if(millis() >= this->next_timepoint){
        this->next_timepoint += this->interval;
        return true;
    }
    return false;
}