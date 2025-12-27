#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้


void Run1();
void Run2();
void Run3();

void setup(){
    beep();
    servo(1,130);
    delay(500);
    servo(1,-1);
    POP32_INIT();
    imu.Start();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[1].callback = Run2; // Run 2
    BasicMenu.buttons[2].callback = Run3; // Run 3
    Front.__Track = 750;
    Back.__Track = 750;
    motors.setSpeedRange(90,250);
    motors.setRatio({1,1.3},{1.0,1.0});
}   

void loop(){
    BasicMenu.show();
}

void Run1(){
    imu.Start();
    beep();
    forwardTill(80,0,1,0);  
    forwardTill(80,1,1,0);   
    backwardTime(60,300,1,0);
    rotate(-90);

}

void Run2(){
    toggleServoOn();

}

void Run3(){

}