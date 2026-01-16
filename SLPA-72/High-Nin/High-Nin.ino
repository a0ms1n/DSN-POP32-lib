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
    BasicMenu.buttons[3].callback = Run4; 
    Front.__Track = 750;
    Back.__Track = 750;
    motors.setSpeedRange(110,340);
    motors.setRatio({1.0,1.1},{1.0,1.0});
}   

void loop()
{
    BasicMenu.show();
}

void Run1(){
    imu.Start();
    beep();
    // First Turn
    forwardTill(speed_slow,0,0,0);  
    forwardTime(speed_slow,200,0);
    
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70,1);

    // forwardTime(speed_fast,650,0,0);
    forwardTill(speed_slow + 10 ,1,1,0);
    backwardTime(speed_slow,360,0,0);
    rotate(90);
    backwardAlign(70,1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,270,0,0);
    rotate(90 , 0);
    backwardAlign(70,1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,300,0,0);
    rotate(-90 , 0);
    backwardAlign(70,1);

    // ไปหา blue
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,350,0,0);
    rotate(93);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,350,0,0);
    rotate(90);
    backwardAlign(70,1);

    // blue
    forwardTill(speed_slow,1,1,0); 
    // forwardTime(speed_slow, 20 , 0);
    Poy();
    backwardTime(speed_slow,250,0,0);
    backwardAlign(70 , 1);

    forwardTime(speed_slow, 70,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,340,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    // ไปหาตะเกียบ
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,390,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    // ตะเกียบ
    forwardTime(60, 2200 , 0 , 0);
    // forwardTill(speed_slow,1,1,0); 
    forwardAlign(70 , 1);
    backwardTime(60, 2100 , 0 , 0);
    backwardAlign(70 , 1);

    forwardTime(speed_slow, 140,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,300,0,0);
    rotate(-90 , 0);
    backwardAlign(70 , 1);

    forwardTime(speed_slow, 470,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,300,0,0);
    rotate(90 , 0);
    backwardAlign(70 , 1);

    // ออก
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,270,0,0);
    rotate(-90 , 0);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,300,0,0);
    rotate(-90 , 0);
    backwardAlign(70 , 1);

    forwardTime(speed_slow , 470 , 0 , 0);
    rotate(90);
    backwardAlign(70 , 1);

    // สะพาน
    forwardTill(speed_slow - 30,1,1,0); 
    backwardTime(speed_slow,300,0,0);
    rotate(-90 , 0);
    backwardAlign(70 , 1);

    // ออกสะพาน
    forwardTill(speed_slow ,1,1,1);
    backwardTime(speed_slow,300,0,0);
    rotate(-90);
    // backwardAlign(70,1);

    // ไปหาแดง
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,335,0,0);
    rotate(-90);
    backwardAlign(70,1);

    // Red
    forwardTill(speed_slow,1,1,0); 
    // backwardTime(speed_slow,230,0,0);
    Poy();
    backwardAlign(70 , 1);

    forwardTime(speed_slow , 220 , 0 , 0);
    rotate(-90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,340,0,0);
    rotate(90);
    backwardAlign(70,1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,300,0,0);
    rotate(-88);
    backwardTime(70,300,0,0);
    backwardAlign(70,1);

    // ไปหา blackhold
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,330,0,0);
    rotate(-88);

    forwardAlign(60 , 1);
    forwardTime(speed_slow,550,0,0); 
    forwardAlign(60 , 1);
    // backwardTime(speed_slow,300,0,0);
    Poy();
    backwardAlign(70 , 1);
    backwardTime(speed_slow,700,0,0);
    forwardAlign(70 , 1);
    backwardTill(speed_slow , 1 , 1 ,0);
    forwardTime(speed_slow , 270 , 0 , 0);

    rotate(-90);
    backwardAlign(70 , 1);
    forwardTill(speed_slow + 20 ,1,1,0); 
    backwardTime(speed_slow,360,0,0);
    // forwardAlign(70 , 1);
    backwardTime(speed_slow,150,0,0);
    Poy();
    Thailand();
    
    



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
    Thailand();
    // Music();

    // forwardTill(60 , 1 , 1 , 0);
    // FD2(40 , 40);
    // delay(500);
    // AO();

}

void Run4(){
    
}