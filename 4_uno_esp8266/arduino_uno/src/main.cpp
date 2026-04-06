#include <Arduino.h>

const unsigned long BLINK_INTERVAL_MS = 500;

String commandBuffer;
bool blinkEnabled = false;
bool ledState = false;
unsigned long lastBlinkToggleMs = 0;

void applyCommand(const String &command) {
  if (command == "LED_ON") {
    blinkEnabled = false;
    ledState = true;
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("OK LED_ON");
    return;
  }

  if (command == "LED_OFF") {
    blinkEnabled = false;
    ledState = false;
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("OK LED_OFF");
    return;
  }

  if (command == "BLINK_START") {
    blinkEnabled = true;
    lastBlinkToggleMs = millis();
    Serial.println("OK BLINK_START");
    return;
  }

  if (command == "BLINK_STOP") {
    blinkEnabled = false;
    ledState = false;
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("OK BLINK_STOP");
    return;
  }

  Serial.print("ERR UNKNOWN_COMMAND: ");
  Serial.println(command);
}

void processSerialInput() {
  while (Serial.available() > 0) {
    const char c = static_cast<char>(Serial.read());

    if (c == '\n' || c == '\r') {
      if (commandBuffer.length() > 0) {
        commandBuffer.trim();
        applyCommand(commandBuffer);
        commandBuffer = "";
      }
      continue;
    }

    if (commandBuffer.length() < 64) {
      commandBuffer += c;
    }
  }
}

void updateBlink() {
  if (!blinkEnabled) {
    return;
  }

  const unsigned long now = millis();
  if (now - lastBlinkToggleMs >= BLINK_INTERVAL_MS) {
    lastBlinkToggleMs = now;
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  commandBuffer.reserve(64);
  Serial.println("UNO READY");
}

void loop() {
  processSerialInput();
  updateBlink();
}
