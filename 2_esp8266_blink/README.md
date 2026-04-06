# ESP8266 Blink (PlatformIO)

This example blinks an LED connected to ESP8266 GPIO2 every 1 second.

## Source Code

File: `src/main.cpp`

```cpp
#include <Arduino.h>

void setup() {
 pinMode(2, OUTPUT);
}

void loop() {
 digitalWrite(2, HIGH);
 delay(1000);
 digitalWrite(2, LOW);
 delay(1000);
}
```

## Code Walkthrough

- `#include <Arduino.h>`
 Imports Arduino core APIs for ESP8266 (`pinMode`, `digitalWrite`, `delay`).
- `setup()`
 Runs once at startup and configures GPIO2 as an output pin.
- `loop()`
 Repeats forever.
 	- Writes `HIGH` to GPIO2 (LED on for most modules).
 	- Waits 1000 ms.
 	- Writes `LOW` to GPIO2 (LED off for most modules).
 	- Waits 1000 ms.

This creates a 2 second blink period (1 s on + 1 s off).

## PlatformIO Configuration

File: `platformio.ini`

```ini
[env:esp12e]
platform = espressif8266
board = esp12e
framework = arduino
```

- `platform = espressif8266`: ESP8266 toolchain/platform.
- `board = esp12e`: Generic ESP-12E/ESP8266 module profile.
- `framework = arduino`: Arduino APIs on ESP8266.

## Build and Upload

From this folder (`2_esp8266_blink`):

```bash
platformio run
platformio run --target upload
```

In VS Code, the equivalent task is:

- **PlatformIO: Upload**

## Arduino Uno WiFi R3 (ESP8266 Side) Notes

For boards with ATmega328P + ESP8266 and DIP switches:

- For ESP8266 programming mode, set DIP switch **5, 6, 7 ON**.
- Set DIP switch **1, 2, 3, 4, 8 OFF**.
- Select the correct serial/COM port.
- Press reset before uploading if needed.
- After upload, set DIP switch **7 OFF** so the sketch persists across reboot.

## Reference

<img width="1920" height="1080" alt="Screenshot from 2026-04-02 23-38-35" src="https://github.com/user-attachments/assets/513dc269-5c56-4ed3-8db1-b3426bc93aea" />
