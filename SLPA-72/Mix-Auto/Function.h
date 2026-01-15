#pragma once
#include "Config.h"
#include "../../src/DSN-POP32.h"

// SENSOR PIN 0 แก้แล้วนะคั้บบบบบ
// ถ้าจะให้หุ่นยนต์ รอกระป๋องเเล้วคีบ ให้หมุนไป Run2 

// PIN, White_Value, Black_Value
LEDSensor sensors[] ={
    {5,3800,1000}, // L - ซ้ายสุด
    {1,3800,1400}, // L2 
    {3,3800,1300}, // L3
    {0,3800,1000}, // M
    {4,3800,2200}, // R3 
    {2,3800,1200},  // R2
    {6,3800,2000}  // R - ขวาสุด
};

// {Sensors Refs}, AutoRotate, Error, Track
LEDSensorLine<7> ground_sensor({&sensors[0],&sensors[1],&sensors[2],&sensors[3],&sensors[4],&sensors[5],&sensors[6]},0,50,500);

void rotate(int32_t angle,bool reset = true){
    motors.stop();
    drive_motors.RotateDrive(angle,&PIDRotate,reset,500,0.8);
    while(drive_motors.Update());
    motors.stop();
}

void ForwardUntilCross(int32_t speed,int32_t spin_speed){ //เดินจับเส้นดำจนกว่าจะเจอแยก วิธีใช้ใส่ ForwardUntilCross(ความเร็ว);
    double_t angle_diff = 0.0;
    while(true){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d %d %d",val,(int32_t)ground_sensor.get(0),(int32_t)ground_sensor.get(4));
        oledf.show();
        if(val < ground_sensor.posFromMid(-1))motors.run(-spin_speed,spin_speed);
        else if (val > ground_sensor.posFromMid(1))motors.run(spin_speed,-spin_speed);
        else motors.run(speed,speed);

        if(ground_sensor.isTrack(ground_sensor.__LEFT) && ground_sensor.isTrack(4)){
          motors.stop();
          break;
        }
    }
}

void SkipCross(int32_t speed,int32_t ms = 200){ //ใช้ตอนกำลังจะข้ามเส้น วิธีใช้ใส่SkipCross(ความเร็ว);
    while(true){
        ground_sensor.readLine();
        motors.run(speed,speed);
        if( !ground_sensor.isTrack(0) || !ground_sensor.isTrack(4)){
            delay(ms);
            motors.stop();
            break;
        }   
    }
}

void TurnLeft(int32_t speed){ 
    // ใช้คู่กับskipcross วิธีใช้skipCross(ความเร็ว);
    //                     TurnLeft(ความเร็ว);
    while(true){
        motors.run(-speed,speed);
        ground_sensor.readLine();
        if(ground_sensor.isTrack(4))break;
    }
    while(true){
        motors.run(-speed,speed);
        ground_sensor.readLine();
        if(ground_sensor.isTrack(2))break;
    }
    motors.stop();
}

void TurnRight(int32_t speed){
    while(true){
        motors.run(speed,-speed);
        ground_sensor.readLine();
        if(ground_sensor.isTrack(0))break;
    }
    while(true){
        motors.run(speed,-speed);
        ground_sensor.readLine();
        if(ground_sensor.isTrack(2))break;
    }
    motors.stop();
}

void ForwardTime(int32_t speed,int32_t ms){
    motors.run(speed,speed);
    delay(ms);
    motors.stop();
}

void ForwardUntilCrossBW(int32_t speed,int32_t spin_speed){
    while(true){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d",val);
        oledf.show();
        if(val < ground_sensor.posFromMid(-1))motors.run(-spin_speed,spin_speed);
        else if (val > ground_sensor.posFromMid(1))motors.run(spin_speed,-spin_speed);
        else motors.run(speed,speed);

        if(ground_sensor.cOnline && ground_sensor.isTrack(0) && ground_sensor.isTrack(4)){
          motors.stop();
          beep();
          break;
        }
    }
}

void ForwardStraightCross(int32_t base_speed, bool _tillBlack = true, bool _reset = true,bool _continuous = false){
    drive_motors.StraightDrive(base_speed,&PIDStraight,_reset);
    while(true){
        drive_motors.Update();
        ground_sensor.readLine(true);
        if(ground_sensor.cOnline && ground_sensor.isTrack(0) && ground_sensor.isTrack(4)){
            if(_continuous)drive_motors.ClearDrive();
            else drive_motors.Stop();
            break;
        }
    }
}

// เดินตรง ใช้ไจโร
void ForwardStraightTime(int32_t base_speed, int32_t time_ms, bool _reset = true,bool _continuous = false){
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


void Align(int32_t spin_speed){
    while(true){
        int32_t val = ground_sensor.readLine();
        if(val < ground_sensor.posFromMid(-1)+250)motors.run(-spin_speed,spin_speed);
        else if (val > ground_sensor.posFromMid(1)-250)motors.run(spin_speed,-spin_speed);
        else {
          motors.stop();
          break;
        }
    }
}

void ForwardStraightTillWhite(int32_t base_speed,bool _reset = true,bool _continuous = false){
    drive_motors.StraightDrive(base_speed,&PIDStraight,_reset);
    while(true){
        int32_t val = ground_sensor.readLine();
        drive_motors.Update();
        if(!ground_sensor.isTrack(0) && !ground_sensor.isTrack(4)){
            if(_continuous)drive_motors.ClearDrive();
            else drive_motors.Stop();
            break;
        }
    }
}

void SensorCalibrate(){
    ground_sensor.AutoCalibrate();
}