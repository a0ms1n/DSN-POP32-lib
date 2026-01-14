// LANG-TH : This example will be removed soon.



// เข้าไปเเก้/ดู PIN ใน Config.h
#include "Config.h"
#include "Function.h"

int32_t can_sensor_PIN = 8;
int32_t can_sensor_val = 300;
int32_t Button = 7;

int GrabPIN = 2;
int ArmUp = 3;

void Run();

void setup(){
    beep();
    servo(GrabPIN,100);
    servo(GrabPIN,-1);
    POP32_INIT();
    BasicMenu.buttons[0].callback = Run;
    BasicMenu.buttons[1].callback = Run2;
    BasicMenu.buttons[2].callback = Run3;
    motors.setSpeedRange(100,255);
    imu.Start();
    PIDStraight.SetOutputLimits(-210, 210);
    motors.setSpeedRange(50,255);
    
    //motors.setReverse({1},{1});
    ground_sensor.update_mid();

    // เปอร์เซ็นจับค่าดำ 0 - 1000
    ground_sensor.__Track = 800;
}   

void loop(){
    BasicMenu.show();
}

void Run(){
    ForwardStraightTillWhite(200);
    ForwardUntilCross(200,180);
    SkipCross(190,350);
    TurnLeft(190);
    Align(150);
    
    ForwardUntilCross(200,180);
    SkipCross(190,350);
    TurnLeft(200);
    Align(150);

    ForwardUntilCross(200,180);
    SkipCross(190,350);
    TurnRight(200);
    Align(150);
    // ForwardStraightCross(160);
    ForwardUntilCrossBW(155,120);
    ForwardStraightTime(-140,500);
    Align(160);
    ForwardUntilCross(115,120);

    ground_sensor.__Track = 500;
    ForwardStraightTillWhite(145);
    ground_sensor.__Track = 700;
    ForwardStraightTime(145,300);
    ForwardStraightTime(-140,500);
    ForwardUntilCross(170,150);
    Align(160);

    ForwardStraightTime(180,1180);
    Align(160);
    rotate(-90);
    ForwardStraightTillWhite(190);
    
    ForwardTime(200,220);
    ForwardUntilCross(170,150);
    rotate(-90);


}

void RunEx(){

    
}

void Run2(){
    servo(GrabPIN,100);
    delay(1000);
    servo(GrabPIN,-1);
    int cnt = 3;
    while(cnt>=0){
        oledf.clear();
        oledf.text(0,0,1,"%d",(int)analog(can_sensor_PIN));
        oledf.show();
        if(analog(can_sensor_PIN) >= can_sensor_val)cnt--;
        else cnt = 3;
        delay(100);
    }
    beep();
    beep();
    delay(1000);
    beep();
    servo(GrabPIN,0);
    Run();

}

void Run3(){

    ground_sensor.__Track = 500;
    ForwardStraightTillWhite(155);
    // ForwardUntilCrossBW(200);
    
    // servo(GrabPIN, 100);
    // delay(1500); 
    // servo(GrabPIN, 0);
    // delay(1500);
    // servo(GrabPIN, 100);

    // while(true){
    //    oled.clear();
    //     oled.text(0,0,0,"%d",(int32_t)analog(Button));
    //     oled.show();


}
                                                
                                                

