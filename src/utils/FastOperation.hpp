#pragma once
#include <POP32.h>

inline int8_t  fast_abs8(int8_t  x) { int8_t  m = x >> 7;  return (x ^ m) - m; }
inline int16_t fast_abs16(int16_t x) { int16_t m = x >> 15; return (x ^ m) - m; }
inline int32_t fast_abs32(int32_t x) { int32_t m = x >> 31; return (x ^ m) - m; }
inline int64_t fast_abs64(int64_t x) { int64_t m = x >> 63; return (x ^ m) - m; }