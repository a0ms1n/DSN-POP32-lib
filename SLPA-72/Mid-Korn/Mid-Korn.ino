#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"
#include "Music.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้
int Base_Speed = 160;
int Slow = 70; 
int Fast = 200;

void Run1();
void Run2();
void Run3();
void MusicJaa();

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
    BasicMenu.buttons[3].callback = Run4;
    BasicMenu.buttons.push_back({"Music",MusicJaa});
    Front.__Track = 700;
    Back.__Track = 700;
    motors.setSpeedRange(90,250);
    motors.setRatio({1,1},{1.0,1.0});
    
}   

void loop(){
    BasicMenu.show();
}



void Run1(){
    
    imu.Start();
    beep();


    forwardTill(140,1,0);
    forwardTime(200,600,0);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    backwardTime(140,200);

    rotate(-90,0);

    backwardAlign(Slow,1);
    forwardTime(200,500,1); //Check-Point 1
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    backwardTime(140,150);

    rotate(-90,0);
    backwardAlign(Slow,1);

    forwardTime(200,700,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    backwardTime(140,200);

    rotate(-90,0);

    forwardTill(140,1,0);
    backwardTime(140,200);

    rotate(-90,0);
    backwardAlign(Slow,1);

    forwardTill(160,1,1);

    Poy(); delay(300); AO(); delay(300); //Green 1

    backwardTime(200,300,1);
    backwardAlign(Slow,1);
    forwardTime(140,200,0);

    rotate(-90,0);

    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(200,800,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    backwardTime(140,200);

    rotate(90,0);

    backwardTill(140,1,0);
    backwardAlign(Slow,1);
    
    forwardTime(200,600,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    backwardTime(140,200);

    rotate(-90,0);

    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(200,300,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,2);
    backwardTime(140,150);

    rotate(-90,0);
    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(200,700,1); //Check-Point 2

    backwardTime(200,450,0); //Blackest

    rotate(90,0);

    forwardTime(200,550,0);
    forwardTill(140,1,0);
    forwardAlign(Slow,2);
    backwardTime(140,200,0);

    rotate(-90,0);

    forwardTill(120,1,0);

    Poy(); delay(300); AO(); delay(300); //Green 2
    forwardAlign(Slow,1);
    backwardTime(200,850,1);
    backwardAlign(Slow,1);
    forwardTime(140,200,0);

    rotate(-90,1);
    backwardAlign(Slow,1);

    forwardTime(200,1000,1);

    
    forwardTill(140,1,0);
    forwardAlign(Slow,2);
    backwardTime(140,200);

    rotate(90,1);

    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(200,200,1);
    forwardTime(100,1700,0);

    Poy(); delay(300); AO(); delay(300); //Green 3

    // forwardAlign(Slow,2);

    backwardTime(100,1700,0);
    backwardTill(140,1,1);
    backwardAlign(Slow,1);

    forwardTime(140,200,0);
    
    rotate(90,1);


    backwardAlign(Slow,1);

    forwardTime(200,1000,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);

    backwardTime(140,200,0);

    rotate(-90,0);

    backwardAlign(Slow,1);

    forwardTime(200,400,1);

    rotate(-90,1);

    backwardTill(140,1,1);
    backwardAlign(Slow,1);

    forwardTill(160,1,1); //เดินมาปล่อยพอดี

    Poy(); delay(300); AO(); delay(300); //Green 4
    forwardAlign(Slow,1);

    backwardTime(200,250,1);
    backwardAlign(Slow,1);

    forwardTime(140,200,1); 

    rotate(90,1);

    forwardTime(200,350,1);

    rotate(-90,1);
    backwardTill(140,1,1);
    backwardAlign(Slow,1);

    forwardTime(200,700,1);

    rotate(-85,0);

    forwardTime(200,400,1);
    forwardTill(140,1,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);

    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(200,400,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,3,200);
    backwardTime(140,200,0);

    rotate(90,0);
    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(200,550,1); // กลับขึ้นสะพาน
    forwardTill(140,1,0);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,0);
    backwardTill(140,1,0);
    backwardAlign(Slow,1);

    forwardTime(200,725,1);

    rotate(-90,1);
    backwardAlign(Slow,1);

    forwardTime(200,1000,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);

    backwardTime(140,200,0);

    rotate(90,0);
    backwardAlign(Slow,1);

    forwardTime(200,600,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,2);

    backwardTime(140,200,0);

    rotate(90,1);
    backwardAlign(Slow,1);

    forwardTime(200,550,1);
    forwardTill(140,1,0);
    forwardAlign(Slow,1);

    forwardTime(140,400,0);
    Sound::RickRoll();
    AO(); delay(10000);
    
    

 }

void Run2(){
    imu.Start();
    beep();
    
    forwardTill(140,1,0);
    forwardAlign(Slow,2);
    backwardTime(140,200,0);

    rotate(-90,0);

    forwardTill(120,1,0);

    Poy(); delay(300); AO(); delay(300); //Green 2

    backwardTime(200,850,1);
    backwardAlign(Slow,1);
    forwardTime(140,200,0);

    rotate(-90,0);
    backwardAlign(Slow,1);

    forwardTime(200,1000,1);

    AO(); delay(100000);

 }


void Run3() 
{   
    imu.Start();
    //FD2(83,90); delay(700); ///

    //forwardTill(120,1,0);
    
    //BK2(45,40); delay(300);
    //forwardTime(120,200,0);forwardTill(140,1,0);
    
    //rotate(90,0); ///asdasdas
    //backwardTill(140,1,0);
    //backwardAlign(80,2);
    //FD2(45,40); delay(1000);
    
    //Prefer test for Direct
    //backwardTill(140,1,0);
    forwardTill(80,1);
    //forwardTime(140,200);
    // forwardTime(200,1000,1);
    //forwardTill(140,1,0);

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
    AO(); delay(10000);
    /*
    forwardTime(100,1400);
    forwardTime(180,500);
    forwardTill(180,1);
    forwardAlign(100,2);
    AO(); delay(10000);
    */
}

void Run4(){
    
}

void MusicJaa(){
    Sound::RickRoll();
}