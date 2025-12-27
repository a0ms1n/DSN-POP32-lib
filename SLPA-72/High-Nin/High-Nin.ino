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
    motors.setSpeedRange(85,250);
    motors.setRatio({1,1.2},{1.0,1.0});
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
    backwardTill(75,1,1);
    backwardAlign(65,1);

    forwardTime(170,300,1,1);
    forwardTime(120,100,0,1);
    forwardTill(100,1,0,0);
    backwardTime(100,350,0,0);
    
    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(65,1);

    forwardTime(150,200,1,1);
    forwardTill(100,1,0,0);
    backwardTime(100,350,0,0);
    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(65,1);

    forwardTime(150,100,1,1);
    forwardTime(120,200,0,1);
    forwardTill(100,1,0,1);
    backwardTime(100,150,0,0);
    Run2();
    backwardTime(150,100,1,1);
    backwardTime(120,200,0,1);
    backwardTill(100,1,0,0);
    forwardTime(100,350,0,0);

    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(65,1);
    forwardTime(150,100,1,1);
    forwardTime(120,200,0,1);
    forwardTill(100,1,0,0);



}

void Run2(){
    toggleServoOn();
    delay(200);
    toggleServoOff();

}

void Run3(){
    Sound::UmaPyou();

}