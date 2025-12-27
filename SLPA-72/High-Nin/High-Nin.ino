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
    Front.__Track = 700;
    Back.__Track = 700;
    motors.setSpeedRange(85,250);
    motors.setRatio({1,1.1},{1.0,1.0});
}   

void loop(){
    BasicMenu.show();
}

void Run1(){
    imu.Start();
    beep();
    // First Turn
    forwardTill(200,0,1,1);  
    forwardTime(200,300,0,1);
    forwardTill(100,1,0,1);
    
    backwardTime(100,350,0,0);
    rotate(-90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);

    // Second Turn
    forwardTime(200,300,1,1);
    forwardTime(150,100,0,1);
    forwardTill(100,1,0,0);

    backwardTime(100,350,0,0);
    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);

    // Third Turn
    forwardTime(180,200,1,1);
    forwardTill(100,1,0,0);

    backwardTime(100,350,0,0);
    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);

    // Straight And Back
    forwardTime(170,200,1,1);
    forwardTime(130,200,0,1);
    forwardTill(100,1,0,1);
    backwardTime(100,150,0,0);
    Run2();
    backwardTime(170,200,1,1);
    backwardTime(130,200,0,1);
    backwardTill(100,1,0,0);

    // 4th Turn
    forwardTime(80,200,0,0);
    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);

    // 5th Turn
    forwardTime(170,200,1,1);
    forwardTime(150,300,0,1);
    forwardTill(100,1,0,0);
    backwardTime(100,350,0,0);
    rotate(-90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);

    // 6th Turn
    forwardTime(150,400,0,1);
    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);

    // Up Stair and 7th Turn
    forwardTime(190,300,1,1);
    forwardTime(150,200,0,1);
    forwardTill(100,1,0,0);

    backwardTime(100,350,0,0);
    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);

    // Down Stair and 8th Turn
    forwardTime(150,200,1,1);
    forwardTime(160,400,0,1);
    forwardTime(110,100,0,1);
    forwardTill(100,1,0,0);

    backwardTime(100,350,0,0);
    rotate(90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);

    // 9th Turn
    forwardTime(200,270,1,0);
    rotate(90);

    // 1st Check Point
    forwardTime(200,270,1,0);
    backwardTime(200,270,0,0);
    backwardTill(100,1,0);

    // 10th Turn and GO
    forwardTime(100,350,0,0);
    rotate(-90);

    forwardTime(200,270,1,0);
    forwardTill(100,1,0,0);

    // 11th Turn

    backwardTime(100,350,0,0);
    rotate(-90);
    backwardTill(75,1,1);
    backwardAlign(60,1,100);


}   

void Run2(){
    toggleServoOn();
    delay(200);
    toggleServoOff();

}

void Run3(){
    Sound::UmaPyou();

}
