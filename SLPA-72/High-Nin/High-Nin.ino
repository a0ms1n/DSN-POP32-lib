#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"
#include "Music.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้

int Rotate_fix = 90;

int32_t speed_slow = 130;
int32_t speed_fast = 190;

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
    //PIDRotate.gains = newStraightGains;
    imu.Start();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[1].callback = Run2; // Run 2
    BasicMenu.buttons[2].callback = Run3; // Run 3
    BasicMenu.buttons[3].callback = Run4; 
    BasicMenu.buttons[4].callback = Run5;
    Front.__Track = 750;
    Back.__Track = 750;
    motors.setSpeedRange(130,340);
    motors.setRatio({1.0,1.0},{1.0,1.0});
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
    // forwardTime(speed_slow,200);
    
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90);
    backwardAlign(80,1);
    delay(300);

    forwardTime(speed_fast, 550);
    forwardAlign(80 , 3);
    rotate(-90);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90 , 0);
    backwardAlign(80,1);

    // Check point 1
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    backwardTill(speed_slow,1,1,0);
    forwardTime(speed_slow, 180 , 0 , 0);
    rotate(-90 , 0);
    backwardAlign(80,1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(90);
    backwardTime(speed_slow,320,0,0);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90);
    backwardAlign(80,1);

    forwardTime(speed_fast, 400);
    rotate(-90);
    backwardAlign(80,1);

    // green
    forwardTill(speed_slow,1,1,0); 
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow, 140 , 0 , 0);
    rotate(90);

    forwardAlign(80 , 1);
    backwardTime(speed_slow,270,0,0);
    rotate(90);
    forwardTime(speed_fast, 270);
    rotate(90);
    // forwardAlign(80 , 3);

    // Red
    forwardAlign(80 , 3);
    delay(300);
    forwardTime(speed_slow - 30 , 750 , 0 , 0);
    Poy();
    backwardTime(speed_slow - 30,1050,0,0);
    forwardAlign(80 , 3);
    delay(300);
    backwardTime(speed_slow - 30,350,0,0);
    rotate(90);
    backwardAlign(80 , 3, 200);
    delay(100);

    // ไปสะพาน 
    forwardTime(speed_fast , 750 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);

    rotate(-90);
    backwardAlign(80 , 1);
    forwardTime(speed_fast , 760 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);
    backwardTime(speed_fast - 20 , 750);
    backwardAlign(80 , 1);

    forwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 3 , 200);

    // ไปหา blue
    forwardTime(speed_slow , 580 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,350,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // blue
    forwardTill(speed_slow,1,1,0); 
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow, 160 , 0 , 0);
    rotate(90);

    backwardAlign(80 , 1);
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-87);
    backwardAlign(80 , 3 , 200);

    forwardTime(speed_fast , 800 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast , 600 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    backwardAlign(80 , 1);
    forwardTime(speed_fast , 750 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,400,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // ตะเกียบ
    forwardTime(60, 2200 , 0 , 0);
    forwardTill(speed_slow,1,1,0); 

    backwardTime(speed_slow, 420 , 0 , 0);
    Poy();
    Thailand();




}   

void Run2()
{
    
    // forwardTime(speed_slow , 2500 , 1 , 0);
    // Poy();

    backwardAlign(80 , 1);

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
    forwardTill(speed_slow,0,0,0);  
    // forwardTime(speed_slow,200);
    
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90);
    backwardAlign(80,1);
    delay(300);

    forwardTime(speed_fast, 670);
    rotate(-90);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90 , 0);
    backwardAlign(80,1);

    // Check point 1
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    backwardTill(speed_slow,1,1,0);
    forwardTime(speed_slow, 180 , 0 , 0);
    rotate(-90 , 0);
    backwardAlign(80,1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(90);
    backwardTime(speed_slow,320,0,0);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90);
    backwardAlign(80,1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);

    forwardAlign(80 , 1);
    backwardTime(speed_slow,270,0,0);
    rotate(90);
    forwardTime(speed_fast, 270);
    rotate(90);
    // forwardAlign(80 , 3);

    // Red
    forwardAlign(80 , 3);
    delay(300);
    forwardTime(speed_slow - 30 , 750 , 0 , 0);
    Poy();
    backwardTime(speed_slow - 30,1050,0,0);
    forwardAlign(80 , 3);
    delay(300);
    backwardTime(speed_slow - 30,350,0,0);
    rotate(90);
    backwardAlign(80 , 3, 200);
    delay(100);

    // ไปสะพาน
    // forwardTime(speed_fast,400,0,0); 
    forwardTime(speed_fast , 800 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);

    rotate(-90);
    backwardAlign(80 , 1);
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,270,0,0);
    forwardAlign(80 , 2);
    backwardTill(speed_slow , 1 , 1 , 0);

    forwardTime(speed_slow , 300 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 3 , 200);

    // ไปหา blue
    forwardTime(speed_slow , 580 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,350,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // blue
    forwardTill(speed_slow,1,1,0); 
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow, 160 , 0 , 0);
    rotate(90);

    backwardAlign(80 , 1);
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-87);
    backwardAlign(80 , 3 , 200);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,300,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,250,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    backwardAlign(80 , 1);
    forwardTime(speed_fast , 800 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,380,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // ตะเกียบ
    forwardTime(60, 2200 , 0 , 0);
    forwardTill(speed_slow,1,1,0); 

    backwardTime(speed_slow, 420 , 0 , 0);
    Poy();
    Thailand();

}

