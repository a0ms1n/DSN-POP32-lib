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
    POP32_INIT();
    servo(servoPIN,startAngle);
    delay(500);
    servo(servoPIN,-1);
    PIDRotate.gains = newRotateGains;
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
    forwardTill(150,0,1,1);  
    forwardTime(150,200,0,1);
    forwardTill(100,1,0,1);
    backwardTime(100,350,0,0);
    
    rotate(-90);
    backwardTill(80,1,1);
    backwardAlign(80,3);

    forwardTime(170,300,1,1);
    forwardTime(120,100,0,1);
    forwardTill(100,1,0,0);
    backwardTime(100,350,0,0);
    
    rotate(90);
    backwardTill(80,1,1);
    backwardAlign(80,3);

    forwardTime(150,200,1,1);
    forwardTill(100,1,0,0);
    backwardTime(100,350,0,0);

}

void Run2(){
    toggleServoOn();
    delay(1000);
    toggleServoOff();

}

void Run3(){
    forwardAlign(60,3);

}