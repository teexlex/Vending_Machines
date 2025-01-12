#define RELAY1 32
#define RELAY2 33
#define RELAY3 25
#define RELAY4 26
#define RELAY5 27
#define RELAY6 14
#define RELAY7 12
#define RELAY8 13
#define RELAY9 19
#define RELAY10 18
#define RELAY11 5
#define RELAY12 17
#define RELAY13 16
#define RELAY14 4
#define RELAY15 2
#define RELAY16 15

void setup() {
  Serial.begin(115200);

  // Set relay pins as OUTPUT
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  pinMode(RELAY5, OUTPUT);
  pinMode(RELAY6, OUTPUT);
  pinMode(RELAY7, OUTPUT);
  pinMode(RELAY8, OUTPUT);
  pinMode(RELAY9, OUTPUT);
  pinMode(RELAY10, OUTPUT);
  pinMode(RELAY11, OUTPUT);
  pinMode(RELAY12, OUTPUT);
  pinMode(RELAY13, OUTPUT);
  pinMode(RELAY14, OUTPUT);
  pinMode(RELAY15, OUTPUT);
  pinMode(RELAY16, OUTPUT);

  // Turn off all relays
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  digitalWrite(RELAY5, HIGH);
  digitalWrite(RELAY6, HIGH);
  digitalWrite(RELAY7, HIGH);
  digitalWrite(RELAY8, HIGH);
  digitalWrite(RELAY9, HIGH);
  digitalWrite(RELAY10, HIGH);
  digitalWrite(RELAY11, HIGH);
  digitalWrite(RELAY12, HIGH);
  digitalWrite(RELAY13, HIGH);
  digitalWrite(RELAY14, HIGH);
  digitalWrite(RELAY15, HIGH);
  digitalWrite(RELAY16, HIGH);
}

void loop() {
  // Turn on all relays one by one
  digitalWrite(RELAY1, LOW);
  delay(500);
  digitalWrite(RELAY2, LOW);
  delay(500);
  digitalWrite(RELAY3, LOW);
  delay(500);
  digitalWrite(RELAY4, LOW);
  delay(500);
  digitalWrite(RELAY5, LOW);
  delay(500);
  digitalWrite(RELAY6, LOW);
  delay(500);
  digitalWrite(RELAY7, LOW);
  delay(500);
  digitalWrite(RELAY8, LOW);
  delay(500);
  digitalWrite(RELAY9, LOW);
  delay(500);
  digitalWrite(RELAY10, LOW);
  delay(500);
  digitalWrite(RELAY11, LOW);
  delay(500);
  digitalWrite(RELAY12, LOW);
  delay(500);
  digitalWrite(RELAY13, LOW);
  delay(500);
  digitalWrite(RELAY14, LOW);
  delay(500);
  digitalWrite(RELAY15, LOW);
  delay(500);
  digitalWrite(RELAY16, LOW);
  delay(500);

  // Turn off all relays
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);
  digitalWrite(RELAY5, HIGH);
  digitalWrite(RELAY6, HIGH);
  digitalWrite(RELAY7, HIGH);
  digitalWrite(RELAY8, HIGH);
  digitalWrite(RELAY9, HIGH);
  digitalWrite(RELAY10, HIGH);
  digitalWrite(RELAY11, HIGH);
  digitalWrite(RELAY12, HIGH);
  digitalWrite(RELAY13, HIGH);
  digitalWrite(RELAY14, HIGH);
  digitalWrite(RELAY15, HIGH);
  digitalWrite(RELAY16, HIGH);
  delay(1000);
}
