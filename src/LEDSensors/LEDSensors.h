#pragma once

/// @brief Class for reading and compute value from a single sensor. 
class LEDSensor {
    public:
    uint8_t channel;
    int32_t blackValue=0;
    int32_t whiteValue=0;
    int32_t midValue=0;

    /// @brief cached value after calling compute function.
    int32_t cValue;

    LEDSensor(uint8_t ch, int32_t white=100, int32_t black=200)
        : channel(ch), blackValue(black), whiteValue(white) {}

    inline void set_white();
    inline void set_black();
    inline void update_mid();
    inline void calibrate();
    inline void reset();

    /// @brief return RawValue from sensor 
    inline int32_t readRaw();

    /// @brief return normalized value to range [0,1000] (0->WHITE, 1000->BLACK)
    inline int32_t read();
};


/// @brief Class for update multiple sensors. 
template<size_t N>
class LEDSensorGroup{
    public:
    LEDSensor *sensors[N];

    LEDSensorGroup(std::array<LEDSensor*,N>sensors_ptr);

    inline void set_white();
    inline void set_black();
    inline void calibrate();
    inline void update_mid();
    inline void reset();

    inline void readRaw();  
    inline void read();

    /// @brief Get value (ref) from specific sensor (by index (0-based)).
    inline int32_t& get(uint8_t);

    /// @brief Get object (ref) from specific sensor (by index (0-based)).
    inline int32_t& getObj(uint8_t);
};

/// @brief Sensor from left to right.
/// @tparam N 
template <size_t N>
class LEDSensorLine : public LEDSensorGroup<N> {
    public:

    int32_t cPosition = (N-1)*500;
    int32_t cOnline = false;
    int16_t __Noise = 50;
    int16_t __Track = 340;
    int32_t __MIDDLE_VALUE = (N-1)*500;
    int32_t __LEFT = 0;
    int32_t __RIGHT = (N-1)*1000;
    bool __AutoRotate = 0;

    LEDSensorLine(std::array<LEDSensor*, N> sensors_ptr,bool __AutoRotate = 0,int16_t cNoise = 50,int16_t cTrack = 340)
        : LEDSensorGroup<N>(sensors_ptr),__Noise(cNoise),__Track(cTrack),__AutoRotate(__AutoRotate){}

    /// @brief return cPosition, based on current sensor.
    inline int32_t readLine(bool do_read = true);
    inline int32_t errorFromMid();
    inline int32_t posFromMid(double_t pos);
    inline int32_t isTrack(int32_t pos); 

};


