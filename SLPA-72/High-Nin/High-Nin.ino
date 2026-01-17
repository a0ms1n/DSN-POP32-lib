#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"
#include "Music.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้

int Rotate_fix = 90;

int32_t speed_slow = 130;
int32_t speed_fast = 170;

void Run1();
void Run2();
void Run3();

void setup()
{
    // PIDRotate.SetOutputLimits(-170,170);
    beep();
    POP32_INIT();
    servo(servoPIN,startAngle);
    delay(500);
    servo(servoPIN,-1);
    Thailand_back();
    PIDRotate.gains = newRotateGains;
    PIDRotate.gains = newStraightGains;
    imu.Start();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[1].callback = Run2; // Run 2
    BasicMenu.buttons[2].callback = Run3; // Run 3
    Front.__Track = 750;
    Back.__Track = 750;
    motors.setSpeedRange(100,340);
    motors.setRatio({1.0,1.0},{1.1,1.1});
}   

void loop()
{
    BasicMenu.show();
}

void Run1(){
    imu.Start();
    beep();
    // First Turn
    // forwardTill(speed_slow,0,0,0);  
    // // forwardTime(speed_slow,200);
    
    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,320,0,0);
    // rotate(-90);
    // backwardAlign(80,1);
    // delay(300);

    // forwardTime(speed_fast, 700);
    // rotate(-90);

    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,320,0,0);
    // rotate(-90 , 0);
    // backwardAlign(80,1);

    // Check point 1
    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,320,0,0);
    // backwardTill(speed_slow,1,1,0);
    // forwardTime(speed_slow, 180 , 0 , 0);
    // rotate(-90 , 0);
    // backwardAlign(80,1);

    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,320,0,0);
    // rotate(90);
    // backwardTime(speed_slow,320,0,0);

    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,320,0,0);
    // rotate(-90);
    // backwardAlign(80,1);

    // forwardTime(speed_fast, 400);
    // rotate(-90);
    // backwardAlign(80,1);

    forwardTill(speed_slow,1,1,0); 
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow, 160 , 0 , 0);
    rotate(90);

    forwardAlign(80 , 1);
    backwardTime(speed_slow,280,0,0);
    rotate(-90);
    forwardTime(speed_fast, 600);
    forwardAlign(80 , 1);
    backwardTime(speed_slow,280,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // สะพาน
    forwardTill(speed_slow,1,1,0); 


    
    



}   

void Run2()
{
    
    // forwardTime(speed_slow , 2500 , 1 , 0);
    // Poy();

    FD2(40 , 40);
    delay(5000);
    AO();

    // backwardAlign(70 , 1);

}

void Poy()
{
    toggleServoOn();
    delay(200);
    toggleServoOff();

}

void Run3(){
    // imu.Start();
    // beep();
    // Sound::UmaPyou();
    // Thailand();
    // Music();
   //  Poy();
   backwardAlign(80 , 1);

    // forwardTill(60 , 1 , 1 , 0);
    // FD2(40 , 40);
    // delay(500);
    // AO();

}
