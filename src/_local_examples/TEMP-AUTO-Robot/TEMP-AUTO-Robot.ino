// LANG-TH : This example will be removed soon.



// เข้าไปเเก้/ดู PIN ใน Config.h
#include "Config.h"
#include "../../DSN-POP32.h"

bool _onLine = false;
int32_t _current_pos = 0;

// PIN, White_Value, Black_Value
LEDSensor sensors[] ={
    {1,1000,500}, // L 
    {3,1000,500}, // LM
    {4,1000,500}, // RM 
    {2,1000,500}  // R
};


LEDSensorLine<4> ground_sensor({&sensors[0],&sensors[1],&sensors[2],&sensors[3]},0,50,400);

void Run();

void setup(){
    beep();
    POP32_INIT();
    BasicMenu.buttons[0].callback = Run;
    motors.setSpeedRange(255,100);
    //motors.setReverse({1},{1});
    ground_sensor.update_mid();
}   

void loop(){
    BasicMenu.show();
}

void Run(){
    while(!SW_B()){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d",val);
        oledf.show();
        if(val < 1000)motors.run(-127,127);
        else if (val > 2000)motors.run(127,-127);
        else motors.run(127,127);
    }   
}
