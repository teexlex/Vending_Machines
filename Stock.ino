#include <Keypad.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// กำหนดจำนวนแถวและหลัก
const byte ROWS = 4; // จำนวนแถว
const byte COLS = 4; // จำนวนหลัก

// กำหนดตัวอักษรของ Keypad
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// ตรวจสอบขา GPIO สำหรับแถว (R) และหลัก (C) ให้ตรงกับการต่อวงจร
byte rowPins[ROWS] = {26, 25, 33, 32};  // ROW 1-4 → GPIO 15, 2, 4, 16
byte colPins[COLS] = {13  , 12, 14, 27}; // COL 1-4 → GPIO 17, 5, 18, 19

// สร้าง Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// OLED Display Config
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  Serial.println("เริ่มทดสอบ Keypad และ OLED Display");

  // ตรวจสอบ OLED Display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED Display ไม่สามารถเริ่มต้นได้"));
    for (;;); 
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Keypad OLED Test");
  display.display();

  // Debugging ขา GPIO
  Serial.println("Row Pins:");
  for (int i = 0; i < ROWS; i++) {
    Serial.print("Row ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(rowPins[i]);
  }
  Serial.println("Column Pins:");
  for (int i = 0; i < COLS; i++) {
    Serial.print("Column ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(colPins[i]);
  }
}

void loop() {
  char key = keypad.getKey(); // อ่านปุ่มจาก Keypad
  
  if (key) {
    Serial.print("ปุ่มที่กด: ");
    Serial.println(key);

    // แสดงปุ่มที่กดบน OLED Display
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(2);
    display.print("Key: ");
    display.println(key);
    display.display();
  }
}
