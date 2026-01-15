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
    PIDRotate.SetOutputLimits(-180,180);
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
    Front.__Track = 550;
    Back.__Track = 550;
    motors.setSpeedRange(100,250);
    motors.setRatio({1,1.1},{1.0,1.0});
}   

void loop()
{
    BasicMenu.show();
}

void Run1(){
    imu.Start();
    beep();
    // First Turn
    forwardTill(speed_slow,0,1,1);  
    forwardTime(speed_fast,150,0,0);
    forwardTill(speed_slow - 30,1,0,1);
    
    backwardTime(speed_slow,300,0,0);
    rotate(-90);
    // backwardTill(75,1,1);
    backwardAlign(70,1);

    forwardTill(speed_slow - 30,1,1,1);
    backwardTime(speed_slow,300,0,0);
    rotate(90);
    // backwardTill(75,1,1);
    backwardAlign(70,1);
    

    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,350,0,0);
    rotate(90);

    // เลี้ยวไปหาเหลือง
    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,350,0,0);
    rotate(-90);
    // backwardTill(75,1,1);
    backwardAlign(70,1);

    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,350,0,0);
    rotate(-90);
    // backwardTill(75,1,1);
    backwardAlign(70,1);

    // Poy เหลือง
    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,280,0,0);
    Poy();
    backwardTime(speed_slow,350,0,0);
    backwardAlign(70,1);
    forwardTime(speed_slow , 200 , 0 , 0);
    rotate(-90);

    forwardTime(speed_slow , 250 , 0 , 0);
    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,320,0,0);
    rotate(90);
    // backwardTill(75,1,1);
    backwardAlign(70,1);

    // backwardAlign(60 , 2);
    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,350,0,0);
    rotate(-90);
    // backwardTill(75,1,1);
    // backwardAlign(60,1);
    // backwardAlign(60 , 2);
    // forwardTill(speed_slow,1,1,1);
    // forwardTime(speed_fast,300,0,0);

    // ตะเกียบ
    forwardTime(60,1820,0,0);
    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,370,0,0);
    rotate(-90);

    // forwardTill(speed_slow,1,1,1);
    forwardTime(speed_slow,450,0,0);
    backwardTime(speed_slow,550,0,0);
    backwardTill(100,1,0,1);
    // backwardAlign(70,1);
    forwardTime(speed_fast,210,0,0);
    rotate(-90);
    backwardAlign(70,1);
    forwardTime(speed_slow,120,0,0);

    // // ออกตะเกียบ
    forwardTime(80,1500,0,0);
    forwardTime(speed_slow,120,0,0);

    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,400,0,0);
    rotate(-90);
    backwardAlign(70,1);

    forwardTill(speed_slow,1,1,1);
    backwardTime(speed_slow,350,0,0);
    rotate(-90);
    backwardAlign(70,1);
    delay(100);
    forwardTime(speed_fast,800,0,0);

    // Green
    forwardTill(speed_slow,1,1,1);
    backwardTime(100,200,0,0);
    Poy();

    backwardTime(100,450,0,0);
    rotate(90);
    backwardAlign(70,1);

    forwardTill(speed_slow - 20,1,1,1);
    backwardTime(100,250,0,0);
    rotate(90);
    backwardAlign(70,1);

    forwardTill(140,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90);
    backwardAlign(70,1);

    forwardTill(speed_fast - 40,1,1,0);
    backwardTime(speed_slow,350,0,0);
    rotate(-90);
    backwardAlign(70,1);
    // checkpoint 2
    forwardTime(100,640,0,0);
    backwardTime(100,10,0,0);
    backwardTill(100,1,1,0);
    forwardTime(100,270,0,0);
    rotate(-90); 
    backwardAlign(70,1);
    

    forwardTime(speed_slow,500,0,0);
    rotate(90); 
    backwardAlign(70,1);
    forwardTill(speed_slow,1,1,0);
    // Red
    backwardTime(100,250,0,0);
    Poy();

    backwardTime(speed_slow,250,0,0);
    backwardTill(speed_slow,1,1,0);
    forwardTime(speed_slow,250,0,0);
    rotate(-90);

    forwardTime(speed_slow,380,1,0);
    rotate(90);
    backwardAlign(70 , 1);

    //ขึ้นสะพาน
    forwardTill(speed_slow - 20,1,1,0);
    backwardTime(120,400,0,0);
    rotate(90);
    backwardAlign(70,1);

    forwardTill(speed_slow,1,1,0);
    backwardTime(120,350,0,0);
    rotate(-90);
    backwardAlign(70,1);

    forwardTill(speed_slow,1,1,0);
    backwardTime(120,350,0,0);
    rotate(-90);
    backwardAlign(70,1);

    forwardTill(speed_fast,1,1,0);
    backwardTime(120,350,0,0);
    Poy();
    Thailand();

}   

void Run2()
{
    
    FD2(52 , 50);
    delay(1000);
    AO();

}

void Poy()
{
    toggleServoOn();
    delay(200);
    toggleServoOff();

}

void Run3(){
    // Sound::UmaPyou();
    // backwardAlign(70 , 1);
    // Thailand();
    // delay(200);
    // Thailand_back();
    rotate(90);

}
