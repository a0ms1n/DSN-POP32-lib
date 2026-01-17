#include "Config.h"
#include "../../src/DSN-POP32.h"
#include "Function.h"
#include "Music.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้
int Base_Speed = 160;
int Slow = 70; 
int Fast = 200;
// 600 = 1
void Run1();
void Run2();
void Run3();
void MusicJaa();



 int R = -90;
 int L = 90;

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
    motors.setSpeedRange(95,250);
    motors.setRatio({1.2,1.2},{1,1.0});
    
}   

void loop(){
    BasicMenu.show();
}



void Run1(){

    // backward  backwardTill(160,true); backwardAlign(160); forwardTime(160,300);
    // forward   forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
    imu.Start();

    forwardTime(200,500);
    forwardAlign(70);
    backwardTime(140,200);
    rotate(-90);

    forwardTime(200, 300);
    rotate(90);

    backwardAlign(70);
    forwardTime(200, 300);
    forwardAlign(70);
    backwardTime(140,200 );
    rotate(90);

    backwardAlign(70);
    forwardTime(200, 500);
    forwardAlign(70);
    backwardTime(140, 300);
    rotate(90);

    backwardAlign(70);
    forwardTime(200, 700);
    forwardAlign(70);
    Poy(); // green 1

    backwardTime(200, 700);
    backwardAlign(70);
    forwardTime(140, 100);
    rotate(L);

    backwardAlign(70,3,200);
    forwardTime(200, 500);
    forwardAlign(70);
    backwardTime(140,200);
    rotate(R);

    forwardTime(200,300);
    forwardAlign(70);
    backwardTime(140,200);
    rotate(R);

    forwardTime(200,300);
    forwardAlign(70);
    backwardTime(140, 200);
    rotate(L);

    forwardTime(200, 300);
    rotate(L);// red

    backwardAlign(70);
    forwardTill(120);
    backwardTime(200, 400);
    rotate(R);

    forwardTime(200, 300);
    forwardAlign(70);
    backwardTime(140, 200);
    rotate(R);

    forwardAlign(70);
    Poy();// green 2

    forwardAlign(70,3,200);
    backwardTime(200, 600);
    backwardAlign(70);
    forwardTime(140, 200);
    rotate(R);

    forwardTime(200, 500);
    rotate(R);

    backwardAlign(70,3,200);
    forwardTime(120,1600);
    forwardAlign(70);
    backwardTime(140,200);
    rotate(R);
    backwardTime(200, 300);
    backwardAlign(70,5,200);
    forwardTime(200, 700);
    forwardAlign(70);
    Poy();// green 3







    // forwardTime(200, 250);
    // forwardAlign(70);
    // backwardTime(140,200 );



    












    
    
    

 }

void Run2(){
    imu.Start();
    //forwardTime(200,400);
    //forwardTill(140);
    //forwardAlign(140);
    //backwardTime(140,200);
    //rotate(R);
    //forwardTill(160,true);
    //forwardAlign(140);
    //backwardTime(140,200);
    //rotate(L);
    //forwardTill(140,true);
    //forwardAlign(70);
    //backwardTime(160,200);
    //rotate(L);
    //forwardTill(140);
    //forwardAlign(70);
    //backwardTime(160,200);
    //rotate(L);
    //forwardTill(160,true); backwardTime(160,300); forwardAlignl(70); backwardTime(160,300);
    //Poy();// 1
    //backwardTill(160,true); backwardAlign(160); forwardTime(160,300);
    //rotate(L);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(R);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(R);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(L);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(L);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,600);
    //rotate(L);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(L);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,100);
    //Poy();// 2
    //backwardTill(160,true); backwardAlign(160); forwardTime(160,300);
    //rotate(R);
    //forwardTime(160, 900);
    //rotate(R);
    //forwardTill(120,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(R);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,100);
    //Poy();
    //backwardTill(160,true); backwardAlign(160); forwardTime(160,600);
    //rotate(R);
    //forwardTill(120,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(R);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(L);
    //forwardTill(160,true); forwardAlignl(70); backwardTime(160,100);
    //forwardTime(160, 500);
    //Poy();
    //backwardTime(160, 600);
    //rotate(R);
    //forwardTill(120,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(R);
    //forwardTime(160, 900);
    //rotate(R);
    //forwardTime(160, 600);
    //rotate(L);
    //forwardTill(120,true); forwardAlignl(70); backwardTime(160,300);
    //rotate(L);
    //forwardTill(120,true); forwardAlignl(70); forwardTime(160,500);
//
 }


void Run3() 
{   
    imu.Start();
   forwardTime(200, 700);
   
}

void Run4(){
    while(true){
        Front.readLine();
        Back.readLine();
        oledf.clear();
        oledf.text(0,0,1,"%d %d",Front.cOnline,Back.cOnline);
        oledf.show();
    }
}

void MusicJaa(){
    Sound::RickRoll();
}