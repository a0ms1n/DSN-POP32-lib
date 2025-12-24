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
    imu.Start();
    motors.run(120,-120);
    while(1){
        if(SW_B()){
            while(SW_B());
            beep();
            motors.stop();
            return;
        }
        imu.Update();
        oledf.clear();
        oledf.text(0,0,1,"Yaw = %.2f",(float)imu.cYaw);
        oledf.show();
    }
}