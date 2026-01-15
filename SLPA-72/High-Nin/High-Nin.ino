#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"

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
    // PIDRotate.SetOutputLimits(-180,180);
    beep();
    POP32_INIT();
    servo(servoPIN,startAngle);
    delay(500);
    servo(servoPIN,-1);
    Thailand_back();
    PIDRotate.gains = newRotateGains;
    imu.Start();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[1].callback = Run2; // Run 2
    BasicMenu.buttons[2].callback = Run3; // Run 3
    Front.__Track = 800;
    Back.__Track = 800;
    motors.setSpeedRange(90,340);
    motors.setRatio({1.0,1.0},{1.0,1.1});
}   

void loop()
{
    BasicMenu.show();
}

void Run1(){
    imu.Start();
    beep();
    // First Turn
    forwardTill(speed_slow,0,0,1);  
    forwardTime(speed_fast,150,0,0);
    
    forwardTill(speed_slow ,1,1,1);
    backwardTime(speed_slow,300,0,0);
    rotate(-90);
    backwardAlign(60,1);

    // forwardTime(speed_slow,200,0,0);
    forwardTill(speed_slow ,1,1,1);
    backwardTime(speed_slow,320,0,0);
    rotate(-90);

    forwardTime(speed_slow ,360,0,0);
    // backwardTime(speed_slow,20,1,0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow -30,1,1,1);
    backwardTime(speed_slow,300,0,0);
    rotate(90);

    // ไปหา blue
    backwardAlign(80 , 1);
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,240,0,0);
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow, 200 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);
    
    // ออก blue
    forwardTill(speed_slow,1,0,0); 
    backwardTime(speed_slow,280,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,320,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,350,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    // หันไปเจอตะเกียบ
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    // ตะเกียบ
    forwardTime(60, 1900 , 0 , 0);
    // สะพาน
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,320,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,320,0,0);
    rotate(-90);

    forwardTill(speed_slow,1,1,0);
    backwardTime(speed_slow,300,0,0);
    rotate(90);
    // backwardTime(speed_slow,500,0,0);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,280,0,0);
    rotate(-90 , 0);
    backwardAlign(80 , 1);

    forwardTill(speed_slow - 10,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90 , 0);
    backwardAlign(80 , 1);

    // ไปหาแดง
    forwardTime(speed_slow - 20,570,1,0); 
    // backwardTime(speed_slow,250,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    // red
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,280,0,0);
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow, 200 , 0 , 0);
    rotate(90 , 0);
    backwardTime(speed_slow - 30,500,0,0);

    //ออกแดง
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,320,0,0);
    rotate(90 , 0 );
    backwardAlign(80 , 1);

    forwardTime(speed_slow,470,1,0); 
    // backwardTime(speed_slow,250,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    // ไปหาเหลือง
    forwardTime(speed_slow,840,0,0); 
    // forwardAlign(80 , 1);
    // backwardTime(speed_slow,240,1,0);
    rotate(90);

    // yellow
    forwardTill(speed_slow - 30,1,1,0); 
    backwardTime(speed_slow - 30,300,0,0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow,10,0,0);
    Poy();
    backwardTime(speed_slow,700,0,0);
    backwardAlign(80 , 1);
    forwardTime(speed_slow,500,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // check point 1
    forwardTill(speed_slow - 20,1,0,0); 
    backwardTime(speed_slow,320,0,0);
    // forwardAlign(80 , 1);
    backwardAlign(80 , 1);
    forwardTime(speed_slow , 150 , 1 , 0);
    rotate(90);

    forwardTill(speed_slow - 20,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    // เข้า black hold
    // forwardTime(speed_slow + 30 , 300 , 0 , 0);
    forwardTill(speed_slow + 20,1,1,0); 
    backwardTime(speed_slow,320,0,0);
    forwardAlign(80 , 1);
    forwardTime(speed_slow - 10,710,1,1);
    forwardAlign(80 , 1);
    backwardAlign(80 , 1);

    // exit black hold
    backwardTime(speed_slow,700,0,0);
    // forwardAlign(80 , 1);
    backwardTill(speed_slow , 1 , 1 ,0);
    forwardTime(speed_slow , 200 , 0 , 0);
    rotate(-90 , 0);
    backwardAlign(80 , 1);

    // ไปหาเขียว
    forwardTill(speed_slow +20,1,1,0); 
    backwardTime(speed_slow,320,0,0);
    Poy();

    Thailand();



}   

void Run2()
{
    
    // forwardTime(0 , 2500 , 1 , 0);
    FD2(40 , 40);
    delay(2000);
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
    imu.Start();
    beep();
    // Sound::UmaPyou();
    // backwardAlign(70 , 1);
    // Thailand();
    // toggleServoOn();
    // delay(200);
    // Thailand_back();
    // rotate(90);
    // Poy();
    forwardTill(speed_slow,1,1,0);
    backwardTime(speed_slow,300,0,0);
    backwardAlign(60 , 3);

    // forwardTill(60 , 1 , 1 , 0);
    // FD2(40 , 40);
    // delay(500);
    // AO();

}
