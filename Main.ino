#include "temperature.h"
#include "lcd.h"
#include "pubsub.h"

// create this file and define WIFI_SSID, WIFI_PASS
#include "wifi_credentials.h"

Temperature temperature(D3);
Lcd lcd;
PubSub *pubsub = new PubSub();
float targetTemperature = 18.0;
void connectWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  lcd.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  lcd.print("Connected");
}

void setup() {
  Serial.begin(115200);
  connectWifi();
  pubsub->connect();
  pinMode(D5, OUTPUT);
}

bool fanOn = false;
void checkTemp() {
  float temp = temperature.getTemp();
  if (!fanOn && temp > targetTemperature + 0.5) {
    fanOn = true;
    digitalWrite(D5, HIGH);
  } else if (fanOn && temp < targetTemperature - 0.5) {
    fanOn = false;
    digitalWrite(D5, LOW);
  }
}

void loop() {
  float temp = temperature.getTemp();
  Serial.println(temp);
  checkTemp();
  pubsub->sendTemp(temp);
  lcd.print(temp, targetTemperature, fanOn);

  delay(10000);
}
