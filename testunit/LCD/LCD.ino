#include 
#include 

// Set the LCD address to 0x27 in PCF8574 by NXP and Set to 0x3F in PCF8574A by Ti
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  lcd.begin();
  lcd.print("Mind Isareeyakorn"); // แสดงคำว่า LCD Safe Mode ออกทางหน้าจอ
}

void loop() {
  LCD_ON(); // เปิดหน้าจอ
  delay(1000); // หน่วงเวลา 1 วินาที
  LCD_OFF(); // ปิดหน้าจอ
  delay(1000); // หน่วงเวลา 1 วินาที
}

void LCD_ON() {
  lcd.display(); // เปิดการแสดงตัวอักษร
  lcd.backlight(); // เปิดไฟแบล็กไลค์
}

void LCD_OFF() {
  lcd.noDisplay(); // ปิดการแสดงตัวอักษร
  lcd.noBacklight(); // ปิดไฟแบล็กไลค์
}
