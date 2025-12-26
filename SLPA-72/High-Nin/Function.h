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
    delay(1000);
    drive_motors.RotateDrive(angle,&PIDRotate,700,0.3);
    while(drive_motors.Update());
    motors.stop();
    delay(100);
}