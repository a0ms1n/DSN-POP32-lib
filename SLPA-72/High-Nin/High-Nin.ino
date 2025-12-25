#include "Config.h"
#include "../../src/DSN-POP32.h"

// PIN, White_Value, Black_Value
// ไล่เซนเซอร์ตรงนี้
LEDSensor sensors[] ={
    {0,3200,500}, // หน้าซ้าย
    {1,2400,200}, // หน้ากลางซ้าย
    {2,1800,200}, // หน้ากลางขวา
    {3,3300,600}, // หน้าขวา
    {4,3150,500}, // หลังซ้าย
    {5,3050,500}, // หลังกลางซ้าย
    {6,2300,400}, // หลังกลางขวา
    {7,2700,400}, // หลังขวา
};


LEDSensorLine<4> ground_sensor({&sensors[0],&sensors[1],&sensors[2],&sensors[3]},0,50,400);

void Run();

void setup(){
    beep();
    POP32_INIT();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[0].callback = Run2; // Run 2
    BasicMenu.buttons[0].callback = Run3; // Run 3
    motors.setSpeedRange(100,255);
    motors.setRatio({1.0,1.05},{1.0,1.0});
}   

void loop(){
    BasicMenu.show();
}

void Run1(){
    FlagTimer ft(3000);
    

}

void Run2(){

}

void Run3(){

}