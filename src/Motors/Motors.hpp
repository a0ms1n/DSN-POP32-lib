#pragma once
#include "Motors.h"

template <size_t N>
inline void MotorPair<N>::update(){

    #ifdef __DISABLE_REVERSE
    for(size_t i=0;i<N;i++){
        motor255(leftGroup[i],left_speed);
        motor255(rightGroup[i],right_speed);
    }
    #else
    for(size_t i=0;i<N;i++){
        motor255(leftGroup[i],left_speed*(leftReverse[i]?-1:1));
        motor255(rightGroup[i],right_speed*(rightReverse[i]?-1:1));
    }
    #endif
}

template <size_t N>
inline void MotorPair<N>::set(const int16_t &left_speed, const int16_t &right_speed){
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
}

template <size_t N>
inline void MotorPair<N>::run(const int16_t &left_speed, const int16_t &right_speed){
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
    update();
}

template <size_t N>
inline void MotorPair<N>::stop(){
    this->left_speed = 0;
    this->right_speed = 0;
    update();
}

template <size_t N>
inline void MotorPair<N>::setReverse(const bool (&left_reverse)[N], const bool (&right_reverse)[N]){
            for (size_t i = 0; i < N; ++i) {
                leftReverse[i] = left_reverse[i];
                rightReverse[i] = right_reverse[i];
            }
        }

void motor255(const int8_t ch, const int16_t pow){
    if(pow>=-255 && pow<=255){
        __motorLastpow = pow*100/255;
        int16_t p = pow;
        if (ch == 1 && pow >= 0)
        {
        __MACRO_M1DIR_OUT0
        analogWrite(M1EN, (int)p);
        }
        else if (ch == 1 && pow < 0)
        {
        __MACRO_M1DIR_OUT1
        analogWrite(M1EN, -(int)p);
        }
        else if (ch == 2 && pow >= 0)
        {
        __MACRO_M2DIR_OUT0
        analogWrite(M2EN, (int)p);
        }
        else if (ch == 2 && pow < 0)
        {
        __MACRO_M2DIR_OUT1
        analogWrite(M2EN, -(int)p);
        }

        else if (ch == 3 && pow >= 0)
        {
        __MACRO_M3DIR_OUT0
        analogWrite(M3EN, (int)p);
        }
        else if (ch == 3 && pow < 0)
        {
        __MACRO_M3DIR_OUT1
        analogWrite(M3EN, -(int)p);
        }
        else if (ch == 4 && pow >= 0)
        {
        __MACRO_M4DIR_OUT0
        analogWrite(M4EN, (int)p);
        }
        else if (ch == 4 && pow < 0)
        {
        __MACRO_M4DIR_OUT1
        analogWrite(M4EN, -(int)p);
        }

        else if (ch == 12 && pow < 0)
        {
        __MACRO_M1DIR_OUT1
        __MACRO_M2DIR_OUT1
        analogWrite(M1EN, -(int)p);
        analogWrite(M2EN, -(int)p);
        }
        else if (ch == 12 && pow >= 0)
        {
        __MACRO_M1DIR_OUT0
        __MACRO_M2DIR_OUT0
        analogWrite(M1EN, (int)p);
        analogWrite(M2EN, (int)p);
        }
        else if (ch == 34 && pow >= 0)
        {
        __MACRO_M3DIR_OUT0
        __MACRO_M4DIR_OUT0
        analogWrite(M3EN, (int)p);
        analogWrite(M4EN, (int)p);
        }
        else if (ch == 34 && pow < 0)
        {
        __MACRO_M3DIR_OUT1
        __MACRO_M4DIR_OUT1
        analogWrite(M3EN, -(int)p);
        analogWrite(M4EN, -(int)p);
        }

        else if (ch == 100 && pow >= 0)
        {
        __MACRO_M1DIR_OUT0
        __MACRO_M2DIR_OUT0
        __MACRO_M3DIR_OUT0
        __MACRO_M4DIR_OUT0
        analogWrite(M1EN, (int)p);
        analogWrite(M2EN, (int)p);
        analogWrite(M3EN, (int)p);
        analogWrite(M4EN, (int)p);
        }
        else if (ch == 100 && pow < 0)
        {
        __MACRO_M1DIR_OUT1
        __MACRO_M2DIR_OUT1
        __MACRO_M3DIR_OUT1
        __MACRO_M4DIR_OUT1
        analogWrite(M1EN, -(int)p);
        analogWrite(M2EN, -(int)p);
        analogWrite(M3EN, -(int)p);
        analogWrite(M4EN, -(int)p);
        }

        else if (ch == 112 && pow < 0)
        {
        __MACRO_M1DIR_OUT1
        __MACRO_M2DIR_OUT0
        analogWrite(M1EN, -(int)p);
        analogWrite(M2EN, -(int)p);
        }
        else if (ch == 112 && pow >= 0)
        {
        __MACRO_M1DIR_OUT0
        __MACRO_M2DIR_OUT1
        analogWrite(M1EN, (int)p);
        analogWrite(M2EN, (int)p);
        }

        else if (ch == 121 && pow < 0)
        {
        __MACRO_M1DIR_OUT0
        __MACRO_M2DIR_OUT1
        analogWrite(M1EN, -(int)p);
        analogWrite(M2EN, -(int)p);
        }
        else if (ch == 121 && pow >= 0)
        {
        __MACRO_M1DIR_OUT1
        __MACRO_M2DIR_OUT0
        analogWrite(M1EN, (int)p);
        analogWrite(M2EN, (int)p);
        }
    }

}
