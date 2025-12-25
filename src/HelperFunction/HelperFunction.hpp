#pragma once
#include "HelperFunction.h"

void POP32_INIT(){
    asm(".global _printf_float");
    #ifdef _enable_IMU
    SerialUSB.begin(9600);
    Wire.setClock(1000000);
    #endif
    #ifdef _enable_PSX
    psx.Start();
    #endif
    oledf.OLED_DMA_Init();
}

void HelperFunction::CallbackPlaceHolder(){
    beep();
    beep();
    oledf.clear();
    oledf.text(0,0,1,"You haven't assign function.");
    oledf.text(0,10,1,"Press B to exit.");
    oledf.show();

    while(!SW_B());
    while(SW_B());
    beep();
}

#ifdef _enable_IMU
/// @brief Reading value from IMU
void HelperFunction::IMUTest(){
    beep();
    imu.Start();
    while(1){
        if(SW_B()){
            while(SW_B());
            return;
        }
        if(SW_A()){
            while(SW_A());
            imu.Reset();
        }
        imu.Update();
        oledf.clear();
        oledf.text(20,0,1,"IMU Test");
        oledf.text(0,9,1,"Press A to reset.");

        oledf.text(0,29,1,"Yaw Roll Pitch");
        oledf.text(0,38,1,"%.2f %.2f %.2f",(float)imu.cYaw,(float)imu.cRoll,(float)imu.cPitch);

        oledf.text(0,52,1,"dYaw : %.2f",(float)imu.dYaw);
        oledf.show();
    }
}

void HelperFunction::SpinTest(){
    motors.setSpeedRange(110,240);
    imu.Start();
    int32_t v = 0;
    while(!SW_B()){
        while(!SW_OK()){  
            if(SW_B())return;     
            v = knob(60,200);
            oledf.clear();
            oledf.text(0,0,1,"PID Spin Test");
            oledf.text(0,10,1,"(use PIDRotate)");
            oledf.text(0,30,1,"Select Angle : %d",v);
            oledf.text(0,40,1,"Kp:%.2f Ki:%.2f",(float)PIDRotate.gains.Kp,(float)PIDRotate.gains.Ki);
            oledf.text(0,50,1,"Kd:%.2f Knorm: %.2f",(float)PIDRotate.gains.Kd,(float)PIDRotate.gains.Knorm);
            oledf.show();
        }
        while(SW_OK());
        drive_motors.RotateDrive(v,PIDRotate);
        beep();
        while(drive_motors.Update()){
            oledf.clear();
            oledf.text(0,0,1,"Timer : %d",(int32_t)millis());
            oledf.text(0,20,1,"Yaw : %.2f",imu.cYaw);
            oledf.show();
        };
    }
}

void HelperFunction::StraightTest(){
    PIDStraight.SetOutputLimits(-210, 210);
    motors.setSpeedRange(50,255);
    imu.Start();
    FlagTimer ft(6000);
    int32_t v = 0;
    while(!SW_B()){
        while(!SW_OK()){  
            if(SW_B())return;     
            v = knob(50,200);
            oledf.clear();
            oledf.text(0,0,1,"PID Straight Test");
            oledf.text(0,10,1,"(use PIDStraight)");
            oledf.text(0,30,1,"Select Speed : %d",v);
            oledf.text(0,40,1,"Kp:%.2f Ki:%.2f",(float)PIDStraight.gains.Kp,(float)PIDStraight.gains.Ki);
            oledf.text(0,50,1,"Kd:%.2f Knorm: %.2f",(float)PIDStraight.gains.Kd,(float)PIDStraight.gains.Knorm);
            oledf.show();
        }
        while(SW_OK());
        drive_motors.StraightDrive(v,PIDStraight);
        beep();
        ft.set();
        while(drive_motors.Update() && !ft.check()){
            oledf.clear();
            oledf.text(0,0,1,"Timer : %d",(int32_t)millis());
            oledf.text(0,20,1,"Yaw : %.2f",imu.cYaw);
            oledf.show();
        };
        drive_motors.Stop();
    }
}

#endif

/// @brief
void HelperFunction::SensorTest(){
    while(1){
        if(SW_B()){
            break;
        }
        oledf.clear();
        oledf.text(20,0,1,"Sensor Test");
        for(uint8_t idx=0;idx<__SENSOR_NUM;idx+=2){
            oledf.text(0,9+idx/2*9,1,"%d : %d",(int)__SENSOR_PINS[idx],(int)analog(__SENSOR_PINS[idx]));
            if(idx+1<__SENSOR_NUM)oledf.text(60,9+idx/2*9,1,"%d : %d",(int)__SENSOR_PINS[idx+1],(int)analog(__SENSOR_PINS[idx+1]));
        }
        oledf.show();
    }
}

void HelperFunction::MotorTest(){
    beep();
    oledf.text(20,0,1,"Motor Test");
    oledf.text(0,9,1,"Press A to test.");
    while(1){
        knob(0,4);
        oledf.clear();
        oledf.text(20,0,1,"Motor Test");
        oledf.text(0,9,1,"Press A to test.");
        oledf.text(0,20,1,"Current Motor : %d",knob(1,4));
        oledf.show();
        if(SW_A()){
            int8_t ch = knob(1,4);
            while(SW_A());
            beep();
            oledf.text(0,30,1,"Running...");  
            oledf.show();
            motor255(ch,100);
            delay(2000);
            motor_stop(ch);
            beep();
        }
    }
}

#ifdef _enable_PSX

void HelperFunction::PsxTest(){
    beep();
    while(!SW_B()){
        oledf.text(20,0,1,"PSX Test");
        oledf.clear();
        uint32_t val = psx.read();
        oledf.text(0,10,1,"val = %d",val);
        oledf.text(0,20,1,"1st BITS : %d %d %d %d",(int)((val&0x0008) !=0 ),(int)((val&0x0004) != 0),(int)((val&0x0002) != 0),((val&0x0001) != 0));
        oledf.text(0,30,1,"2nd BITS : %d %d %d %d",(int)((val&0x0080) !=0 ),(int)((val&0x0040) != 0),(int)((val&0x0020) != 0),((val&0x0010) != 0));
        oledf.text(0,40,1,"3rd BITS : %d %d %d %d",(int)((val&0x0800) !=0 ),(int)((val&0x0400) != 0),(int)((val&0x0200) != 0),((val&0x0100) != 0));
        oledf.text(0,50,1,"3rd BITS : %d %d %d %d",(int)((val&0x8000) !=0 ),(int)((val&0x4000) != 0),(int)((val&0x2000) != 0),((val&0x1000) != 0));
        oledf.show();
    }
    while(SW_B());
    oledf.clear();
    oledf.show();
}

#endif

#ifdef __ENABLE_MAZE_ROBOT_HELPER1

/// @brief  To Overwrite 'Run' function, use BasicMenu.buttons[0].callback = (YOUR (void) FUNCTION).
VerticalMenu BasicMenu = {{
    {"Run 1",HelperFunction::CallbackPlaceHolder},
    {"Run 2",HelperFunction::CallbackPlaceHolder},
    {"Run 3",HelperFunction::CallbackPlaceHolder},
    {"Sensor Test",HelperFunction::SensorTest},
    {"Motor Test",HelperFunction::MotorTest},
    #ifdef _enable_IMU
    {"IMU Test",HelperFunction::IMUTest},  
    {"Spin Test",HelperFunction::SpinTest},
    {"Straight Test",HelperFunction::StraightTest},
    #endif
    #ifdef _enable_PSX
    {"PSX Test",HelperFunction::PsxTest},
    #endif
}};

#endif