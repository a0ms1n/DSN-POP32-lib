# การติดตั้ง Library เเละตัวอย่าง
  
  


## สารบัญ
  - [การ Setup Extension สำหรับการพัฒนาบน VSCode](#การ-setup-extension-สำหรับการพัฒนาบน-vscode)
- [การติดตั้ง Library](#การติดตั้ง-library)
- [ตัวอย่าง](#ตัวอย่าง)

  

## การ Setup Extension สำหรับการพัฒนาบน VSCode

สามารถดาวน์โหลด .zip ได้จาก Repository นี้
https://github.com/namooTH/setup-pop32

หรือใช้โฟลเดอร์ "./vscode_setup" (ให้ย้ายไปไว้ใน workspace ที่ต้องการ)
*ใช้ได้สำหรับ Board POP32 เท่านั้น*

### ขั้นตอนการ Setup
1. ลง package POP32 , STM32 bootloader ใน Arduino ตามปกติ
2. โหลด extension Arduino Community ใน Vscode (https://marketplace.visualstudio.com/items?itemName=vscode-arduino.vscode-arduino-community)
3. กดตรงเเถบค้นหาด้านบนใน vscode พิมพ์ " >Arduino: board config " เลือกเป็น POP32
4. เปลี่ยนชื่อโฟลเดอร์ (vscode_exmp) ให้เป็น .vscode ถ้ามีอยู่เเล้วให้ลบอันเก่าทิ้งก่อน
5. รัน "setup.py" โดยใช้ Python
6. ให้เขียนโค้ดใน vscode (สังเกตว่าตอนนี้มันจะมี code suggestion เเล้ว)
7. หากต้องการ verify สามารถ verify ใน vscode ได้เลย
8. หากต้องการอัพโหลดเเนะนำให้ใช้ ArduinoIDE เปิดไฟล์ .ino ที่ต้องการเเล้วอัพโหลดเข้าบอร์ด

## การติดตั้ง Library

## ตัวอย่าง