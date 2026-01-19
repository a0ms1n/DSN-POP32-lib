#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"
#include "Music.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้

int Rotate_fix = 90;

int32_t speed_slow = 130;
int32_t speed_fast = 180;

void Run1();
void Run2();
void Run3();
void Nin();
void Ninja2();
void Ninja3();

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
    // BasicMenu.buttons[4].callback = Run5;
    BasicMenu.buttons.push_back({"Nin",Nin});
    BasicMenu.buttons.push_back({"Ninja2",Ninja2});
    BasicMenu.buttons.push_back({"Ninja3",Ninja3});
    Front.__Track = 820;
    Back.__Track = 820;
    motors.setSpeedRange(130,340);
    motors.setRatio({1.0,1.1},{1.0, 1.0});
}   

void loop()
{
    BasicMenu.show();
}

void Run1(){
    imu.Start();
    beep();
    // // First Turn
    // forwardTill(speed_slow,0,0,0);  
    // // forwardTime(speed_slow,200);
    
    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,250,0,0);
    // rotate(-90);
    // backwardAlign(80,1);
    // delay(300);

    // forwardTime(speed_fast, 550);
    // forwardAlign(80 , 3);
    // backwardTime(speed_slow,200,1,0);
    // rotate(-90);

    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,250,0,0);
    // rotate(-90);
    // backwardAlign(80,1);

    // // Check point 1
    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,250,0,0);
    // backwardTill(speed_slow,1,1,0);
    // forwardTime(speed_slow, 180 , 0 , 0);
    // rotate(-90 , 0);
    // backwardAlign(80,1);

    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,250,0,0);
    // rotate(90);
    // backwardTime(speed_slow,250,0,0);

    // forwardTill(speed_slow ,1,1,0);
    // backwardTime(speed_slow,250,0,0);
    // rotate(-90);
    // backwardAlign(80,1);

    // forwardTime(speed_fast, 400);
    // rotate(-90);
    // backwardAlign(80,1);

    // // green
    // forwardTill(speed_slow,1,1,0); 
    // Poy();
    // backwardAlign(80 , 1);
    // forwardTime(speed_slow, 140 , 0 , 0);
    // rotate(90);

    // forwardAlign(80 , 1);
    // backwardTime(speed_slow,270,0,0);
    // rotate(90);
    // forwardTime(speed_fast, 270);
    // rotate(90);
    // forwardAlign(80 , 3);

    // Red
    forwardAlign(80 , 3);
    delay(300);
    forwardTime(speed_slow - 30 , 770 , 1 , 0);
    Poy();
    backwardTime(speed_slow - 30,1050,0,0);
    forwardAlign(80 , 3);
    delay(300);
    backwardTime(speed_slow - 30,350,0,0);
    rotate(90);
    backwardAlign(80 , 1);
    delay(300);

    // ไปสะพาน 
    forwardTime(speed_fast , 750 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 160 , 0 , 0);

    rotate(-90);
    backwardAlign(80 , 1);
    delay(300);
    forwardTime(speed_fast , 760 );
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);
    backwardTime(speed_fast - 20 , 750,0);
    backwardAlign(80 , 1);
    delay(300);

    forwardTime(speed_slow , 220 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);
    delay(300);

    // ไปหา blue
    forwardTime(speed_slow , 580 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);
    delay(300);

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
    backwardTime(speed_slow,250,0,0);
    rotate(-87);
    backwardAlign(80 , 1);
    delay(300);

    forwardTime(speed_fast , 800 ,1);
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);
    delay(300);

    forwardTime(speed_fast , 600 , 1);
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);
    delay(300);

    forwardTime(speed_fast , 750 , 1);
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTill(speed_slow,1,1,0); 
    backwardTime(speed_slow,360,0,0);
    rotate(90);
    backwardAlign(80 , 1);

    // ตะเกียบ
    forwardTime(60, 2200 , 1 , 0);
    forwardTill(speed_slow,1,1,0); 

    backwardTime(speed_slow, 420 , 0 , 0);
    Poy();
    Thailand();




}   

void Run2()
{
    
    // forwardTime(speed_slow , 2500 , 1 , 0);
    // Poy();
    // imu.Start();
    // forwardTill(speed_slow ,1,1,0);
    // forwardAlign(80 , 1);
    backwardAlign(80 , 1);

}

void Poy()
{
    toggleServoOn();
    delay(200);
    toggleServoOff();

}

void Run3(){


}

void Run4()
{
    imu.Start();
    backwardAlign(80 , 1);
    // forwardTime(speed_fast , 800 );
    // forwardAlign(80 , 3);
    // backwardTime(speed_slow , 200 , 0 , 0);

}

