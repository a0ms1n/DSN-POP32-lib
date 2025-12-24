#include "Config.h"
#include <DSN-POP32.h>

void Run();

void setup(){
    beep();
    POP32_INIT();
    BasicMenu.buttons[0].callback = Run;

}   

void loop(){
    BasicMenu.show();
}

void Run(){
    PIDRotate.SetOutputLimits(-230, 230);
    PIDRotate.gains = {3.0,1.0,1.0};
    motors.setSpeedRange(255,80);
    imu.Start();
    int32_t v = 0;
    while(!SW_OK()){        
        v = knob(60,200);
        oledf.clear();
        oledf.text(0,0,1,"Select Angle : %d",v);
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