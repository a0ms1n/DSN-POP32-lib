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
    BasicMenu.buttons.push_back({
        "Sensor Calibrate",SensorCalibrate
    });
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
    Front.__Track = 700;
    Back.__Track = 700;
    motors.setSpeedRange(130,250);
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
    backwardAlign(80,1);

    forwardTime(speed_slow - 30,1000,0,0); 
    backwardTime(speed_slow,150,0,0);
    rotate(90);
    backwardAlign(80,1);

    // ตะเกียบ
    forwardTime(90,1800,0,0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow,280,0,0);
    rotate(-85);
    backwardAlign(80,1);

    // Red
    forwardTill(speed_slow + 20,1,1,0); 
    backwardTime(speed_slow,250,0,0);
    Poy();

    backwardTime(speed_slow,360,0,0);
    rotate(-90);
    backwardAlign(80,1);

    // ขึ้นสะพาน
    forwardTill(speed_slow + 10,1,1,0); 
    backwardTime(speed_slow,300,0,0);
    rotate(90);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,320,0,0);
    rotate(90);
    backwardAlign(80,1);

    forwardTill(speed_slow,1,1,0);  
    backwardTime(speed_slow,310,0,0);
    forwardAlign(80 , 1);

    //backhold
    forwardTime(speed_slow - 10,710,1,1);
    forwardAlign(80 , 1);
    backwardTime(speed_slow,300,0,0);
    rotate(180);
    backwardAlign(80 , 1);

    // exit blackhold
    forwardAlign(80 , 1);
    forwardTime(speed_slow,880,1,1);
    // forwardTill(speed_slow,0,1,1);
    // backwardTime(speed_slow,240,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    // ไปหาเขียว
    forwardTime(speed_slow,860,1,1);
    rotate(-90);
    backwardAlign(80 , 1);

    // เขียว
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,300,0,0);
    Poy();
    backwardTime(speed_slow,250,0,0);
    backwardAlign(80 , 1);

    forwardTime(speed_slow,220,1,1);
    rotate(89);

    // forwardTill(speed_slow - 30,1,1,0); 
    // backwardTime(speed_slow ,300,0,0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow - 20,260,0,0);
    rotate(90);

    backwardTill(speed_slow,1,1,0); 
    forwardTime(speed_slow - 20, 260 , 0 , 0);
    backwardAlign(80 , 1);

    forwardTime(speed_slow , 860 , 0 , 0 );
    rotate(90);
    backwardAlign(80 , 1);

    // // น้ำเงิน
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,250,0,0);
    Poy();
    backwardTill(speed_slow , 1 , 1 , 0);

    forwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);

    // เข้าวงกต
    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,330,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // yellow
    forwardTill(speed_slow + 20,1,1,0); 
    backwardTime(speed_slow,430,0,0);
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
    // backwardAlign(70 , 1);
    // Thailand();
    // toggleServoOn();
    // delay(200);
    // Thailand_back();
    // rotate(90);
    // Poy();

    // forwardTill(60 , 1 , 1 , 0);
    // FD2(40 , 40);
    // delay(500);
    // AO();

}
