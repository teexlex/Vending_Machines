#define RELAY_PIN_1 23  // กำหนด GPIO Pin 1 สำหรับควบคุม Relay 1
#define RELAY_PIN_2 22  // กำหนด GPIO Pin 2 สำหรับควบคุม Relay 2
#define RELAY_PIN_3 21  // กำหนด GPIO Pin 3 สำหรับควบคุม Relay 3
#define RELAY_PIN_4 19  // กำหนด GPIO Pin 4 สำหรับควบคุม Relay 4

void setup() {
  pinMode(RELAY_PIN_1, OUTPUT);  // ตั้ง GPIO 1 เป็น OUTPUT
  pinMode(RELAY_PIN_2, OUTPUT);  // ตั้ง GPIO 2 เป็น OUTPUT
  pinMode(RELAY_PIN_3, OUTPUT);  // ตั้ง GPIO 3 เป็น OUTPUT
  pinMode(RELAY_PIN_4, OUTPUT);  // ตั้ง GPIO 4 เป็น OUTPUT
  Serial.begin(115200);  // เปิด Serial Monitor ที่ Baud Rate 115200
  Serial.println("System Starting..."); // แจ้งว่าโปรแกรมเริ่มทำงาน
}

void loop() {
  // เปิด Relay 1 และปิด Relay 2
  digitalWrite(RELAY_PIN_1, HIGH);  // เปิด Relay 1
  delay(2000);  // รอ 2 วินาที
  digitalWrite(RELAY_PIN_2, LOW);   // ปิด Relay 1
  digitalWrite(RELAY_PIN_3, LOW);
  digitalWrite(RELAY_PIN_4, LOW);   // ปิด Relay 2
  Serial.println("Relay 1 ON, Relay 2 OFF");  // แสดงสถานะรีเลย์
  delay(2000);  // รอ 2 วินาที

  // เปิด Relay 2 ทีละตัว
  digitalWrite(RELAY_PIN_2, HIGH);  // เปิด Relay 2
  delay(2000);  // รอ 2 วินาที
  digitalWrite(RELAY_PIN_1, LOW);
  digitalWrite(RELAY_PIN_3, LOW);   // ปิด Relay 2
  digitalWrite(RELAY_PIN_4, LOW);  // ปิด Relay 1 ค้างไว้
  Serial.println("Relay 2 ON, Relay 1 OFF");  // แสดงสถานะรีเลย์
  delay(5000);  // รอ 5 วินาที

  // เปิด Relay 3 และปิด Relay 4
  digitalWrite(RELAY_PIN_3, HIGH);  // เปิด Relay 3
  delay(2000);  // รอ 2 วินาที
  digitalWrite(RELAY_PIN_1, LOW);
  digitalWrite(RELAY_PIN_2, LOW);   // ปิด Relay 3
  digitalWrite(RELAY_PIN_4, LOW);   // ปิด Relay 4
  Serial.println("Relay 3 ON, Relay 4 OFF");  // แสดงสถานะรีเลย์
  delay(2000);  // รอ 2 วินาที

  // เปิด Relay 4 ทีละตัว
  digitalWrite(RELAY_PIN_4, HIGH);  // เปิด Relay 4
  delay(2000);  // รอ 2 วินาที
  digitalWrite(RELAY_PIN_1, LOW);   // ปิด Relay 4
  digitalWrite(RELAY_PIN_2, LOW);
  digitalWrite(RELAY_PIN_3, LOW);  // ปิด Relay 3 ค้างไว้
  Serial.println("Relay 4 ON, Relay 3 OFF");  // แสดงสถานะรีเลย์
  delay(5000);  // รอ 5 วินาที
}
