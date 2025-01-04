#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid     = "Happytime";    // ชื่อ WiFi
const char* password = "AZ8597cool";   // รหัสผ่าน WiFi

WiFiUDP udp;
const char* ntpServer = "pool.ntp.org";   // NTP Server
const int timeZone = 7;                   // GMT+7 (เวลาประเทศไทย)

unsigned int localPort = 2390;            // Local UDP port
byte packetBuffer[48];                    // NTP packet buffer

const int relayPin = 23;                  // ขารีเลย์เปลี่ยนเป็น GPIO 23

void setup() {
  Serial.begin(115200);

  // เชื่อมต่อ Wi-Fi
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);

  int retries = 0; 
  while (WiFi.status() != WL_CONNECTED && retries < 20) { 
    delay(500);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi connected successfully!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to Wi-Fi. Please check your credentials.");
    while (1);
  }

  udp.begin(localPort);
  Serial.println("Started UDP. Ready to get NTP time.");

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
}

void loop() {
  unsigned long currentEpoch = getNTPTime();

  if (currentEpoch > 0) {
    int hours = (currentEpoch % 86400L) / 3600 + timeZone;
    int minutes = (currentEpoch % 3600) / 60;

    if (hours >= 24) hours -= 24;

    Serial.print("Current Time: ");
    Serial.print(hours);
    Serial.print(":");
    Serial.println(minutes);

    // ตรวจสอบเวลา 19:05 - 19:10
    if (hours == 19 && minutes >= 5 && minutes < 10) {
      digitalWrite(relayPin, HIGH);
      Serial.println("เปิดไฟ 12V Strip");
    } else {
      digitalWrite(relayPin, LOW);
      Serial.println("ปิดไฟ 12V Strip");
    }
  } else {
    Serial.println("Failed to get NTP time.");
  }

  delay(1000);
}

unsigned long getNTPTime() {
  memset(packetBuffer, 0, 48);
  packetBuffer[0] = 0b11100011;

  udp.beginPacket(ntpServer, 123);
  udp.write(packetBuffer, 48);
  udp.endPacket();

  delay(1000);
 
  if (udp.parsePacket()) {
    udp.read(packetBuffer, 48);
    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    const unsigned long seventyYears = 2208988800UL;

    Serial.println("NTP time retrieved successfully.");
    return secsSince1900 - seventyYears;
  }
  Serial.println("NTP time retrieval failed.");
  return 0;
}
