#include <Keypad.h>

// กำหนดจำนวนแถวและคอลัมน์
#define ROWS 4
#define COLS 4

// กำหนด Keymap ของปุ่มบน Keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// กำหนดพินของแถวและคอลัมน์
byte rowPins[ROWS] = {26, 25, 33, 32}; // ROW1, ROW2, ROW3, ROW4
byte colPins[COLS] = {13  , 12, 14, 27}; // COL1, COL2, COL3, COL4

// สร้างออบเจกต์ Keypad
Keypad keypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Serial.println("เริ่มต้นใช้งาน Keypad");
}

void loop() {
  char customKey = keypad.getKey(); // อ่านค่าปุ่มที่ถูกกด

  if (customKey) { // ถ้ามีปุ่มถูกกด
    Serial.print("Key Pressed: ");
    Serial.println(customKey); // แสดงผลปุ่มบน Serial Monitor
  }
}
