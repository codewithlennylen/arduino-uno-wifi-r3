# UNO Blink (PlatformIO)

This example blinks the built-in LED on an Arduino Uno every 500 ms.

## Source Code

File: `src/main.cpp`

```cpp
#include <Arduino.h>

void setup() {
 pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
 digitalWrite(LED_BUILTIN, HIGH);
 delay(500);
 digitalWrite(LED_BUILTIN, LOW);
 delay(500);
}
```

## Code Walkthrough

- `#include <Arduino.h>`
 Loads Arduino core APIs such as `pinMode`, `digitalWrite`, and `delay`.
- `setup()`
 Runs once after reset. It sets the built-in LED pin as an output.
- `loop()`
 Runs forever.
 	- `digitalWrite(LED_BUILTIN, HIGH)` turns the LED on.
 	- `delay(500)` waits 500 ms.
 	- `digitalWrite(LED_BUILTIN, LOW)` turns the LED off.
 	- `delay(500)` waits another 500 ms.

This gives a 1 second blink cycle (0.5 s on + 0.5 s off).

## PlatformIO Configuration

File: `platformio.ini`

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
```

- `platform = atmelavr`: AVR toolchain/platform for Uno-class boards.
- `board = uno`: Compiles for Arduino Uno (ATmega328P).
- `framework = arduino`: Uses Arduino framework APIs.

## Build and Upload

From this folder (`1_uno_blink`):

```bash
platformio run
platformio run --target upload
```

In VS Code, the equivalent upload task is:

- **PlatformIO: Upload**

## Notes for UNO WiFi R3 Clone Boards

If your board is an Uno WiFi R3 clone with DIP switches and separate USB interfaces, use ATmega328 upload mode:

- DIP switch **3, 4 ON**
- DIP switch **1, 2, 5, 6, 7, 8 OFF**
- Select the correct serial/COM port before upload
- If upload stalls at the beginning, press the board reset button once, then retry

## Expected Behavior

After a successful upload, the onboard LED should blink continuously at 1 Hz.
