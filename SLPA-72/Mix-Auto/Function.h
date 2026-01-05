#pragma once
#include "../../src/DSN-POP32.h"

// PIN, White_Value, Black_Value
LEDSensor sensors[] ={
    {1,1500,300}, // L 
    {3,1400,300}, // LM
    {0,2600,900}, // M
    {4,1400,400}, // RM 
    {2,1200,450}  // R
};

// {Sensors Refs}, AutoRotate, Error, Track
LEDSensorLine<5> ground_sensor({&sensors[0],&sensors[1],&sensors[2],&sensors[3],&sensors[4]},1,50,400);



void ForwardUntilCross(int32_t speed){
    while(!SW_B()){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d",val);
        oledf.show();
        if(val < ground_sensor.posFromMid(-1))motors.run(-speed,speed);
        else if (val > ground_sensor.posFromMid(1))motors.run(speed,-speed);
        else motors.run(speed,speed);

        if(ground_sensor.isTrack(ground_sensor.__LEFT) && ground_sensor.isTrack(ground_sensor.__RIGHT)){
          motors.stop();
          beep();
          break;
        }
    }   
}