#pragma once
#include "../../src/DSN-POP32.h"

LEDSensor sensors[] ={
    {0,3200,500}, // หน้าซ้าย
    {1,2400,200}, // หน้ากลางซ้าย
    {2,1800,200}, // หน้ากลางขวา
    {3,3300,600}, // หน้าขวา
    {4,3150,500}, // หลังซ้าย
    {5,3050,500}, // หลังกลางซ้าย
    {6,2300,400}, // หลังกลางขวา
    {7,2700,400}, // หลังขวา
};

LEDSensorLine<2> Front({
    &sensors[1],
    &sensors[2]
});

LEDSensorLine<2> Back({
    &sensors[5],
    &sensors[6],
}); 

void forwardTill(int32_t base_speed, bool _tillBlack = true, bool _reset = true,bool _continuous = false){
    drive_motors.StraightDrive(base_speed,&PIDStraight,_reset);
    while(true){
        drive_motors.Update();
        Front.readLine(true);
        if(Front.cOnline ^ (!_tillBlack)){
            if(_continuous)drive_motors.ClearDrive();
            else drive_motors.Stop();
            break;
        }
    }
}

void backwardTill(int32_t base_speed, bool _tillBlack = true, bool _reset = true,bool _continuous = false){
    drive_motors.StraightDrive(-base_speed,&PIDStraight,_reset);
    while(true){
        drive_motors.Update();
        Back.readLine(true);
        if(Back.cOnline ^ (!_tillBlack)){
            if(_continuous)drive_motors.ClearDrive();
            else drive_motors.Stop();
            break;
        }
    }
}

void forwardTime(int32_t base_speed, int32_t time_ms, bool _reset = true,bool _continuous = false){
    drive_motors.StraightDrive(base_speed,&PIDStraight,_reset);
    FlagTimer ft(time_ms);
    ft.set();
    while(true){
        drive_motors.Update();
        if(ft.check()){
            if(_continuous)drive_motors.ClearDrive();
            else drive_motors.Stop();
            break;
        }
    }
}

void backwardTime(int32_t base_speed, int32_t time_ms, bool _reset = true,bool _continuous = false){
    drive_motors.StraightDrive(-base_speed,&PIDStraight,_reset);
    FlagTimer ft(time_ms);
    ft.set();
    while(true){
        drive_motors.Update();    
        if(ft.check()){
            if(_continuous)drive_motors.ClearDrive();
            else drive_motors.Stop();
            break;
        }
    }
}

void rotate(int32_t angle){
    motors.stop();
    drive_motors.RotateDrive(angle,&PIDRotate,500,0.8);
    while(drive_motors.Update());
    motors.stop();
    delay(100);
}

void toggleServoOn(){
    servo(1,140);
    delay(200);
    servo(1,20);
}

void toggleServoOff(){
    servo(1,140);
}

void frontAlign(int16_t speed,int16_t repeat = 1,int32_t back_delay = 150){
    for(int16_t idx = 1;idx<=repeat;idx++){
        do{
            Front.readLine();
            if(!Front.cOnline)motors.run(speed,speed);

            // Black at right -> go right
            else if(Front.errorFromMid() > 0)motors.run(speed,-speed);
            else motors.run(-speed,speed);
        }while(abs(Front.errorFromMid()) >= 100);
        if(idx == repeat)return;
        motors.run(-speed,-speed);
        delay(back_delay);
    }   
}

void backAlign(int16_t speed,int16_t repeat = 1,int32_t back_delay = 150){
    for(int16_t idx = 1;idx<=repeat;idx++){
        do{
            Back.readLine();
            if(!Back.cOnline)motors.run(-speed,-speed);

            // Black at right -> go right
            else if(Back.errorFromMid() > 0)motors.run(-speed,speed);
            else motors.run(speed,-speed);
        }while(abs(Front.errorFromMid()) >= 100);
        if(idx == repeat)return;
        motors.run(speed,speed);
        delay(back_delay);
    }   
}

namespace Sound{
    void UmaPyou(){
        static int16_t soundseq[][2] = {
            {988,333},{932,333},{988,333},{988,166},{932,333},{740,166},{831,499},{659,333},{831,166},{659,166},{740,499},{1109,333},{988,333},{932,333},{1109,166},{988,333},{988,166},{932,333},{740,166},{831,499},{554,666},{659,333},{831,166},{659,166},{740,499},{831,832}
        };
        for(int i=0;i<26;i++){
            sound(soundseq[i][0],soundseq[i][1]);
        }
    }
}