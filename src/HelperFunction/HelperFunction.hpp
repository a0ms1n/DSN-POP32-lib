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

void CallbackPlaceHolder(){
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
void IMUTest(){
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
#endif

/// @brief
void SensorTest(){
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

void MotorTest(){
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

void PsxTest(){
    // #define PSB_IDLE      	0x0000
    // #define PSB_SELECT      0x0001
    // #define PSB_START       0x0008


    // #define PSB_L2          0x0100
    // #define PSB_R2          0x0200
    // #define PSB_L1          0x0400
    // #define PSB_R1          0x0800

    // // Same as Right
    // #define PSB_GREEN       0x1000
    // #define PSB_RED         0x2000
    // #define PSB_BLUE        0x4000
    // #define PSB_PINK        0x8000

    // // Left Keys Pad and Stiks
    // #define PSB_PAD_UP      0x0010
    // #define PSB_PAD_RIGHT   0x0020
    // #define PSB_PAD_DOWN    0x0040
    // #define PSB_PAD_LEFT    0x0080

    // #define PSB_LSTIK_LEFT  0x0010
    // #define PSB_LSTIK_DOWN  0x0020
    // #define PSB_LSTIK_RIGHT 0x0040
    // #define PSB_LSTIK_UP    0x0080

    // // Right Keys Pad and Stiks
    // #define PSB_TRIANGLE    0x1000
    // #define PSB_CIRCLE      0x2000
    // #define PSB_CROSS       0x4000
    // #define PSB_SQUARE      0x8000

    // #define PSB_RSTIK_LEFT 	0x1000
    // #define PSB_RSTIK_DOWN  0x2000
    // #define PSB_RSTIK_RIGHT 0x4000
    // #define PSB_RSTIK_UP    0x8000
    beep();
    while(!SW_B()){
        oledf.text(20,0,1,"PSX Test");
        oledf.clear();
        uint32_t val = psx.read();
        
        oledf.text(0,10,1,"1st BITS : %d %d %d %d",val&0x0008,val&0x0004,val&0x0002,val&0x0001);
        oledf.text(0,20,1,"2nd BITS : %d %d %d %d",val&0x0080,val&0x0040,val&0x0020,val&0x0010);
        oledf.text(0,30,1,"3rd BITS : %d %d %d %d",val&0x0800,val&0x0400,val&0x0200,val&0x0100);
        oledf.text(0,30,1,"3rd BITS : %d %d %d %d",val&0x8000,val&0x4000,val&0x2000,val&0x1000);
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
    {"Run",CallbackPlaceHolder},
    #ifdef _enable_IMU
    {"IMU Test",IMUTest},  
    #endif
    #ifdef _enable_PSX
    {"PSX Test",PsxTest},
    #endif
    {"Sensor Test",SensorTest},
    {"Motor Test",MotorTest}
}};

#endif