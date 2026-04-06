#include <Arduino.h>
#include <ESP8266WiFi.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";
const char *WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

const unsigned long WIFI_CONNECT_TIMEOUT_MS = 20000;
const unsigned long WIFI_RETRY_DELAY_MS = 5000;

void connectToWifi() {
  Serial.printf("\nConnecting to Wi-Fi SSID: %s\n", WIFI_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  const unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < WIFI_CONNECT_TIMEOUT_MS) {
    delay(500);
    Serial.print('.');
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWi-Fi connect timeout");
  }
}

void setup() {
  Serial.begin(9600);
  delay(200);

  connectToWifi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi disconnected, retrying...");
    WiFi.disconnect();
    connectToWifi();
    delay(WIFI_RETRY_DELAY_MS);
    return;
  }

  // Print RSSI every 10 seconds while connected.
  Serial.print("Wi-Fi connected, RSSI: ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
  delay(10000);
}