#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้

int Rotate_fix = 90;

int32_t speed_slow = 120;
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
    Front.__Track = 825;
    Back.__Track = 825;
    motors.setSpeedRange(100,250);
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
    forwardTill(speed_slow,0,1,1);  
    forwardTime(speed_fast,150,0,0);
    forwardTill(speed_slow ,1,0,1);
    
    backwardTime(speed_slow,300,0,0);
    rotate(90);
    backwardAlign(70,1);

    forwardTime(speed_slow - 30,1000,0,0); 
    backwardTime(speed_slow,150,0,0);
    rotate(85);
    backwardAlign(70,1);

    // ตะเกียบ
    forwardTime(60,2000,0,0);
    forwardTill(speed_slow,1,1,0);  
    backwardTime(speed_slow,390,0,0);
    rotate(-90);
    backwardAlign(70,1);

    // Red
    forwardTill(speed_slow + 20,1,1,0); 
    backwardTime(speed_slow,250,0,0);
    Poy();

    backwardTime(speed_slow,390,0,0);
    rotate(-90);
    backwardAlign(70,1);

    // ขึ้นสะพาน
    forwardTill(speed_slow + 20,1,1,0); 
    backwardTime(speed_slow,320,0,0);
    rotate(90);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,370,0,0);
    rotate(90);
    backwardAlign(70,1);

    forwardTill(speed_slow,1,1,0);  
    backwardTime(speed_slow,300,0,0);
    forwardAlign(70 , 1);

    //backhold
    forwardTime(speed_slow,700,1,1);
    forwardAlign(70 , 1);
    backwardTime(speed_slow,300,0,0);
    rotate(180);
    backwardAlign(70 , 1);

    // exit blackhold
    forwardAlign(70 , 1);
    forwardTime(speed_slow,980,1,1);
    // forwardTill(speed_slow,0,1,1);
    backwardTime(speed_slow,240,0,0);
    rotate(-90);
    backwardAlign(70 , 1);

    // ไปหาเขียว
    forwardTime(speed_slow,880,1,1);
    rotate(-90);
    backwardAlign(70 , 1);

    // เขียว
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,340,0,0);
    Poy();
    backwardTime(speed_slow,350,0,0);
    backwardAlign(70 , 1);

    forwardTime(speed_slow,220,1,1);
    rotate(88);

    // forwardTill(speed_slow - 30,1,1,0); 
    // backwardTime(speed_slow ,300,0,0);
    forwardAlign(70 , 1);
    backwardTime(speed_slow,250,0,0);
    rotate(88);

    backwardTill(speed_slow,1,1,0); 
    forwardTime(speed_slow - 20, 250 , 0 , 0);
    backwardAlign(70 , 1);

    forwardTime(speed_slow , 880 , 0 , 0 );
    rotate(90);
    backwardAlign(70 , 1);

    // // น้ำเงิน
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,250,0,0);
    Poy();
    backwardTill(speed_slow , 1 , 1 , 0);

    forwardTime(speed_slow , 250 , 0 , 0);
    rotate(-83);

    // เข้าวงกต
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    // yellow
    forwardTill(speed_slow + 10,1,1,0); 
    backwardTime(speed_slow,380,0,0);
    Poy();
    Thailand();


}   

void Run2()
{
    
    // forwardTime(60 , 2500 , 1 , 0);
    // FD2(30 , 30);
    // delay(1000);
    // AO();

    // backwardAlign(70 , 1);

    backwardAlign(70 , 1);

    forwardTime(speed_slow , 900 , 0 , 0 );
    rotate(90);
    backwardAlign(70 , 1);

    // // น้ำเงิน
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,250,0,0);
    Poy();
    backwardTill(speed_slow , 1 , 1 , 0);

    forwardTime(speed_slow , 220 , 0 , 0);
    rotate(-88);

    // เข้าวงกต
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    // yellow
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,380,0,0);
    Poy();
    Thailand();

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
    // toggleServoOn();
    // delay(200);
    // Thailand_back();
    // rotate(90);
    // Poy();

    // forwardTill(60 , 1 , 1 , 0);

    backwardAlign(70 , 1);

    // exit blackhold
    forwardAlign(70 , 1);
    forwardTime(speed_slow,650,1,1);
    forwardTill(speed_slow,0,1,1);
    backwardTime(speed_slow,230,0,0);
    rotate(-90);
    backwardAlign(70 , 1);

    // ไปหาเขียว
    forwardTime(speed_slow,930,1,1);
    rotate(-90);
    backwardAlign(70 , 1);

    // เขียว
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,340,0,0);
    Poy();
    backwardTime(speed_slow,350,0,0);
    backwardAlign(70 , 1);

    forwardTime(speed_slow,220,1,1);
    rotate(90);

    // forwardTill(speed_slow - 30,1,1,0); 
    // backwardTime(speed_slow ,300,0,0);
    forwardAlign(70 , 1);
    backwardTime(speed_slow,250,0,0);
    rotate(86);

    backwardTill(speed_slow,1,1,0); 
    forwardTime(speed_slow - 20, 250 , 0 , 0);
    backwardAlign(70 , 1);

    forwardTime(speed_slow , 900 , 0 , 0 );
    rotate(90);
    backwardAlign(70 , 1);

    // // น้ำเงิน
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,250,0,0);
    Poy();
    backwardTill(speed_slow , 1 , 1 , 0);

    forwardTime(speed_slow , 220 , 0 , 0);
    rotate(-88);

    // เข้าวงกต
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(70 , 1);

    // yellow
    forwardTill(speed_slow + 10,1,1,0); 
    backwardTime(speed_slow,380,0,0);
    Poy();
    Thailand();

}
