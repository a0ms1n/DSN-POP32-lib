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
    imu.Start();
    PIDStraight.SetOutputLimits(-230, 230);
    motors.setSpeedRange(80,255);
    
    //motors.setReverse({1},{1});
    ground_sensor.update_mid();

    // เปอร์เซ็นจับค่าดำ 0 - 1000
    ground_sensor.__Track = 500;
    BasicMenu.buttons.push_back({
        "Sensor Calibrate",SensorCalibrate
    });
    motors.setRatio({1.0},{1.05});
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

void Run2(){

  ForwardStraightTillWhite(250,400);
  ForwardUntilCross(230,150);
  SkipCross(170,200);
  TurnLeft(200);  //เลี้ยวซ้ายแรก
  Align(150);

  ForwardUntilCross(235,150);
  SkipCross(170,200);
  TurnLeft(170); //เลี้ยวซ้ายที่ สอง
  Align(150);

  ForwardUntilCross(235,150);
  SkipCross(170,200);
  TurnRight(170); //เลี้ยวขวาครั้งแรก
  Align(120);
 
  ForwardStraightTime(-150,300); //ถอยแล้วปรับให้ตรงเส้นกลาง
  Align(120);

  ForwardUntilTime(120,120,1400);
  Align(100);
  ForwardUntilCrossBW(160,180); //เดินเส้นประ ความเร็วตรงและความเร็วหมุนตามลำดับ

  ForwardStraightTime(-150,550); //-ถอยหลังด้วยไจโรเพื่อปรับให้ตรงเส้น
  Align(100);
  ForwardUntilCross(80,95);

  ForwardStraightTime(160,1500); //เดินหน้าด้วยไจโร
  ForwardStraightTillWhite(170,0,0); // สีเขียวด้วยไจโร
  ForwardStraightTime(170,700);
  LineScan(10,1); //หมุนเพื่อหาเส้น กรณีที่หาเส้นไม่เจอ ซึ่งใส่ไว้กันหมาเฉยๆ

  ForwardUntilTime(150,250,1000);
  ground_sensor.__Track = 300;
  ForwardUntilCross(170,150);
  ground_sensor.__Track = 400;
  ForwardStraightTime(150,1580); // ****
  rotate(-90); // หมุนขวา ไจโร
  beep();
  Run3();

}

void Run3(){
//เช็ตพ้อย
    CanGrab();
    LiftDown();
    FlagDown();
    ForwardStraightTillWhite(190);
    ForwardTime(170,220);

    ForwardUntilCross(170,150);
    SkipCross(140,300);
    TurnRight(170); 
    Align(160);
    
    ForwardUntilTime(180,170,2200);

    ForwardUntilCross(160,150);
    SkipCross(120,200);

    ForwardUntilTime(250,170,2500);
    ForwardUntilCross(150,120);
    beep();
    
    ForwardUntilButton(200,120);
    LiftUp();
    delay(1100);
    CanPoy();
    Flagup();
    Sound::ChillGuy();


}

 
     
// สำหรับทดลองโค้ดบางส่วน
void Run4(){
    CanPoy();
    FlagDown();
    LiftDown();
}