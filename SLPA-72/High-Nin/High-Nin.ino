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
    imu.Start();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[1].callback = Run2; // Run 2
    BasicMenu.buttons[2].callback = Run3; // Run 3
    Front.__Track = 750;
    Back.__Track = 750;
    motors.setSpeedRange(70,255);
    motors.setRatio({1,1.3},{1.0,1.0});
}   

void loop(){
    BasicMenu.show();
}

void Run1(){
    beep();
    forwardTill(120,0,1,1);  
    forwardTime(100,300,0,1);
    forwardTime(100,300,0,1);
    forwardTill(80,1,0);   
    backwardTime(90,300,false);
    rotate(90);

    // forwardTime(120,300,1,0);
    // forwardTime(100,300,0,0);
    // forwardTill(80,1,0);  

}

void Run2(){

}

void Run3(){

}