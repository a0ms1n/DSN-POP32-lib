#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"
#include "Music.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้
int Base_Speed = 160;
int Slow = 80; 
int Fast = 200;

void Run1();
void Run2();
void Run3();

void setup(){
    BasicMenu.buttons.push_back({

    });

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
    Back.__Track = 800;
    motors.setSpeedRange(90,250);
    motors.setRatio({1,1},{1.0,1.04});
    
}   

void loop(){
    BasicMenu.show();
}

 void Run1(){
    
    imu.Start();
    beep();

    

    forwardTill(140,1,0); // ขึ้นสะพานแรก
    forwardTime(200,550,0);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    backwardTime(160,200,1,0);


    rotate(90,0);

    backwardTill(140,1,0);
    backwardAlign(Slow,1);
    forwardTime(200,700,0);

    rotate(-90,0);

    forwardTill(160,1,1);

    Poy(); delay(300); AO(); delay(300); //Green 1

    backwardTill(140,1,0);
    backwardAlign(Slow,1);
    forwardTime(160,200,0);

    rotate(90,0);

    forwardTime(160,300,1,0);
    forwardTill(140,1,0);
    forwardAlign(80,2);
    BK2(45,40); delay(200);    
    rotate(-90,0);
    backwardTill(120,1,0);
    backwardAlign(80,3);

    forwardTime(200,600,0);
    forwardTill(140,1,0);
    forwardAlign(80,2);
    BK2(45,40); delay(300);
    

    rotate(-90,0);
    FD2(45,40); delay(50);
    backwardTill(160,1,0);
    forwardTill(120,1,0);
    forwardAlign(Slow,2);
    BK2(45,40); delay(300);

    rotate(90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);

    forwardTime(200,700,0);
    forwardTill(120,1,0);
    forwardAlign(80,2);
    BK2(45,40); delay(300);


    rotate(-90,0);

    backwardTime(200,400,0);
    backwardTill(140,1,0);



    forwardTime(200,700,0);
    forwardTill(140,1,0);
    forwardAlign(80,2);

    Poy(); delay(300); AO(); delay(300);  //green 2

    backwardTime(200,500,0);


    rotate(-90,0);
    
    backwardTill(140,1,0);
    backwardAlign(80,1);

    forwardTime(200,500,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(300);

    rotate(90,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(300);

    rotate(90,0);
    backwardTill(140,1,0);
    backwardAlign(80,1);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(300);

    rotate(-90,0);
    backwardTill(140,1,0);
    backwardAlign(80,1);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(400);
    
    rotate(-90,0);
    FD2(45,40); delay(100);
    backwardTill(140,1,0);
    backwardAlign(80,2);
    FD2(45,40); delay(200);
    FD2(83,90); delay(400);
    forwardTill(120,1,0);


    Poy(); delay(300); AO(); delay(300);  // green 3

    backwardTime(200,400,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);
    forwardTime(120,200,0);
    rotate(-90,0);

    forwardTill(160,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);
    rotate(90,0);
   
    forwardTill(140,1,0);
    BK2(44,40); delay(200);

    rotate(-90);

    backwardTill(140,1,0);
    backwardAlign(80,2);

    forwardTime(200,500,1,0); // ปยอ
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(300);
    

    rotate(90,1); ///asdasdas
    forwardTime(200,500,1,0);
    forwardTill(140,1,0);
    forwardAlign(80,2);
    BK2(45,40); delay(300);
    

    rotate(90,1);
    forwardTime(200,500,1,0);

    
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,250,0);    //ขึ้นสะพาน
    

    rotate(-90,0);
    backwardTill(140,1,0);
    backwardAlign(80,3);

    forwardTime(200,500,0);
    
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,200,0);    //ลงสะพาน
    

    rotate(-90,0);
    forwardTime(200,600,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);
    

    rotate(-90,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(300);
    

    rotate(90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(300);
    

    rotate(90,1);
    //check 2
    forwardTime(100,1500,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,200,0);

    rotate(90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);

    FD2(83,90); delay(400);
    forwardTill(120,1,0);

    Poy(); delay(300); AO(); delay(300);  // green 4

    BK2(83,90); delay(550);
    backwardTill(140,1,0);
    backwardAlign(80,2);

    rotate(90,0);
    forwardTime(100,1500,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);
    

    rotate(-90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);
    forwardTill(120,1,0);
    forwardAlign(80,1);
    backwardTime(140,250,0);
    

    rotate(-90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);
    

    rotate(90,0); //ดำ
    forwardTime(200,500,0);
    forwardTill(140,1,0);
    forwardAlign(80,2);
    backwardTime(140,100,0);
    
    
    rotate(-90,0);
    forwardTime(140,600,0);

    rickroll();

    AO(); delay(100000);

    

 }

void Run2(){
    imu.Start();
    beep();
    
    backwardTill(140,1,0);
    backwardAlign(80,2);

    forwardTime(200,500,1,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(300);
    

    rotate(90,1); ///asdasdas
    forwardTime(200,500,1,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(200);
    

    rotate(90,1);
    forwardTime(200,500,1,0);

    
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);    //ขึ้นสะพาน
    

    rotate(-90,0);
    forwardTime(200,500,1,0);
    
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);    //ลงสะพาน
    

    rotate(-90,0);
    forwardTime(200,600,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,200,0);
    

    rotate(-90,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(300);
    

    rotate(90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    BK2(45,40); delay(200);
    

    rotate(90,1);
    //check 2
    forwardTime(100,1500,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,200,0);

    rotate(90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);

    FD2(83,90); delay(400);
    forwardTill(120,1,0);

    Poy(); delay(300); AO(); delay(300);  // green 4

    BK2(83,90); delay(550);
    backwardTill(140,1,0);
    backwardAlign(80,2);

    rotate(90,0);
    forwardTime(100,1500,0);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);
    

    rotate(-90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);
    

    rotate(-90,0);
    backwardTill(140,1,0);
    backwardAlign(80,2);
    forwardTill(140,1,0);
    forwardAlign(80,1);
    backwardTime(140,300,0);
    

    rotate(90,0); //ดำ
    forwardTime(200,500,0);
    forwardTill(140,1,0);
    forwardAlign(80,2);
    backwardTime(140,200,0);
    
    
    rotate(-90,0);
    forwardTime(140,600,0);



    AO(); delay(100000);

 }


void Run3() 
{   
    //FD2(83,90); delay(700); ///

    //forwardTill(120,1,0);
    
    //BK2(45,40); delay(300);
    //forwardTime(120,200,0);forwardTill(140,1,0);
    
    //rotate(90,0); ///asdasdas
    //backwardTill(140,1,0);
    //backwardAlign(80,2);
    //FD2(45,40); delay(1000);
    //forwardTime(200,500);
    // forwardTime(200,700,1);
    // forwardTill(160,1,1);
     //rotate(90,0);
    //rotate(-90,0);
    // forwardTime(100,1600);
    // forwardTime(200,600);
    // Poy(); // เทสปล่อย
    // AO(); delay(1000);
    //forwardTime(160,1000,0);
    //backwardTill(160,1,0);
    //forwardAlign(Slow,1);
    //FD2(83,90);
    //delay(600);
    // forwardTime(200,700,0);
    //forwardTill(140,1,0);
    rickroll();
    AO(); delay(10000);
    /*
    forwardTime(100,1400);
    forwardTime(180,500);
    forwardTill(180,1);
    forwardAlign(100,2);
    AO(); delay(10000);
    */
}