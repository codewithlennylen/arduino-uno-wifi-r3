# Arduino UNO Task

This firmware runs on the ATmega328P (Arduino UNO side) and controls the built-in LED based on serial commands received from ESP8266.

## PlatformIO Config

`platformio.ini`

```ini
[env:uno]
platform = atmelavr
board = uno
framework = arduino
monitor_speed = 9600
```

## Supported Serial Commands

Send one command per line (`\n`):

- `LED_ON` -> turn built-in LED on, reply: `OK LED_ON`
- `LED_OFF` -> turn built-in LED off, reply: `OK LED_OFF`
- `BLINK_START` -> start 500 ms interval blink, reply: `OK BLINK_START`
- `BLINK_STOP` -> stop blink and force LED off, reply: `OK BLINK_STOP`
- unknown command -> reply: `ERR UNKNOWN_COMMAND: <command>`

## Behavior

- Uses `LED_BUILTIN` pin.
- Uses non-blocking blink timing with `millis()`.
- Prints `UNO READY` once on startup.

## Build and Upload

From this folder:

```bash
platformio run
platformio run --target upload
```