void Nin() 
{
    // First Turn
    forwardTime(speed_fast, 350 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 300 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 450 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 260 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 370 , 1 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    // Green
    forwardTill(speed_slow,1,1,0); 
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow, 140 , 1 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast + 20, 550 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 240 , 0 , 0);
    rotate(-90);
   backwardAlign(80 , 1);

    // ตะเกียบ
   forwardTime(60, 2500 , 1 , 0);

    // Check point 1
    forwardTime(speed_fast + 20, 800 , 1 , 0);
    forwardAlign(80 , 3);
    backwardTime(speed_fast, 500 , 1 , 0);
    backwardTime(speed_fast - 40, 560 , 0 , 0);
    rotate(-90);

    forwardTime(speed_fast, 300 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 230 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    // สะพาน
    forwardTime(speed_fast, 420 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 300 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    // ออกสะพาน
    forwardTime(speed_fast, 450 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);

    forwardTime(speed_fast, 350 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 300 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    // Red
    forwardTill(speed_slow , 1 , 1 , 0);
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow , 200 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    // blue
    forwardTime(speed_fast + 20, 820 , 1 , 0);
    forwardAlign(80 , 3);
    Poy();
    backwardTime(speed_fast , 560 , 1 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 500 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);
    backwardTime(speed_slow , 300 , 0 , 0);

    forwardTime(speed_fast, 400 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(-90 , 0);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 400 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 170 , 0 , 0);
    rotate(90 , 0);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 400 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(90 , 0);
    backwardAlign(80 , 1);

    // black hold
    forwardTime(speed_fast, 700 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(90 , 0);
    backwardAlign(80 , 1);

    forwardTill(speed_slow , 1 , 1 , 0);
    backwardTime(speed_slow, 350 , 0 , 0);
    Poy();

    Thailand();


}

void Ninja2()
{

    // First Turn
    forwardTime(speed_fast, 350 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 300 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 450 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 600 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 230 , 0 , 0);
    rotate(-90);
   backwardAlign(80 , 1);

    // ตะเกียบ
   forwardTime(60, 2500 , 1 , 0);

    // Check point 1
    forwardTime(speed_fast, 850 , 1 , 0);
    forwardAlign(80 , 3);
    backwardTime(speed_fast, 500 , 1 , 0);
    backwardTime(speed_fast - 40, 520 , 0 , 0);
    rotate(-90);

    forwardTime(speed_fast, 300 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 230 , 0 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    // สะพาน
    forwardTime(speed_fast, 350 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 300 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    // ออกสะพาน
    forwardTime(speed_fast, 350 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);

    forwardTime(speed_fast, 350 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 300 , 0 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    // Red
    forwardTill(speed_slow , 1 , 1 , 0);
    Poy();
    backwardAlign(80 , 1);
    forwardTime(speed_slow , 200 , 0);
    rotate(-90);
    backwardAlign(80 , 1);

    // blue
    forwardTime(speed_fast + 20, 820 , 1 , 0);
    forwardAlign(80 , 3);
    Poy();
    backwardTime(speed_fast , 580 , 1 , 0);
    rotate(90);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 500 , 1 , 0);
    forwardAlign(80 , 1);
    backwardTime(speed_slow , 250 , 0 , 0);
    rotate(-90);
    backwardTime(speed_slow , 300 , 0 , 0);

    forwardTime(speed_fast, 400 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(-90 , 0);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 400 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 170 , 0 , 0);
    rotate(90 , 0);
    backwardAlign(80 , 1);

    forwardTime(speed_fast, 400 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(90 , 0);
    backwardAlign(80 , 1);

    // black hold
    forwardTime(speed_fast, 700 , 1 , 0);
    // forwardAlign(80 , 1);
    backwardTime(speed_slow , 200 , 0 , 0);
    rotate(90 , 0);
    backwardAlign(80 , 1);

    forwardTill(speed_slow , 1 , 1 , 0);
    backwardTime(speed_slow, 350 , 0 , 0);
    Poy();

    Thailand();

}


void Forward_Fake(int Rotate_Right = -90 , int Rotate_Left = 90 , bool PoyColor = false)
{
    if(PoyColor == false)
    {
        forwardTime(speed_fast , 300 , 1 , 0);
        rotate(Rotate_Right);
        forwardAlign(80 , 3);
        backwardTime(speed_slow , 220 , 0 , 0);
        rotate(Rotate_Left);
        delay(100); 
    }else{
        forwardTime(speed_fast , 300 , 1 , 0);
        rotate(Rotate_Right);
        forwardAlign(80 , 3);
        backwardTime(speed_slow , 200 , 0 , 0);
        Poy();
        backwardAlign(80 , 1);
        forwardTime(speed_slow , 150 , 1 , 0);
    }
    

}

void Forward_Fake2(int Rotate_Right = -90 , int Rotate_Left = 90 , int Rotate_back = 90)
{

    forwardTime(speed_fast , 300 , 1 , 0);
    rotate(Rotate_Right);
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 220 , 0 , 0);
    rotate(Rotate_Left);
    forwardAlign(80 , 3);
    backwardTime(speed_slow , 220 , 0 , 0);
    rotate(Rotate_back);
    backwardAlign(80 , 1);
    forwardTime(speed_fast , 150 , 1 , 0);

}

void Ninja3()
{
        // First Turn
    Forward_Fake();
    Forward_Fake2();
    Forward_Fake2();
    Forward_Fake();
    Forward_Fake2(90 , -90 , -90);
    Forward_Fake(-90 , 90 , 1);
    rotate(90);
    Forward_Fake2(90 , -90 , -90);
    forwardTime(60, 2500 , 1 , 0);
    Forward_Fake(90 , -90);
    Forward_Fake(90 , -90);
    Forward_Fake2(-90 , 90 , 90);
    Forward_Fake();
    Forward_Fake();
    Forward_Fake();
    Forward_Fake();

}
