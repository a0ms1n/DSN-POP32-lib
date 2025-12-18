#pragma once

/// @brief Class for reading and compute value from a single sensor. 
class LEDSensor {
    public:
    uint8_t channel;
    int32_t blackValue;
    int32_t whiteValue;

    /// @brief cached value after calling compute function.
    int32_t cValue;

    LEDSensor(uint8_t ch, int32_t black, int32_t white)
        : channel(ch), blackValue(black), whiteValue(white) {}

    inline void set_white();
    inline void set_black();
    inline void calibrate();

    /// @brief return RawValue from sensor 
    inline int32_t readRaw();

    /// @brief return normalized value to range [0,1000] (0->WHITE, 1000->BLACK)
    inline int32_t read();
};


class LEDSensorPair{
    public:
    LEDSensor *left,*right;
    LEDSensorPair(LEDSensor &left,LEDSensor &right);

    inline void set_white();
    inline void set_black();
    inline void calibrate();
 
    inline int32_t readRaw();
    inline int32_t read();

};