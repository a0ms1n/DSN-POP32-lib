#pragma once
#include "Config.h"
#include "../../src/DSN-POP32.h"

// SENSOR PIN 0 แก้แล้วนะคั้บบบบบ
// ถ้าจะให้หุ่นยนต์ รอกระป๋องเเล้วคีบ ให้หมุนไป Run2 

// PIN, White_Value, Black_Value
int32_t _right_sensor = 5;
int32_t _mid_sensor = 3;
int32_t _left_sensor = 1;
double RightAngle = 87.0;

int32_t can_sensor_PIN = 8;
int32_t can_sensor_val = 210;
int32_t Button = 7;

int GrabPIN = 2;
int ArmUp = 3;

LEDSensor sensors[] ={
    {5,3800,1500}, // L - ซ้ายสุด
    {1,3800,1500}, // L2 
    {3,3800,1500}, // L3
    {0,3800,1500}, // M
    {4,3800,1600}, // R3 
    {2,3800,1600},  // R2
    {6,3800,800}  // R - ขวาสุด
};

// {Sensors Refs}, AutoRotate, Error, Track
LEDSensorLine<7> ground_sensor({&sensors[0],&sensors[1],&sensors[2],&sensors[3],&sensors[4],&sensors[5],&sensors[6]},0,50,500);

PIDGains newRotateGains = {2.7,3.1,1.3,1.3,0}; 

void rotate(int32_t angle,bool reset = true){
    motors.stop();
    drive_motors.RotateDrive(angle,&PIDRotate,reset,500,0.8);
    while(drive_motors.Update());
    motors.stop();
}

void ForwardUntilTime(int32_t speed,int32_t spin_speed,int32_t ms){
    FlagTimer ft(ms);
    ft.set();
    while(true){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d %d %d",val,(int32_t)ground_sensor.get(0),(int32_t)ground_sensor.get(_right_sensor));
        oledf.show();
        if(val < ground_sensor.posFromMid(-1))motors.run(-spin_speed,spin_speed);
        else if (val > ground_sensor.posFromMid(1))motors.run(spin_speed,-spin_speed);
        else motors.run(speed,speed);

        if(ft.check()){
          motors.stop();
          break;
        }
    }
}

void ForwardUntilCross(int32_t speed,int32_t spin_speed){ //เดินจับเส้นดำจนกว่าจะเจอแยก วิธีใช้ใส่ ForwardUntilCross(ความเร็ว);
    double_t angle_diff = 0.0;
    while(true){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d %d %d",val,(int32_t)ground_sensor.get(0),(int32_t)ground_sensor.get(_right_sensor));
        oledf.show();
        if(val < ground_sensor.posFromMid(-1))motors.run(-spin_speed,spin_speed);
        else if (val > ground_sensor.posFromMid(1))motors.run(spin_speed,-spin_speed);
        else motors.run(speed,speed);

        if(ground_sensor.isTrack(_left_sensor) && ground_sensor.isTrack(_right_sensor)){
          motors.stop();
          break;
        }
    }
}

void SkipCross(int32_t speed,int32_t ms = 200){ //ใช้ตอนกำลังจะข้ามเส้น วิธีใช้ใส่SkipCross(ความเร็ว);
    while(true){
        ground_sensor.readLine();
        motors.run(speed,speed);
        if( !ground_sensor.isTrack(_left_sensor) && !ground_sensor.isTrack(_right_sensor)){
            delay(ms);
            motors.stop();
            break;
        }   
    }
}

void TurnLeft(int32_t speed){ 
    // ใช้คู่กับskipcross วิธีใช้skipCross(ความเร็ว);
    //                     TurnLeft(ความเร็ว);

    double_t angle = 0;
    while(!imu.Update());

    while(angle <= RightAngle){
        if(imu.Update()){
            angle += imu.dYaw;
        }
        motors.run(-speed,speed);
        ground_sensor.readLine();
        if(ground_sensor.isTrack(_right_sensor))break;
    }
    while(angle <= RightAngle){
        if(imu.Update()){
            angle += imu.dYaw;
        }
        motors.run(-speed,speed);
        ground_sensor.readLine();
        if(ground_sensor.isTrack(_mid_sensor))break;
    }
    motors.stop();
}

