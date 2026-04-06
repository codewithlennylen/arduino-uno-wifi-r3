# ESP8266 Wi-Fi Connect (PlatformIO)

This project runs on the ESP8266 side of an Arduino Uno WiFi R3 (ATmega328P + ESP8266 combo board) and connects the ESP8266 to a Wi-Fi network.

## What The Code Does

- Initializes Serial output in `setup()`.
- Connects to Wi-Fi in station mode.
- Waits up to 20 seconds for a successful connection.
- Prints the assigned local IP address when connected.
- Monitors connectivity in `loop()` and retries automatically if disconnected.
- Prints Wi-Fi signal strength (RSSI) every 10 seconds while connected.

## Source Code Overview

File: `src/main.cpp`

```cpp
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

	Serial.print("Wi-Fi connected, RSSI: ");
	Serial.print(WiFi.RSSI());
	Serial.println(" dBm");
	delay(10000);
}
```

## PlatformIO Configuration

File: `platformio.ini`

```ini
[env:esp12e]
platform = espressif8266
board = esp12e
framework = arduino
```

- `platform = espressif8266`: ESP8266 toolchain.
- `board = esp12e`: Generic ESP-12E profile used by this board's ESP8266 side.
- `framework = arduino`: Arduino APIs for ESP8266.

## Build, Upload, and Monitor

From this folder (`3_esp8266_wifi`):

```bash
platformio run
platformio run --target upload
platformio device monitor --baud 9600
```

## Uno WiFi R3 DIP Switch Notes (ESP8266 Programming)

For the common Uno WiFi R3 clone programming mode:

- Set DIP switch **5, 6, 7 ON**.
- Set DIP switch **1, 2, 3, 4, 8 OFF**.
- Press reset before upload if needed.
- After upload, set DIP switch **7 OFF** so the sketch can boot normally after reset.

## Sample Output