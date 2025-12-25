#pragma once
#include "../utils/Core.hpp"

/// @brief  Flag timer class (microseconds), for implementing non-blocking delays.
/**
 * @example FlagTimer timer(1000); Then use if(timer.check()) to check if timeout.
 */
class FlagTimer{
    public:
        int64_t next_timepoint = 0;
        int64_t current_timepoint = 0;
        int64_t interval = 1000;

        FlagTimer(const int64_t &ms=1000):interval(ms){}
        
        /// @brief reset next_timepoint using current interval.
        inline void set();

        /// @brief set time interval, and reset next_timepoint.
        inline void set(const int64_t &ms);
        
        /// @brief check if current_time is past next_timepoint, and reset next_timepoint if true.
        inline bool check();

        /// @brief return interval between now() and current_timee.
        inline int64_t gap(const bool _reset=true);

};