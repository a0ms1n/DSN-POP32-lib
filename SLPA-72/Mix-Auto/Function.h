#pragma once
#include "../../src/DSN-POP32.h"

int speedL = 200;
int speedR = 155;

// SENSOR PIN 0 แก้แล้วนะคั้บบบบบ
// ถ้าจะให้หุ่นยนต์ รอกระป๋องเเล้วคีบ ให้หมุนไป Run2 

// PIN, White_Value, Black_Value
LEDSensor sensors[] ={
    {1,3800,650}, // L 
    {3,2300,370}, // LM
    {0,3800,430}, // M
    {4,3500,350}, // RM 
    {2,3800,570}  // R
};

// {Sensors Refs}, AutoRotate, Error, Track
LEDSensorLine<5> ground_sensor({&sensors[0],&sensors[1],&sensors[2],&sensors[3],&sensors[4]},0,50,500);


void ForwardUntilCross(int32_t speed){ //เดินจับเส้นดำจนกว่าจะเจอแยก วิธีใช้ใส่ ForwardUntilCross(ความเร็ว);
    while(true){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d %d %d",val,(int32_t)ground_sensor.get(0),(int32_t)ground_sensor.get(4));
        oledf.show();
        if(val < ground_sensor.posFromMid(-1))motors.run(-speedL,speedR);
        else if (val > ground_sensor.posFromMid(1))motors.run(speedL,-speedR);
        else motors.run(speedL,speedR);

        if(ground_sensor.isTrack(ground_sensor.__LEFT) && ground_sensor.isTrack(4)){
          motors.stop();
          beep();
          break;
        }
    }
}

void SkipCross(int32_t speed,int32_t ms = 200){ //ใช้ตอนกำลังจะข้ามเส้น วิธีใช้ใส่SkipCross(ความเร็ว);
    while(true){
        ground_sensor.readLine();
        motors.run(speedL,speedR);
        if( !ground_sensor.isTrack(0) || !ground_sensor.isTrack(4)){
            delay(ms);
            motors.stop();
            break;
        }   
    }
}

void TurnLeft(int32_t speed,int32_t ms = 0){ 
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
    delay(ms);
    motors.stop();
}

void TurnRight(int32_t speed,int32_t ms = 0){
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
    delay(ms);
    motors.stop();
}

void ForwardTime(int32_t speed,int32_t ms){
    motors.run(speedL,speedR);
    delay(ms);
    motors.stop();
}

void ForwardUntilCrossBlackWhite(int32_t speed){
    while(true){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d",val);
        oledf.show();
        if(val < ground_sensor.posFromMid(-1))motors.run(-speed,speed);
        else if (val > ground_sensor.posFromMid(1))motors.run(speed,-speed);
        else motors.run(speed,speed);

        if(ground_sensor.cOnline && ground_sensor.isTrack(0) && ground_sensor.isTrack(4)){
          motors.stop();
          beep();
          break;
        }
    }
}
