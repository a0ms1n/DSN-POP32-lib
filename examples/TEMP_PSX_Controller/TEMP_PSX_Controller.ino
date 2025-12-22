// LANG-TH : This example will be removed soon.



// เข้าไปเเก้/ดู PIN ใน Config.h ดูเฉพาะบรรทัด บนๆ
#include "Config.h"
#include <DSN-POP32.h>

void Run();

void setup(){
    beep();
    POP32_INIT();
    BasicMenu.buttons[0].callback = Run;

}   

void loop(){
    BasicMenu.show();
}

// เริ่มการควบคุมด้วย Joy 
void Run(){
    beep();
    int32_t current_base_speed = 60;
    
    while(!SW_B()){
        oledf.clear();
        int32_t val = psx.read();

        // L1 -> ลดความเร็ว
        if(psx.buttonNewState(PSB_L1))current_base_speed = constrain(current_base_speed - 10,0,255);

        // R1 -> เพิ่มความเร็ว
        if(psx.buttonNewState(PSB_R1))current_base_speed = constrain(current_base_speed + 10,0,255);

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
        oledf.text(0,40,1,"Timer : %d",(int)millis());
        oledf.show();

        motors.update();
        delay(1);
    }
    SW_B();
    
}