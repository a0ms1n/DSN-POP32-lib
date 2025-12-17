#pragma once
#include "HelperFunction.h"

void POP32_INIT(){
    asm(".global _printf_float");
    SerialUSB.begin(9600);
    Wire.setClock(1000000);
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
        oledf.text(0,9,1,"Press B to exit.");
        oledf.text(0,18,1,"Press A to reset");

        oledf.text(0,35,1,"Yaw : %f",(float)imu.cYaw);
        oledf.text(0,44,1,"Pitch : %f",(float)imu.cPitch);
        oledf.text(0,53,1,"Roll : %f",(float)imu.cRoll);

        oledf.text(0,80,1,"IMU Status : %d",(int)imu.status);
        oledf.text(0,89,1,"Timer : %d",(int)millis());
        oledf.show();
    }
}

#ifdef __ENABLE_MAZE_ROBOT_HELPER1

/// @brief  To Overwrite 'Run' function, use BasicMenu.buttons[0].callback = (YOUR (void) FUNCTION).
VerticalMenu BasicMenu = {{
    {"Run",CallbackPlaceHolder},
    {"IMU Test",IMUTest},    
}};
#endif