void TurnRight(int32_t speed){
    double_t angle = 0;
    while(!imu.Update());
    
    while(angle >= -RightAngle){
        if(imu.Update()){
            angle += imu.dYaw;
        }
        motors.run(speed,-speed);
        ground_sensor.readLine();
        if(ground_sensor.isTrack(_left_sensor))break;
    }
    while(angle >= -RightAngle){
        if(imu.Update()){
            angle += imu.dYaw;
        }
        motors.run(speed,-speed);
        ground_sensor.readLine();
        if(ground_sensor.isTrack(_mid_sensor))break;
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
        if (!ground_sensor.cOnline)motors.run(speed,speed);
        else if(val < ground_sensor.posFromMid(-1))motors.run(-spin_speed,spin_speed);
        else if (val > ground_sensor.posFromMid(1))motors.run(spin_speed,-spin_speed);
        else motors.run(speed,speed);

        if(ground_sensor.cOnline && ground_sensor.isTrack(_left_sensor) && ground_sensor.isTrack(_right_sensor)){
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
        if(ground_sensor.cOnline && ground_sensor.isTrack(_left_sensor) && ground_sensor.isTrack(_right_sensor)){
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

void ForwardStraightTillWhite(int32_t base_speed,int32_t ms = 0,bool _reset = true,bool _continuous = false){
    drive_motors.StraightDrive(base_speed,&PIDStraight,_reset);
    while(true){
        int32_t val = ground_sensor.readLine();
        drive_motors.Update();
        if(!ground_sensor.isTrack(_left_sensor) && !ground_sensor.isTrack(_right_sensor)){
            if(_continuous)drive_motors.ClearDrive();
            else drive_motors.Stop();
            break;
        }
    }

    
    motors.run(base_speed,base_speed);
    delay(ms);
    motors.stop();
}

void ForwardUntilButton(int32_t speed,int32_t spin_speed){
    while(true){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d %d %d",val,(int32_t)ground_sensor.get(0),(int32_t)ground_sensor.get(_right_sensor));
        oledf.show();
        if(val < ground_sensor.posFromMid(-1))motors.run(-spin_speed,spin_speed);
        else if (val > ground_sensor.posFromMid(1))motors.run(spin_speed,-spin_speed);
        else motors.run(speed,speed);

        if(analog(Button) <= 10){
          motors.stop();
          break;
        }
    }
}

void SensorCalibrate(){
    ground_sensor.AutoCalibrate(4000);
}

namespace Sound{
    void ChillGuy(){
        static int16_t soundseq[][2] = {
            {311,231},{622,231},{698,231},{831,346},{932,346},{1047,2077},{208,231},{311,231},{622,231},{698,231},{831,346},{932,346},{831,2077},{208,231},{311,231},{622,231},{698,231},{831,346},{932,346},{1047,2077},{208,231},{311,231},{622,231},{698,231},{831,346},{932,346},{831,2077},{1047,231},{932,231},{831,231},{698,231},{622,231},{523,231},{622,231},{698,231},{831,231},{932,231},{1047,231},{932,231},{831,231},{659,231},{831,231},{659,231},{831,231},{659,231},{831,231},{932,1154},{208,231},{311,231},{622,231},{698,231},{831,346},{932,346},{1047,2077},{208,231},{311,231},{622,231},{698,231},{831,346},{932,346},{831,2077},{208,231},{311,231},{622,231},{698,231},{831,346},{932,346},{1047,2077},{208,231},{311,231},{622,231},{698,231},{831,346},{932,346},{831,2077},{1047,231},{932,231},{831,231},{698,231},{622,231},{523,231},{622,231},{698,231},{831,231},{932,231},{1047,231},{932,231},{831,231},{659,231},{831,231},{659,231},{831,231},{659,231},{831,231},{932,1038},{208,231},{698,231},{831,231},{932,231},{1047,346},{1245,346},{1397,2077},{208,231},{698,231},{831,231},{932,231},{1047,346},{1245,346},{1047,2192}
        };
        for(int i=0;i<109;i++){
            sound(soundseq[i][0],soundseq[i][1]);
            if(SW_OK())break;
        }
    }
}