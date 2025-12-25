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

LEDSensorLine<2> Front({
    &sensors[1],
    &sensors[2]
});

LEDSensorLine<2> Back({
    &sensors[5],
    &sensors[6],
}); 

void Run1();
void Run2();
void Run3();

void setup(){
    beep();
    POP32_INIT();
    imu.Start();
    BasicMenu.buttons[0].callback = Run1; // Run 1
    BasicMenu.buttons[1].callback = Run2; // Run 2
    BasicMenu.buttons[2].callback = Run3; // Run 3
    motors.setSpeedRange(100,255);
    motors.setRatio({1,1.3},{1.0,1.0});
}   

void loop(){
    BasicMenu.show();
}

void Run1(){
    beep();
    drive_motors.StraightDrive(80,&PIDStraight);
    beep();
    while(true){
        drive_motors.Update();
        Front.readLine(true);
        if(Front.cOnline){
            drive_motors.Stop();
            break;
        }
    }
    while(!SW_B()){
        Front.readLine(true);
        oledf.clear();
        oledf.text(0,0,1,"%d %d",(int32_t)Front.cPosition,(int32_t)Front.cOnline);
        oledf.show();
    }
    

}

void Run2(){

}

void Run3(){

}