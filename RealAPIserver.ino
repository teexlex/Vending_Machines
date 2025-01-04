#include <WiFi.h>
#include <SocketIoClient.h>
#include <ArduinoJson.h>

const char* ssid = "Happytime";
const char* password = "AZ8597cool";

const char* host = "getapackpack.com";  // ชื่อโฮสต์
const uint16_t port = 443;              // พอร์ต HTTPS สำหรับ WSS
const char* url = "api/ws/";        // เส้นทางของ WebSocket

WiFiClientSecure wifiClient;
SocketIoClient socketIO;

//Event สำหรับ ส่ง ข้อมูลไป server 
///ส่งข้อมูลนี้เมื่อสินค้าออกจากช่องสินค้าแล้ว
void SenProduct_is_taken(){
  /// สร้าง JSON Document
  StaticJsonDocument<64> doc;
  doc["slotId"] = "1"; // กำหนดค่า slotId เป็น "ช่องสินค้า"

  /// แปลง JSON Document เป็นสตริง
  String jsonPayload;
  serializeJson(doc, jsonPayload);

  /// ส่งข้อมูลผ่าน socketIO.emit()
  socketIO.emit("product_is_taken", jsonPayload.c_str());

  Serial.println("✅ ส่งข้อมูล '1' ไปยัง Event 'product_is_taken'");
  Serial.print("📤 ข้อมูล JSON ที่ส่ง: ");
  Serial.println(jsonPayload);
}

// ส่งข้อมูลเมื่อพนักงานเติมช่องสินค้าแล้ว
void SenRefill_slot() {
  // สร้าง JSON Document
  StaticJsonDocument<64> doc;
  doc["slotId"] = "1"; // กำหนดค่า slotId เป็น "ช่องสินค้า"
  // แปลง JSON Document เป็นสตริง
  String jsonPayload;
  serializeJson(doc, jsonPayload);

  // ส่งข้อมูลผ่าน socketIO.emit()
  socketIO.emit("refill_slot", jsonPayload.c_str());
  
  // แสดงข้อความใน Serial Monitor
  Serial.println("ส่งข้อมูล '1' ไปยัง Event 'refill_slot'");
  Serial.print("ข้อมูล JSON ที่ส่ง: ");
  Serial.println(jsonPayload);
}

void SenChange_product_details(){
  StaticJsonDocument<200> doc; //สร้าง Json Document
  // ใส่ข้อมูลลงใน JSON
  doc["slotId"] = "1";
  doc["name"] = "minere";
  doc["description"] = "100ml 5bottles";
  doc["price"] = 500.50;
  doc["imageBuffer"] = "data.image";
  doc["brand_id"] = "select_brand_id";

  // แปลง JSON เป็นสตริง
  String jsonPayload;
  serializeJson(doc, jsonPayload);

  socketIO.emit("change_product_details",jsonPayload.c_str());
  Serial.println("ส่งข้อมูล JSON ไปยัง Event 'change_product_details'");
  Serial.print("ข้อมูลที่ส่ง: ");
  Serial.println(jsonPayload);
}

void SenAdd_new_brand(){
  StaticJsonDocument<64> doc;
  doc["name"] = "New Brand";
  String jsonPayload;
  serializeJson(doc, jsonPayload);
  socketIO.emit("Add_new_brand", jsonPayload.c_str());
  
  // แสดงข้อความใน Serial Monitor
  Serial.println("ส่งข้อมูล '1' ไปยัง Event 'Add_new_brand'");
  Serial.print("ข้อมูล JSON ที่ส่ง: ");
  Serial.println(jsonPayload);
}

