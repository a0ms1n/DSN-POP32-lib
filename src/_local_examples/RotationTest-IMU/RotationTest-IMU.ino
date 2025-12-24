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
    double_t asum = 0;
    while(1){
        int16_t v = knob(60,200);
        if(SW_A()){
            while(SW_A());
            asum = 0;
            imu.ResetWaitZero(0.6);
            motors.run(90,-90);
            while(abs(asum)<(float)v){
                if(imu.Update())asum += imu.dYaw;
                oledf.clear();
                oledf.text(0,0,1,"%d",v);
                oledf.text(0,20,1,"%.2f %.2f",(float)imu.cYaw,(float)imu.pvYaw);
                oledf.text(0,40,1,"%.2f",(float)asum);
                oledf.show();
            }
            motors.stop();
            while(oled_dma_busy);
            oledf.clear();
            oledf.text(0,0,1,"%d",v);
            oledf.text(0,20,1,"%.2f %.2f",(float)imu.cYaw,(float)imu.pvYaw);
            oledf.text(0,40,1,"%.2f",(float)asum);
            oledf.text(0,50,1,"STOP");
            oledf.show();
            beep();
            delay(1500);
        }
        imu.Update();
        oledf.clear();
        oledf.text(0,0,1,"%d",v);
        oledf.text(0,20,1,"%.2f %.2f",(float)imu.cYaw,(float)imu.pvYaw);
        oledf.text(0,40,1,"%.2f",(float)asum);
        oledf.show();
    }
}