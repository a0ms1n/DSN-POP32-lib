#pragma once

/// @brief Fast absolute value functions for int8_t.
int8_t  fast_abs8(int8_t  x) { int8_t  m = x >> 7;  return (x ^ m) - m; }
/// @brief Fast absolute value functions for int16_t.
int16_t fast_abs16(int16_t x) { int16_t m = x >> 15; return (x ^ m) - m; }
/// @brief Fast absolute value functions for int32_t.
int32_t fast_abs32(int32_t x) { int32_t m = x >> 31; return (x ^ m) - m; }
/// @brief Fast absolute value functions for int64_t.
int64_t fast_abs64(int64_t x) { int64_t m = x >> 63; return (x ^ m) - m; }

/// @brief Clamp `val` to the range [-max, max]
#define _ABSCLAMP(val,max) ((val) > (max) ? (max) : ((val) < -(max) ? -(max) : (val)))

/// @brief Clamp `val` to the range [min, max]
#define _CLAMP(val,min,max) ((val) > (max) ? (max) : ((val) < (min) ? (min) : (val)))

/// @brief Clamp `val` to range (-inf,-min] U [min,inf)
#define _MINCLAMP(val,min) ((val>=0)?((val<min)?min:val):((val>-min)?-min:val))

template <typename T>
T lerp(T a, T b, T t) {return a + t * (b - a);}

inline double angularMinDiff(double a, double b) {
    double diff = a - b;
    while (diff > 180.0f) diff -= 360.0f;
    while (diff < -180.0f) diff += 360.0f;
    return diff;
}