//Event สำหรับ รับ ข้อมูลจาก server 
// ฟังก์ชันจัดการ Event ชื่อ "order_is_placed"
void onOrderIsPlaced(const char* payload, size_t length) {
  Serial.println("ได้รับ Event 'order_is_placed' จากเซิร์ฟเวอร์");

  // แสดงข้อมูลดิบที่ได้รับ
  Serial.print("ข้อมูลที่ได้รับ: ");
  Serial.println(payload);

  // แปลง JSON (ถ้าข้อมูลเป็น JSON)
  StaticJsonDocument<128> doc;
  DeserializationError error = deserializeJson(doc, payload);
  if (error) {
    Serial.print("JSON parse error: ");
    Serial.println(error.c_str());
    return;
  }

  // ดึงค่า slotId
  const char* slotId = doc["slotId"];
  if (slotId) {
    Serial.print("Slot ID: ");
    Serial.println(slotId);
  }
}
//ฟังชั่นจัดการ Event ชืื่ออ "Order is canceled"
void onOrder_is_canceled(const char* payload, size_t length){
  Serial.println("ได้รับ Event 'Order_is_canceled' จากเซิร์ฟเวอร์");

  // แสดงข้อมูลดิบที่ได้รับ
  Serial.print("ข้อมูลที่ได้รับ: ");
  Serial.println(payload);

  // แปลง JSON (ถ้าข้อมูลเป็น JSON)
  StaticJsonDocument<128> doc;
  DeserializationError error = deserializeJson(doc, payload);
  if (error) {
    Serial.print("JSON parse error: ");
    Serial.println(error.c_str());
    return;
  }

  // ดึงค่า slotId
  const char* slotId = doc["slotId"];
  if (slotId) {
    Serial.print("Slot ID: ");
    Serial.println(slotId);
  }
}

void onOrder_times_out(const char* payload, size_t length){
  Serial.println("ได้รับ Event 'order_times_out' จากเซิร์ฟเวอร์");

  // แสดงข้อมูลดิบที่ได้รับ
  Serial.print("ข้อมูลที่ได้รับ: ");
  Serial.println(payload);

  // แปลง JSON (ถ้าข้อมูลเป็น JSON)
  StaticJsonDocument<128> doc;
  DeserializationError error = deserializeJson(doc, payload);
  if (error) {
    Serial.print("JSON parse error: ");
    Serial.println(error.c_str());
    return;
  }

  // ดึงค่า slotId
  const char* slotId = doc["slotId"];
  if (slotId) {
    Serial.print("Slot ID: ");
    Serial.println(slotId);
  }
}

  // เชื่อมต่อ Wi-Fi
void checkWiFi() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("กำลังเชื่อมต่อ Wi-Fi ใหม่...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nเชื่อมต่อ Wi-Fi สำเร็จอีกครั้ง!");
  }
}

//เชื่อมต่อ Scoket
void checkWebSocket() {
  static unsigned long lastReconnectAttempt = 0;
  if (millis() - lastReconnectAttempt > 5000) { // ตรวจสอบทุก 5 วินาที
    lastReconnectAttempt = millis();
    Serial.println("กำลังเชื่อมต่อ WebSocket ใหม่...");
    socketIO.beginSSL(host, port, url); // พยายามเชื่อมต่อใหม่
  }
}

void setup() {
  Serial.begin(115200);
  checkWiFi();
  // ตั้งค่า WiFiClientSecure
  wifiClient.setInsecure();

  // เชื่อมต่อกับ WebSocket Server
  wifiClient.setInsecure();
  socketIO.beginSSL(host, port, url);
  Serial.println("เชื่อมต่อ WebSocket สำเร็จ!");

  // ลงทะเบียน Event handlers
  socketIO.on("connect", [](const char* payload, size_t length) {
    Serial.println("เชื่อมต่อกับเซิร์ฟเวอร์สำเร็จ!");
  });
  socketIO.on("order_is_placed", onOrderIsPlaced);
  socketIO.on("order_is_canceled", onOrder_is_canceled);

  // ส่งข้อมูล
  //SenProduct_is_taken();
  //SenRefill_slot();
  //SenChange_product_details();
  //SenAdd_new_brand();
}

void loop() {
   static bool initialized = false;
  if (!initialized) {
    Serial.println("ESP32 is running...");
    initialized = true;
  }
  delay(1000);
  // ฟัง Event ตลอดเวลา
  socketIO.loop();
  checkWiFi();
  checkWebSocket();
}
