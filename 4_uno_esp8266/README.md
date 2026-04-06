# UNO + ESP8266 Wi-Fi LED Control

This project controls the Arduino UNO built-in LED over Wi-Fi by using the onboard ESP8266 as a network bridge.

## Folder Layout

- `arduino_uno/`: Arduino UNO firmware (ATmega328P)
- `esp8266/`: ESP8266 firmware (Wi-Fi + HTTP API)

## How It Works

1. A client sends an HTTP request to ESP8266.
2. ESP8266 translates the request into a serial command.
3. ESP8266 sends the command to UNO over UART.
4. UNO executes LED action and replies with status.
5. ESP8266 returns UNO status in HTTP response.

## Command/API Mapping

- `GET /led/on` -> `LED_ON`
- `GET /led/off` -> `LED_OFF`
- `GET /blink/start` -> `BLINK_START`
- `GET /blink/stop` -> `BLINK_STOP`

## Build and Upload

Upload each firmware from its own folder:

```bash
cd arduino_uno
platformio run --target upload

cd ../esp8266
platformio run --target upload
```

## Runtime Notes

- Use the correct DIP switch modes for programming each chip.
- After flashing, set DIP switches to runtime UART communication mode between ESP8266 and UNO.
- The ESP8266 serial speed and UNO serial speed must match (both set to 9600 in this project).
