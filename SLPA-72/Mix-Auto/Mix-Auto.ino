// LANG-TH : This example will be removed soon.



// เข้าไปเเก้/ดู PIN ใน Config.h
#include "Config.h"
#include "Function.h"

void Run();

void setup(){
    beep();
    POP32_INIT();
    BasicMenu.buttons[0].callback = Run;
    BasicMenu.buttons[1].callback = Run2;
    motors.setSpeedRange(100,255);
    //motors.setReverse({1},{1});
    ground_sensor.update_mid();
}   

void loop(){
    BasicMenu.show();
}

void Run(){
    ForwardUntilCross(130);
}

void Run2(){
    while(true){
        ground_sensor.read();
        int32_t val = ground_sensor.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d %d",val,(int32_t)ground_sensor.posFromMid(-1.5));
        oledf.show();
        motors.run(-157,157);
        if(val>=ground_sensor.__MIDDLE_VALUE)break;
    }
    motors.stop();
}