void Run4()
{
    imu.Start();
    // backwardAlign(80 , 1);
    // forwardTime(speed_fast , 800 );
    // forwardAlign(80 , 3);
    // backwardTime(speed_slow , 200 , 0 , 0);
    forwardTill(speed_slow,0,0,0);  
    // forwardTime(speed_slow,200);
    
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90);
    backwardAlign(80,1);
    delay(300);

    forwardTime(speed_fast, 670);
    rotate(-90);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90 , 0);
    backwardAlign(80,1);

    // Check point 1
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    backwardTill(speed_slow,1,1,0);
    forwardTime(speed_slow, 180 , 0 , 0);
    rotate(-90 , 0);
    backwardAlign(80,1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(90);
    backwardTime(speed_slow,320,0,0);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-90);
    backwardAlign(80,1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);

    forwardAlign(80 , 1);
    backwardTime(speed_slow,270,0,0);
    rotate(90);
    forwardTime(speed_fast, 270);
    rotate(-90);
    backwardAlign(80 , 1);
    forwardTime(speed_slow , 230 , 0 , 0);

    // ไปสะพาน
    // forwardTime(speed_fast,400,0,0); 
    forwardTime(speed_fast , 800 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);

    rotate(-90);
    backwardAlign(80 , 1);
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,270,0,0);
    forwardAlign(80 , 2);
    backwardTill(speed_slow , 1 , 1 , 0);

    forwardTime(speed_slow , 300 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 3 , 200);

    // ไปหา blue
    forwardTime(speed_slow , 580 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,350,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // blue
    forwardTill(speed_slow,1,1,0); 
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow, 160 , 0 , 0);
    rotate(90);

    backwardAlign(80 , 1);
    forwardTill(speed_slow ,1,1,0);
    backwardTime(speed_slow,320,0,0);
    rotate(-87);
    backwardAlign(80 , 3 , 200);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,300,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,250,0,0);
    rotate(-90);
    backwardAlign(80 , 1);

    backwardAlign(80 , 1);
    forwardTime(speed_fast , 800 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,380,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // ตะเกียบ
    forwardTime(60, 2200 , 0 , 0);
    forwardTill(speed_slow,1,1,0); 

    backwardTime(speed_slow, 420 , 0 , 0);
    Poy();
    Thailand();
}

void Run5()
{

}