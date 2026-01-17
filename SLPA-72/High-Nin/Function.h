#pragma once
#include "../../src/DSN-POP32.h"

LEDSensor sensors[] ={
    {0,80,15}, // หลังซ้าย
    {1,145,25}, // หน้ากลางซ้าย
    {2,500,80}, // หน้าขวา
    {3,114,10}, // หน้ากลางขวา
    {4,2300,440}, // หน้าซ้าย
    {5,1380,190}, // หลังกลางซ้าย
    {6,2700,630}, // หลังกลางขวา
    {7,3100,500}, // หลังขวา
};

LEDSensorLine<2> Front({
    &sensors[4],
    &sensors[2]
});

PIDGains newRotateGains = {3.0,3.0,2.5,1.1,0.2}; //3.0,3.0,2.5,1.1,0.2
// PIDGains newStraightGains = {3.5,0.5,0.6,1.0,0.5}; // 3.5,0.5,0.6,1.0,0.5

LEDSensorLine<2> Back({
    &sensors[5],
    &sensors[6],
});

int32_t servoPIN = 1;
int32_t startAngle = 176;
int32_t endAngle = 70;

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

void forwardTime(int32_t base_speed, int32_t time_ms, bool _reset = false,bool _continuous = false){
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

void backwardTime(int32_t base_speed, int32_t time_ms, bool _reset = false,bool _continuous = false){
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

void rotate(int32_t angle,bool reset = true){
    motors.stop();
    drive_motors.RotateDrive(angle,&PIDRotate,reset,400,0.6); // 400 , 0.9
    while(drive_motors.Update());
    motors.stop();
}

void Thailand()
{
    servo(6 , 180);
}

void Thailand_back()
{
    servo(6 , 90);
}

void toggleServoOn()
{
    servo(servoPIN,startAngle);
    delay(200);
    servo(servoPIN,endAngle);
}

void toggleServoOff(){
    servo(servoPIN,startAngle);
}

void forwardAlign(int16_t speed,int16_t repeat = 1,int32_t back_delay = 200){
        for(int16_t idx = 1;idx<=repeat;idx++){
        do{
            Front.readLine();
            if(!Front.cOnline)motors.run(speed + 10,speed);

            // Black at right -> go right
            else if(Front.errorFromMid() > 0)motors.run(-speed,speed + 20);
            else motors.run(speed,-speed - 20);
            oledf.clear();
            oledf.text(0,0,1,"%d",(int32_t)Front.errorFromMid());
            oledf.show();
        }while(abs(Front.errorFromMid()) >= 50 || !Front.cOnline);
        if(idx == repeat)break;
        motors.run(-speed,-speed);
        delay(back_delay);
        do{
            Front.readLine();
        }while(Front.cOnline);
    }   
    motors.stop();
}

void backwardAlign(int16_t speed,int16_t repeat = 1,int32_t back_delay = 1000){
    for(int16_t idx = 1; idx <= repeat; idx++){
        do{
            Back.readLine();

            if(!Back.cOnline)
                motors.run(-speed -5, -speed);

            // เส้นอยู่ขวา → หมุนขวา (ตอนถอย)
            else if(Back.errorFromMid() > 0)
                motors.run(speed, -speed - 20);

            // เส้นอยู่ซ้าย → หมุนซ้าย (ตอนถอย)
            else
                motors.run(-speed, speed + 20);

        }while(abs(Back.errorFromMid()) >= 50 || !Back.cOnline);

        if(idx == repeat) break;

        motors.run(speed, speed);
        delay(back_delay);

        do{
            Back.readLine();
        }while(Back.cOnline);
    }
    motors.stop();
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
