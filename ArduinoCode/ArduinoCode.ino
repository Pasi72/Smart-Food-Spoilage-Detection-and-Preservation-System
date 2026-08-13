#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define EXHAUST_FAN_PIN 10
#define HEAT_SINK_FAN_PIN 9
#define PELTIER_PIN 8

#define BUZZER_PIN 7
#define LED1_PIN 6
#define LED2_PIN 5
#define LED3_PIN 4

DHT dht(DHTPIN, DHTTYPE);

unsigned long lastHumidityTime = 0;
const unsigned long humidityInterval = 500;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);   // Prevents command read from blocking too long
  dht.begin();

  pinMode(EXHAUST_FAN_PIN, OUTPUT);
  pinMode(HEAT_SINK_FAN_PIN, OUTPUT);
  pinMode(PELTIER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  digitalWrite(EXHAUST_FAN_PIN, LOW);
  digitalWrite(HEAT_SINK_FAN_PIN, LOW);
  digitalWrite(PELTIER_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
}

void loop() {
  // Read only one command per loop
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    handleCommand(command);
  }

  // Send humidity continuously
  if (millis() - lastHumidityTime >= humidityInterval) {
    lastHumidityTime = millis();

    float humidity = dht.readHumidity();

    if (!isnan(humidity)) {
      Serial.println(humidity);   // Only numeric output
    }
  }
}

void handleCommand(String command) {
  // Food status commands
  if (command == "FRESH") {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    delay(50);
    Serial.println("Fresh");
  }
  else if (command == "MODERATE") {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    delay(50);
    Serial.println("Moderate");
  }
  else if (command == "SPOILED") {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    Serial.println("Spoiled");
  }
  // Peltier and heatsink fan control commands
  else if (command == "COOLING_ON") {
    digitalWrite(PELTIER_PIN, HIGH);
    digitalWrite(HEAT_SINK_FAN_PIN, HIGH);
    delay(50);
    Serial.println("Cooling on");
  }
  else if (command == "COOLING_OFF") {
    digitalWrite(PELTIER_PIN, LOW);
    delay(5000);
    digitalWrite(HEAT_SINK_FAN_PIN, LOW);
    delay(50);
    Serial.println("Cooling off");
  }
  // Exhaust fan control commands
  else if (command == "EXHAUST_FAN_ON") {
    digitalWrite(EXHAUST_FAN_PIN, HIGH);
    delay(50);
    Serial.println("Exhaust fan on");
  }
  else if (command == "EXHAUST_FAN_OFF") {
    digitalWrite(EXHAUST_FAN_PIN, LOW);
    delay(50);
    Serial.println("Exhaust fan off");
  }
}
