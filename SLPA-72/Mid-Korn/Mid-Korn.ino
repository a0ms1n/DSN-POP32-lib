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
void MissNaja();
void MissNaja2();
void MissNaja3();

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
    BasicMenu.buttons.push_back({"Miss1" ,MissNaja});
    BasicMenu.buttons.push_back({"Miss2" ,MissNaja2});
    BasicMenu.buttons.push_back({"Miss3" ,MissNaja3});

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
}


void MusicJaa(){
    Sound::RickRoll();
}
void MissNaja() {
    forwardTill(140,0,1);
    forwardTime(100,1700,0);
    
    rotate(90,0);
    backwardTime(200,150,0);
    backwardAlign(Slow,1);
    forwardTime(200,750,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);
    forwardTime(200,350,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);
    
    rotate(90,0);
    forwardTime(200,250,0);
    forwardAlign(Slow,1);

    Poy(); delay(300); AO(); delay(300); //Green 1

    backwardTime(200,500,1); // cp1
    backwardAlign(Slow,1);
    forwardTime(140,125,0);

    rotate(90,0);
    backwardTime(200,350,0);
    backwardAlign(Slow,1);
    forwardTime(200,650,1);

    forwardAlign(Slow,1);

    Poy(); delay(300); AO(); delay(300); //Green 2

    backwardTime(200,500,1);
    
    rotate(-90,0);
    forwardTime(200,250,0);

    rotate(90,0);
    backwardTime(200,125,0);
    backwardAlign(Slow,1);
    forwardTime(200,600,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,0);
    backwardTime(200,125,0);
    backwardAlign(Slow,1);
    forwardTime(200,1325,1); // ข้ามสะพาน
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,0);
    forwardTime(200,300,0);

    rotate(-90,0);
    forwardTime(200,250,0);
    forwardAlign(Slow,1);

    Poy(); delay(300); AO(); delay(300); //Green 3

    backwardTime(200,350,0);
    backwardAlign(Slow,1);

    forwardTime(140,200,0);

    rotate(90,0);

    forwardTime(200,350,0);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);

    backwardAlign(Slow,1);
    forwardTime(200,600,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);
    forwardTime(200,550,0);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);

    forwardTime(200,350,0);
    forwardAlign(Slow,1);
    backwardTime(200,350,0);
    backwardAlign(Slow,1);
    forwardTime(140,150,0);

    rotate(90,0);
    backwardTime(Slow,1);
    forwardTime(200,650,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,0);
    backwardAlign(Slow,1);
    forwardTime(200,750,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);
    backwardAlign(Slow,1);
    forwardTime(200,375,1);
    forwardAlign(Slow,1);
    backwardTime(140,150,0);

    rotate(90,0);
    backwardAlign(Slow,1);
    forwardTime(200,700,1);
    forwardAlign(Slow,1);

    Poy(); delay(300); AO(); delay(300); //Green 4

    backwardTime(200,750,1);
    backwardAlign(Slow,1);
    forwardTime(140,150,0);

    rotate(90,0);
    forwardTime(200,300,0);
    forwardAlign(Slow,1);
    backwardTime(140,150,0);

    rotate(-90,0);
    forwardTime(200,350,0);

    rotate(90,0);
    backwardTime(200,125,0);
    backwardAlign(Slow,1);
    forwardTime(200,625,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);
    backwardTime(200,125,0);
    backwardAlign(Slow,1);
    forwardTime(200,1125,1);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(90,0);
    backwardTime(200,125,0);
    backwardAlign(Slow,1);
    forwardTime(200,300,1);

    rotate(90,0);
    backwardTime(200,125,0);
    backwardAlign(Slow,1);
    forwardTime(200,250,1);
    forwardAlign(Slow,1);
    forwardTime(200,350,0);
    forwardAlign(Slow,1);
    backwardTime(140,200,0);

    rotate(-90,0);
    forwardTime(100,2500,0);


    Sound::RickRoll();

}
void MissNaja3() {
    
    backwardAlign(Slow,1);
    forwardTime(225,1000,1);
    AO(); delay(1000);
}

void Run2() {
    forwardAlign(Slow,1);
}

void Run3() {
    backwardAlign(Slow,1);
}

void Run4() {}

void MissNaja2() {}

