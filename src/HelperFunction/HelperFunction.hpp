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

#ifdef __ENABLE_MAZE_ROBOT_HELPER1

/// @brief  To Overwrite 'Run' function, use BasicMenu.buttons[0].callback = (YOUR (void) FUNCTION).
VerticalMenu BasicMenu = {{
    {"Run",CallbackPlaceHolder},
    {"IMU Test",IMUTest},    
    {"Sensor Test",SensorTest},
    {"Motor Test",MotorTest}
}};
#endif