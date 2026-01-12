// LANG-TH : This example will be removed soon.



// เข้าไปเเก้/ดู PIN ใน Config.h
#include "Config.h"
#include "../../src/DSN-POP32.h"

void Run();

ServoController Grabber(6,50,0,65); // Pin Servo องศา เริ่มต้นตัวจับ
ServoController Lifter(5,10,0,180);

void setup(){
    motors.setRatio({1,1},{-1,-1}); 
    beep();
    POP32_INIT();
    BasicMenu.buttons[0].callback = Run;
    motors.setSpeedRange(0,255);
    Grabber.setInit();
    Lifter.setInit();
    delay(1000);
    Grabber.free();
    Lifter.free();
}   

void loop(){
    BasicMenu.show();
}

// เริ่มการควบคุมด้วยจอย
void Run(){
    beep();
    int32_t current_base_speed = 90;
    int32_t current_grab_angle = Grabber.cDeg;
    int32_t current_lift_angle = Lifter.cDeg;
    FlagTimer grabberDelay(5);
    FlagTimer lifterDelay(8);

    while(!SW_B()){
        Grabber.Update();
        Lifter.Update();
        oledf.clear();
        int32_t val = psx.read();

        // L1 -> ลดความเร็ว
        if(psx.button(PSB_L1) && psx.buttonNewState(PSB_L1))current_base_speed = constrain(current_base_speed - 10,90,255);

        // R1 -> เพิ่มความเร็ว
        if(psx.button(PSB_R1) && psx.buttonNewState(PSB_R1))current_base_speed = constrain(current_base_speed + 10,90,255);

        if(psx.button(PSB_L2) && psx.buttonNewState(PSB_L2))current_base_speed = 90;
        if(psx.button(PSB_R2) && psx.buttonNewState(PSB_R2))current_base_speed = 255;

        // R ขวา - กาง
        if(psx.button(PSB_RSTIK_RIGHT) && grabberDelay.check())Grabber.cDeg++;
        if(psx.button(PSB_RSTIK_LEFT) && grabberDelay.check())Grabber.cDeg--;

        if(psx.button(PSB_RSTIK_UP) && lifterDelay.check())Lifter.cDeg++;
        if(psx.button(PSB_RSTIK_DOWN) && lifterDelay.check())Lifter.cDeg--;

        motors.left_speed = 0;
        motors.right_speed = 0;
        // LSIDE -> Up
        if(val & PSB_PAD_UP){
            motors.left_speed += current_base_speed;
            motors.right_speed += current_base_speed;
        }
        // LSIDE -> Down
        if(val & PSB_PAD_DOWN){
            motors.left_speed -= current_base_speed;
            motors.right_speed -= current_base_speed;
        }
        // LSIDE -> Left
        if(val & PSB_PAD_LEFT){
            motors.left_speed -= current_base_speed;
            motors.right_speed += current_base_speed;
        }
        // LSIDE -> Right
        if(val & PSB_PAD_RIGHT){
            motors.left_speed += current_base_speed;
            motors.right_speed -= current_base_speed;
        }
        oledf.text(0,0,1,"val = %d",val);
        oledf.text(0,10,1,"BaseSpeed = %d",current_base_speed);
        oledf.text(0,20,1,"Lspeed = %d",motors.left_speed);
        oledf.text(0,30,1,"Rspeed = %d",motors.right_speed);
        oledf.text(0,40,1,"Grab : %d",(int)Grabber.cDeg);
        oledf.text(0,50,1,"Timer : %d",(int)millis());
        oledf.show();

        motors.update();
        delay(1);
    }
    SW_B();
    
}