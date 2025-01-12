#include <Wire.h>
#include <Adafruit_MCP23017.h>

Adafruit_MCP23017 mcp;

void setup() {
  Serial.begin(115200);       
  Wire.begin();               
  mcp.begin(0);               


  for (int i = 0; i < 16; i++) {
    mcp.pinMode(i, OUTPUT);
    mcp.digitalWrite(i, HIGH);
  }

  Serial.println("MCP23017 พร้อมใช้งาน!");
}

void loop() {

  Serial.println("เปิด Relay 1");
  mcp.digitalWrite(0, LOW); 
  delay(1000);

  Serial.println("เปิด Relay 2");
  mcp.digitalWrite(1, LOW); 
  delay(1000);

  Serial.println("ปิด Relay 1 และ Relay 2");
  mcp.digitalWrite(0, HIGH); 
  mcp.digitalWrite(1, HIGH);
  delay(1000);

  for (int i = 2; i < 16; i++) {
    Serial.print("เปิด Relay ");
    Serial.println(i + 1);
    mcp.digitalWrite(i, LOW);
    delay(500);
  }

  for (int i = 2; i < 16; i++) {
    Serial.print("ปิด Relay ");
    Serial.println(i + 1);
    mcp.digitalWrite(i, HIGH);
    delay(500);
  }
}
