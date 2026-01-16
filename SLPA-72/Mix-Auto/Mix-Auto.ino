// LANG-TH : This example will be removed soon.



// เข้าไปเเก้/ดู PIN ใน Config.h

#include "Function.h"
#define DE2000() delay(2000);

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
    ground_sensor.__Track = 500;
    BasicMenu.buttons.push_back({
        "Sensor Calibrate",SensorCalibrate
    });
}   

void loop(){
    BasicMenu.show();
}

void Run(){
    ForwardStraightTillWhite(220,400);
    ForwardUntilCross(220,150);
    SkipCross(140,250);
    TurnLeft(170);
    Align(150);
    
    ForwardUntilCross(220,150);
    SkipCross(140,250);
    TurnLeft(170);
    Align(150);

    ForwardUntilCross(200,180);
    SkipCross(120,350);
    TurnRight(170);
    Align(150);
    
    ForwardUntilCrossBW(155,120);
    
    ForwardStraightTime(-140,400);
    Align(110);
    ForwardUntilCross(100,110);

    ForwardStraightTillWhite(145);
    ForwardStraightTime(145,300);
    ForwardUntilCross(170,150);
    Align(160);

    ForwardStraightTime(140,1580);
    Align(160);
    rotate(-90);
    ForwardStraightTillWhite(190);
    
    ForwardTime(170,220);

    ForwardUntilCross(170,150);
    SkipCross(140,300);
    TurnRight(150);
    Align(160);
    ForwardUntilTime(240,150,4200);
    ForwardUntilCross(190,150);
    SkipCross(140,300);

    ForwardUntilCross(220,150);
    SkipCross(140,300);
    ForwardUntilButton(220,150);
    Sound::ChillGuy();

}

void Run2(){
    CanPoy();
    LiftDown();
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
    delay(2000);
    beep();
    CanGrab();
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
                                                
                                                

