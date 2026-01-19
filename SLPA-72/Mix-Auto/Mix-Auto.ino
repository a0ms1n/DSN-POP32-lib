// LANG-TH : This example will be removed soon.



// เข้าไปเเก้/ดู PIN ใน Config.h

#include "Function.h"

void Run();

void setup(){
    FlagDown();
    LiftDown();
    beep();
    POP32_INIT();
    BasicMenu.buttons[0].callback = Run1;
    BasicMenu.buttons[1].callback = Run2;
    BasicMenu.buttons[2].callback = Run3;
    BasicMenu.buttons[3].callback = Run4;
    motors.setSpeedRange(80,255); // ปรับความเร็วช้าสุด - เร็วชุด
    imu.Start();
    PIDStraight.SetOutputLimits(-210, 210);
    
    //motors.setReverse({1},{1});
    ground_sensor.update_mid();

    // เปอร์เซ็นจับค่าดำ 0 - 1000
    ground_sensor.__Track = 500; // ปรับเปอร์เซ็นจับเส้นดำ
    BasicMenu.buttons.push_back({
        "Sensor Calibrate",SensorCalibrate
    });
}   

void loop(){
    BasicMenu.show();
}

// อ้าเเขน กดรันนี้เพื่อ รอรับกระป๋อง
void Run1(){
    CanGrab();
    delay(1000);
    CanPoy(); // ปล่อยปอง
    LiftDown(); //แขนลง
    int cnt = 3;
    while(cnt>=0){
        oledf.clear();
        oledf.text(0,0,1,"%d",(int)analog(can_sensor_PIN));
        oledf.show();
        if(analog(can_sensor_PIN) >= can_sensor_val)cnt--;
        else cnt = 3;
        delay(100);
    }
    beep();
    beep();
    delay(2000);
    beep();
    CanGrab();
    beep();
    Run2();
}

/// ออกตัวโดยไม่รอกระป๋อง 
void Run2(){
    ForwardStraightTillWhite(230,400); //ตรงกว่าจะขาว ค.เร้ว ตรงไปอีก...ms
    ForwardUntilCross(230,150); //ค.เร็วตรง ค.เร็วหมุน
    SkipCross(170,200); //ค.เร็ว ตรงไปอีก...ms
    TurnLeft(200);
    Align(150);
    
    ForwardUntilCross(230,150);
    SkipCross(170,200);
    TurnLeft(170);
    Align(150);

    ForwardUntilCross(230,180);
    SkipCross(120,350);
    TurnRight(200);
    Align(150);
    
    ForwardUntilCrossBW(180,140); //เส้นประ ค.เร็วตรง ค.เร็วหมุน
    
    ForwardStraightTime(-160,450); //-ถอยหลังด้วยไจโร
    Align(100);
    ForwardUntilCross(75,85);

    ForwardStraightTillWhite(220); // สีเขียว
    ForwardStraightTime(250,300);
    LineScan(15,1); // หมุนหาเส้น กรณีเลยเส้น ลบได้ ถ้ามั่นใจว่าหุ่นเดินตรงเส้นเป๊ะๆ

    
    ForwardUntilTime(250,150,1700);
    ground_sensor.__Track = 400;
    ForwardUntilCross(180,150);
    ground_sensor.__Track = 500;
    ForwardStraightTime(150,1580); // ****
    rotate(-90); // หมุนขวา ไจโร
    beep();
    Run3();

}

// เดินจากจุดเซฟ 
void Run3(){
    CanGrab();
    LiftDown();
    FlagDown();
    ForwardStraightTillWhite(190);
    
    ForwardTime(170,220);

    ForwardUntilCross(170,150);
    SkipCross(140,300);
    TurnRight(150);
    Align(160);
    
    ForwardUntilTime(250,150,2200);
    ForwardUntilTime(180,140,2200);
    ForwardUntilCross(170,130);
    SkipCross(140,300);

    ForwardUntilCross(240,130);
    SkipCross(140,300);
    ForwardUntilButton(250,130);
    LiftUp();
    delay(1000);
    CanPoy();
    Flagup();
    Sound::ChillGuy();

}                         
     
// สำหรับทดลองโค้ดบางส่วน
void Run4(){
    CanPoy();
    LiftDown();
}