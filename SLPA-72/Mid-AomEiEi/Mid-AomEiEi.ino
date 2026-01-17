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
void Run4();

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
    BasicMenu.buttons[3].callback = Run4; // Run 4
    
    BasicMenu.buttons.push_back({"Music",MusicJaa});
    Front.__Track = 700;
    Back.__Track = 700;
    motors.setSpeedRange(85,250);
    motors.setRatio({1.1,1.1},{1,1.0});
    
}   

void loop(){
    BasicMenu.show();
}

void Run1(){
    
    imu.Start();
    beep();


    forwardTill(140,1,0);
    forwardTime(200,600,0);
    forwardAlign(Slow,1);
    backwardTime(140,200);

    rotate(-90,0);

    backwardAlign(Slow,1);
    forwardTime(200,450,1);
    forwardAlign(Slow,1);
    backwardTime(140,200);

    rotate(90,0);
    backwardAlign(Slow,1);

    forwardTime(200,400,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);

    backwardAlign(Slow,1);
    forwardTime(200,600,1);
    forwardAlign(Slow,1);
    backwardTime(140,300,0);

    rotate(90,0);
    backwardAlign(Slow,1);

    forwardTime(200,650,1);
    forwardAlign(Slow,1);

    Poy(); delay(300); AO(); delay(300); //Green 1
    backwardTime(140,200,1);

    rotate(180,0);

    backwardAlign(Slow,1);
    forwardTime(200,800,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,0);

    backwardAlign(Slow,1);
    forwardTime(200,650,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,0);

    backwardAlign(Slow,1);
    forwardTime(200,350,1);
    forwardAlign(Slow,1);
    backwardTime(140,200);

    rotate(-90,0);

    backwardAlign(Slow,1);
    forwardTime(200,350,1);
    forwardAlign(Slow,1);
    backwardTime(140,200);

    rotate(90,0); // ออกจาก Maze

    backwardAlign(Slow,1);
    forwardTime(200,350,1);

    rotate(90,1);

    backwardAlign(Slow,1);
    forwardTime(200,850,1); // CP1

    backwardTime(200,450,0);

    rotate(-90,1);

    backwardTime(200,350,1);
    backwardAlign(Slow,1);

    forwardTime(200,550,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,1);

    forwardAlign(Slow,1);

    Poy(); delay(300); AO(); delay(300); //Green 2
    backwardTime(140,200,1);

    rotate(180,1);

    backwardAlign(Slow,1);
    forwardTime(200,750,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0); //สะพานขึ้น

    rotate(90);

    backwardAlign(Slow,1);
    forwardTime(200,600,1);

    rotate(-90,0);

   backwardAlign(Slow,1);
    forwardTime(200,200,1);

    forwardTime(100,1800,0);

    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,1);

    backwardTime(200,350,1);
    backwardAlign(Slow,1);

    forwardTime(200,700,1);

    forwardAlign(Slow,1);

    Poy(); delay(300); AO(); delay(300); //Green 3

    forwardAlign(Slow,1);
    backwardTime(200,550,1); // ใกล้ตะเกียบ

    rotate(-90,1);

    backwardAlign(Slow,1);
    forwardTime(200,200,1);
    forwardTime(100,1700,0); //ข้ามตะเกียบกลับ
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,1);
    forwardTime(200,300,1);
    forwardAlign(Slow,1);
    backwardTime(140,300,0);

    rotate(90,0);
    forwardTime(200,200,1);
    forwardAlign(Slow,1);
    forwardTime(200,300,1);
    forwardAlign(Slow,1);
    

    Poy(); delay(300); AO(); delay(300); //Green 4
    forwardAlign(Slow,1);

    backwardTime(200,250,1);
    backwardAlign(Slow,1);
    backwardTime(200,300,1);

    rotate(90,1);
    backwardAlign(Slow,1);

    forwardTime(200,800,1); // ขึ้นสะพานขากลับ
    forwardAlign(Slow,1);
    backwardTime(140,200,0);
    
    rotate(-90,1);

    backwardAlign(Slow,1);

    forwardTime(200,650,1); // ลงสะพานขากลับ

    rotate(-90,1);

    backwardAlign(Slow,1);

    forwardTime(200,350,1);

    rotate(90,1);

    forwardTime(200,550,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,1);

    forwardTime(140,600,1);

    Sound::RickRoll();
    AO(); delay(1000);
}

#define R_BCK() backwardTime(160,200,0) 
#define R_FOR() forwardTime(160,200,0)

void Run4(){
    imu.Start();
    beep();
    forwardTill(140,0,0);
    forwardTime(200,500,0);
    forwardTill(160,1,0);
    R_BCK();

    rotate(-90,0);
}


void Run3() {
    
    backwardAlign(Slow,1);
    forwardTime(200,1000,1);
}

void Run2() {
    imu.Start();
    beep();
    forwardTill(200,1,1);
    backwardTime(150,450,0);
    rotate(90);
    backwardAlign(Slow,1);
    
}


void MusicJaa(){
    Sound::RickRoll();
}