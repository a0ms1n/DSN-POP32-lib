#pragma once
#include "Motors.h"

template <size_t N>
inline void MotorPair<N>::update(){

    #ifdef __AUTO_CONSTRAIN_ON_UPDATE
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
    #endif

    #ifdef __DISABLE_REVERSE
    for(size_t i=0;i<N;i++){
        motor255(leftGroup[i],left_speed);
        motor255(rightGroup[i],right_speed);
    }
    #else
    for(size_t i=0;i<N;i++){
        motor255(leftGroup[i],(int32_t)(left_speed*(leftRatio[i])));
        motor255(rightGroup[i],(int32_t)(right_speed*(rightRatio[i])));
    }
    #endif
}

template <size_t N>
inline void MotorPair<N>::set(const int16_t &left_speed, const int16_t &right_speed){
    #ifndef __AUTO_CONSTRAIN_ON_UPDATE
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
    #else
    this->left_speed = left_speed;
    this->right_speed = right_speed;
    #endif
}

template <size_t N>
inline void MotorPair<N>::set_minclamp(const int16_t &left_speed, const int16_t &right_speed){
    #ifndef __AUTO_CONSTRAIN_ON_UPDATE
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
    #else
    this->left_speed = left_speed;
    this->right_speed = right_speed;
    #endif
    this->left_speed = _MINCLAMP(this->left_speed,this->min_speed);
    this->right_speed = _MINCLAMP(this->right_speed,this->min_speed);
}

template <size_t N>
inline void MotorPair<N>::run(){
    #ifndef __AUTO_CONSTRAIN_ON_UPDATE
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
    #else
    this->left_speed = left_speed;
    this->right_speed = right_speed;
    #endif
    update();
}

template <size_t N>
inline void MotorPair<N>::run(const int16_t &left_speed, const int16_t &right_speed)
{
    #ifndef __AUTO_CONSTRAIN_ON_UPDATE
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
    #else
    this->left_speed = left_speed;
    this->right_speed = right_speed;
    #endif
    update();
}

template <size_t N>
inline void MotorPair<N>::run_minclamp(const int16_t &left_speed, const int16_t &right_speed){
    #ifndef __AUTO_CONSTRAIN_ON_UPDATE
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
    #else
    this->left_speed = left_speed;
    this->right_speed = right_speed;
    #endif
    this->left_speed = _MINCLAMP(this->left_speed,this->min_speed);
    this->right_speed = _MINCLAMP(this->right_speed,this->min_speed);
    update();
}

template <size_t N>
inline void MotorPair<N>::run_dir(int16_t speed,const int16_t angular_vel,double_t direction){
    direction = constrain(direction,-1.0,1.0);
    //speed = abs(speed);

    this->left_speed =  speed - (angular_vel*direction);
    this->right_speed = speed + (angular_vel*direction);
    #ifndef __AUTO_CONSTRAIN_ON_UPDATE
    this->left_speed = _ABSCLAMP(this->left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(this->right_speed,this->max_speed);
    #endif
    update();

}

template <size_t N>
inline void MotorPair<N>::run_dir_minclamp(int16_t speed, const int16_t angular_vel, double_t direction){
    direction = constrain(direction,-1.0,1.0);
    //speed = abs(speed);
    this->left_speed = speed - (angular_vel*direction);
    this->right_speed = speed + (angular_vel*direction);
    #ifndef __AUTO_CONSTRAIN_ON_UPDATE
    this->left_speed = _ABSCLAMP(left_speed,this->max_speed);
    this->right_speed = _ABSCLAMP(right_speed,this->max_speed);
    #endif
    this->left_speed = _MINCLAMP(this->left_speed,this->min_speed);
    this->right_speed = _MINCLAMP(this->right_speed,this->min_speed);
    update();
}

template <size_t N>
inline void MotorPair<N>::stop(){
    this->left_speed = 0;
    this->right_speed = 0;
    update();
}

template <size_t N>
inline void MotorPair<N>::setRatio(const double_t (&left_ratio)[N], const double_t (&right_ratio)[N]){
    for (size_t i = 0; i < N; ++i) {
        leftRatio[i] = left_ratio[i];
        rightRatio[i] = right_ratio[i];
    }
}

template <size_t N>
inline void MotorPair<N>::setSpeedRange(const int16_t &min_speed = 0, const int16_t &max_speed=255){
    this->max_speed = max_speed;
    this->min_speed = min_speed;
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
