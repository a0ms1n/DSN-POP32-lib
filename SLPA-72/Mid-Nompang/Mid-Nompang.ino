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
void Nompang();
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
    BasicMenu.buttons.push_back({"Nompang",Nompang});
    Front.__Track = 700;
    Back.__Track = 700;
    motors.setSpeedRange(110,250);
    motors.setRatio({1.0,1.0},{1,1.0});

    
}   

void loop(){
    BasicMenu.show();
}



void Run1(){
    forwardTime(220,500);
    // backward  backwardTill(160,true); backwardAlign(160); forwardTime(160,300);
    // forward   forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
  


 }

void Run2(){
    imu.Start();
  
 }


void Run3() 
{   
    imu.Start();
   backwardAlign(100);
   
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

void Nompang() {

    // backward  backwardTill(160,true); backwardAlign(160); forwardTime(160,300);
    // forward   forwardTill(160,true); forwardAlignl(70); backwardTime(160,300);
    /// imu.Start();

    forwardTime(120, 900);
    forwardAlign(100);
    backwardTime(140, 300);
    rotate(L);
    
    backwardAlign(100);
    forwardAlign(100);
    forwardTime(200,300);
    forwardAlign(100);
    backwardTime(140, 300);
    rotate(L);

    backwardTime(200, 300);
    backwardAlign(100,3,200);
    forwardTime(200, 600);
    forwardAlign(100,3,200);
    backwardTime(140, 400);
    rotate(L);
    forwardTime(200, 200);
    forwardAlign(100);
    Poy(); // 1 green

    backwardTime(200, 500);
    backwardAlign(100);
    forwardTime(140, 100);
    rotate(L);
    backwardTime(200, 300);
    backwardAlign(100,3,200);
    forwardTime(200, 700);
    forwardAlign(100);
    Poy(); // 2 green

    backwardTime(200, 600);
    rotate(R);
    backwardAlign(100);

    forwardTime(200, 400);
    rotate(L);
    backwardAlign(100);

    forwardTime(200, 500);
    forwardAlign(100,2,200);
    backwardTime(140, 260);
    rotate(R);

    forwardTime(200, 600);
    forwardAlign(100,3,200);
    backwardTime(140, 200);
    rotate(R);

    forwardTime(200, 350);
    rotate(R);
    backwardAlign(100);
    forwardTime(200, 300);
    forwardAlign(100);
    Poy();// 3 green

    backwardAlign(100);
    forwardTime(140,200);
    rotate(L);

    forwardTime(200, 300);
    forwardAlign(100);
    backwardTime(140, 200);
    rotate(R);

    forwardTime(200, 300);
    forwardAlign(100);
    backwardTime(140, 200);
    rotate(L);

    forwardTime(200, 300);
    forwardAlign(100);
    backwardTime(140, 200);
    rotate(L);

    forwardTime(200, 700);
    forwardAlign(100);
    Poy();// 4 green
    backwardTime(200, 800);
    backwardAlign(100);
    forwardTime(140,200 );
    rotate(L);

    forwardTime(200, 300);
    forwardAlign(100);
    backwardTime(140,200);
    rotate(R);

    forwardTime(200, 500);
    forwardAlign(100);
    backwardTime(140, 300);
    rotate(L);

    forwardTime(200, 500);
    forwardAlign(100);
    backwardTime(140, 200);
    rotate(L);

    forwardTime(200, 300);
    forwardAlign(100);
    backwardTime(200, 400);
    backwardAlign(100);
    forwardTime(140, 200);
    rotate(L);

    forwardTime(200,500);
    forwardAlign(100);
    backwardTime(140, 200);
    rotate(R);

    forwardTime(200, 800);
    rotate(R);

    forwardTime( 200, 700);
    forwardAlign(100);
    backwardTime(140, 200);
    rotate(L);

    forwardTime(200, 700);
    forwardAlign(100);
    backwardTime(140, 200);
    rotate(L);

    forwardTime(200, 400);
    rotate(R);
    backwardAlign(100);

    forwardAlign(100);
    forwardTime(200, 400);

    forwardAlign(100);
    backwardTime(140, 200);
    rotate(R);

    backwardAlign(100,3,200);
    forwardTime(120, 1800);




    


























    // forwardTime(200, 250);
    // forwardAlign(70);
    // backwardTime(140,200 );





}