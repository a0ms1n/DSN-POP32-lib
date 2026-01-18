#pragma once
#include "../../src/DSN-POP32.h"

// พิน ขาว ดำ
LEDSensor sensors[] ={
    {4,1300,180}, // หน้าซ้าย
    {0,1900,340}, // หน้ากลางซ้าย
    {1,3075,560}, // หน้ากลางขวา
    {6,1800,300}, // หน้าขวา

    {5,1200,200}, // หลังซ้าย
    {2,1400,290}, // หลังกลางซ้าย
    {3,2800,510}, // หลังกลางขวา
    {7,3600,640}, // หลังขวา
};

PIDGains newRotateGains = {3.2,3.4,1.3,1.5,0}; // Kp = 2.0;

LEDSensorLine<4> Front({
    &sensors[0],
    &sensors[1],
    &sensors[2],
    &sensors[3],
});

LEDSensorLine<4> Back({
    &sensors[4],
    &sensors[5],
    &sensors[6],
    &sensors[7],
});

int32_t servoPIN = 3;
int32_t startAngle = 180;
int32_t endAngle = 0;

void forwardTill(int32_t base_speed, bool _tillBlack = true, bool _reset = true,bool _continuous = false){
    drive_motors.StraightDrive(base_speed,&PIDStraight,_reset);
    while(true){
        drive_motors.Update();
        Front.readLine(true);
        if((Front.cOnline ^ (!_tillBlack))){
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
        if((Back.cOnline ^ (!_tillBlack))){
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

void rotate(int32_t angle,bool reset = true){
    motors.stop();
    drive_motors.RotateDrive(angle,&PIDRotate,reset,350,0.3);
    while(drive_motors.Update());
    motors.stop();
}

void toggleServoOn(){
    servo(servoPIN,startAngle);
    delay(200);
    servo(servoPIN,endAngle);
}

void toggleServoOff(){
    servo(servoPIN,startAngle);
}

void forwardAlign(int16_t speed,int16_t repeat = 1,int32_t back_delay = 300){
    for(int16_t idx = 1;idx<=repeat;idx++){
        do{
            Front.readLine();
            if(!Front.cOnline)motors.run(speed -5 ,speed);

            // Black at right -> go right
            else if(Front.errorFromMid() > 0)motors.run(-speed - 20,speed);
            else motors.run(speed + 20,-speed);
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

void backwardAlign(int16_t speed,int16_t repeat = 1,int32_t back_delay = 300){
    for(int16_t idx = 1; idx <= repeat; idx++){
        do{
            Back.readLine();

            if(!Back.cOnline)
                motors.run(-speed, -speed + 10);

            // เส้นอยู่ขวา → หมุนขวา (ตอนถอย)
            else if(Back.errorFromMid() > 0)
                motors.run(speed, -speed - 50);

            // เส้นอยู่ซ้าย → หมุนซ้าย (ตอนถอย)
            else
                motors.run(-speed, speed + 50);

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

void Poy() 
{
  servo(3,60); delay(500); // ต้อง set 0
  servo(3,180);
}

void Poy2() 
{
  servo(3, 70); delay(300);
  servo(3, 175);
}

void spinLeft(int speed) {
    motor(1, -speed);
    motor(2, -speed);
    motor(3, speed);
    motor(4, speed);
}

void spinRight(int speed) {
  motor(1 , 50);
  motor(2 , 50);
  motor(3 , -50);
  motor(4 , -50);
}

