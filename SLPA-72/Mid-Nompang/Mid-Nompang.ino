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
    motors.setSpeedRange(95,250);
    motors.setRatio({1.2,1.2},{1,1.0});
    
}   

void loop(){
    BasicMenu.show();
}



void Run1(){
    imu.Start();
    forwardTime(150,100);
    forwardAlign(150,true,false);
    rotate(90,true);

    
    
    

 }

void Run2(){
    imu.Start();
    forwardTime(150,2000,false);
    
 }


void Run3() 
{   
    imu.Start();
    rotate(90,0);
   
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