// LANG-TH : This example will be removed soon.



// เข้าไปเเก้/ดู PIN ใน Config.h
#include "Config.h"
#include "Function.h"

int32_t can_sensor_PIN = 8;
int32_t can_sensor_val = 200;
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
    
    //motors.setReverse({1},{1});
    ground_sensor.update_mid();

    // เปอร์เซ็นจับค่าดำ 0 - 1000
    ground_sensor.__Track = 650;
}   

void loop(){
    BasicMenu.show();
}

void Run(){

    ForwardTime(200,500);
    ForwardUntilCross(210);
    SkipCross(180);
    TurnLeft(220);
    beep();

    ForwardUntilCross(220);
    SkipCross(180);
    TurnLeft(220);
    
    ForwardUntilCross(220);
    SkipCross(180);
    TurnRight(180);
    
    ForwardUntilCross(160);
    ForwardTime(160,3400);
    beep();

    ground_sensor.__Track = 850;
    ForwardStraightTime(200,2000);
        
    return;
    // ForwardStraightTill() ;;
    ForwardUntilCross(160);
    SkipCross(180);
    TurnRight(230);

    ForwardUntilCross(220);
    SkipCross(180);
    TurnRight(230);

    ForwardUntilCross(220);
    SkipCross(180);
    TurnRight(230);

    ForwardTime(160,1500);
    ForwardUntilCross(220);

    
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
    while(true);
    Run();

}

void Run3(){

    while(true){
        oled.clear();
        oled.text(0,0,1,"%d",(int32_t)analog(Button));
        oled.show();
    }

    // servo(GrabPIN, 100);
    // delay(1500); 
    // servo(GrabPIN, 0);
    // delay(1500);
    // servo(GrabPIN, 100);
}