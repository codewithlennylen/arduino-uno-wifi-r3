#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char *WIFI_SSID = "YOUR_WIFI_SSID";
const char *WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

const unsigned long UNO_REPLY_TIMEOUT_MS = 500;

String sendUnoCommand(const char *command) {
  while (Serial.available() > 0) {
    Serial.read();
  }

  Serial.println(command);

  const unsigned long start = millis();
  String response;

  while (millis() - start < UNO_REPLY_TIMEOUT_MS) {
    while (Serial.available() > 0) {
      const char c = static_cast<char>(Serial.read());
      if (c == '\n' || c == '\r') {
        if (response.length() > 0) {
          response.trim();
          return response;
        }
      } else {
        response += c;
      }
    }
  }

  return "ERR UNO_TIMEOUT";
}

void handleRoot() {
  String body;
  body.reserve(220);
  body += "UNO LED Control\\n";
  body += "GET /led/on\\n";
  body += "GET /led/off\\n";
  body += "GET /blink/start\\n";
  body += "GET /blink/stop\\n";
  server.send(200, "text/plain", body);
}

void handleLedOn() {
  server.send(200, "text/plain", sendUnoCommand("LED_ON"));
}

void handleLedOff() {
  server.send(200, "text/plain", sendUnoCommand("LED_OFF"));
}

void handleBlinkStart() {
  server.send(200, "text/plain", sendUnoCommand("BLINK_START"));
}

void handleBlinkStop() {
  server.send(200, "text/plain", sendUnoCommand("BLINK_STOP"));
}

void connectToWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void setup() {
  Serial.begin(9600);
  delay(200);

  connectToWifi();

  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);
  server.on("/blink/start", handleBlinkStart);
  server.on("/blink/stop", handleBlinkStop);

  server.begin();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectToWifi();
  }

  server.handleClient();
}
