#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้
int Base_Speed = 160;
int Slow = 70; 
int Fast = 200;

void Run1();
void Run2();
void Run3();

void setup(){
    beep();
    POP32_INIT();   
    PIDRotate.gains = newRotateGains;
    //servo(servoPIN,startAngle);
    delay(500);
    //servo(servoPIN,-1);
    imu.Start();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[1].callback = Run2; // Run 2
    BasicMenu.buttons[2].callback = Run3; // Run 3
    Front.__Track = 700;
    Back.__Track = 700;
    motors.setSpeedRange(85,250);
    motors.setRatio({1,1},{1.0,1.0});
}   

void loop(){
    BasicMenu.show();
}

 void Run1(){
    
    imu.Start();
    beep();

    forwardTill(140,0,0);
    forwardTime(200,550,0);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);
    
    
    rotate(-90); // +-5

    forwardTime(200,400,0);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);
    rotate(-90);

    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);

    rotate(-90);

    backwardTill(140,1,0);
    backwardAlign(Slow,1);
    FD2(40,40); delay(300);
    forwardTill(120,1,0);
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);

    rotate(90);

    forwardTime(200,400,0);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);

    Poy(); delay(300); AO(); delay(300); //Green 1

    BK2(40,40); delay(900); //ก่อนขึ้นสะพาน

    rotate(90);
    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(200,1200,0);
    AO(); delay(10);
    forwardTime(160,1500,0);

    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);

    rotate(-90);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);

    rotate(-90);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    Poy(); delay(300); AO(); delay(300); //Green 2

    backwardTill(140,1,0);
    backwardAlign(Slow,1);
    FD2(60,60); delay(300);

    rotate(-90);

    forwardTime(200,450,0);
    forwardTill(140,1,0); //ปรับแสงแรง
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);

    rotate(90);

    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    Poy(); delay(300); AO(); delay(300); //Green 3

    backwardTill(140,1,0);
    backwardAlign(Slow,1);
    FD2(40,40); delay(300);

    rotate(90); 

    FD2(60,60);//ก่อนตะเกียบกละบ
    delay(800);
    AO(); delay(100);

    rotate(-90);
    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(100,2050,1); // ข้ามตะเกียบกลับ

    rotate(90);

    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);

    rotate(-90);

    backwardTill(160,1,0);
    backwardAlign(Slow,1);

    forwardTill(160,1,0);
    forwardAlign(Slow,1);

    forwardTill(140,0,0); // จนเจอขาว
    forwardTime(140,500,0); // CheckPoint 1
    backwardTime(140,1500,0);

    backwardTill(120,1,0);
    backwardAlign(Slow,1);
    FD2(40,40);
    delay(300);

    rotate(-90);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    BK2(40,40); delay(300);
    rotate(90);

    forwardTime(200,550,0);
    forwardTill(140,1,0); // check  2

    backwardTime(200,550,0);
    backwardTill(120,1,0);
    backwardAlign(70,2);
    FD2(40,40); delay(150);

    rotate(90);

    forwardTime(100,800,1);

    rotate(-90);
    forwardTime(200,550,0);
    forwardTill(140,1,0);
    
    

    Poy(); delay(300); AO(); delay(300); //Green4

    backwardTime(200,550,0);
    backwardTill(120,1,0);
    backwardAlign(70,2);
    FD2(40,40); delay(300);

    rotate(90);
    backwardTill(120,1,0);
    backwardAlign(70,2);

    forwardTime(200,700,1);
    AO(); delay(100);

    rotate(-90); // ก่อนขึ้นสะพานกลับ

    forwardTime(160,1500,1);
    
    forwardTill(140,1,0);
    
    
    BK2(40,40); delay(300);

    rotate(-90);

    forwardTill(120,1,0);
    
    
    BK2(40,40); delay(300);

    rotate(-90);

    forwardTill(140,1,0);
    
    
    BK2(40,40); delay(300);

    rotate(90);

    forwardTill(140,1,0);
    
    
    BK2(40,40); delay(300);

    rotate(90);

    forwardTime(200,550,0);
    forwardTill(140,1,0);
    
    
    BK2(40,40); delay(300);

    rotate(90);

    forwardTime(200,550,0);
    forwardTill(140,1,0);
    
    

    FD2(40,40); delay(600);

    AO(); delay(100000);


 }

void Run2(){
    imu.Start();
    beep();
    forwardTime(200,1200,1);
    forwardTime(100,1500,1);
    forwardTill(140,1,0);

    AO(); delay(10000);
    
}

void Run3() 
{   
    // forwardTime(200,500);
    // forwardTime(200,700,1);
    // forwardTill(160,1,1);
    // rotate(90);
    // rotate(-90);
    // forwardTime(100,1600);
    // forwardTime(200,600);
    // Poy(); // เทสปล่อย
    AO(); delay(1000);
    forwardTime(200,1500,0);
    
    AO(); delay(10000);
    /*
    forwardTime(100,1400);
    forwardTime(180,500);
    forwardTill(180,1);
    forwardAlign(100,2);
    AO(); delay(10000);
    */
}