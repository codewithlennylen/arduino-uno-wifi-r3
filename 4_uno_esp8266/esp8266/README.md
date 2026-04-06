# ESP8266 Task

This firmware runs on the ESP8266 side and exposes a simple HTTP API to control the UNO built-in LED over serial.

## PlatformIO Config

`platformio.ini`

```ini
[env:esp12e]
platform = espressif8266
board = esp12e
framework = arduino
monitor_speed = 9600
```

## Setup

Edit Wi-Fi credentials in `src/main.cpp`:

- `WIFI_SSID`
- `WIFI_PASSWORD`

## HTTP Endpoints

All endpoints are `GET`:

- `/` -> endpoint list/help
- `/led/on` -> sends `LED_ON` to UNO
- `/led/off` -> sends `LED_OFF` to UNO
- `/blink/start` -> sends `BLINK_START` to UNO
- `/blink/stop` -> sends `BLINK_STOP` to UNO

## Example curl Commands

Replace `<ESP_IP>` with your ESP8266 local IP address.

```bash
curl http://<ESP_IP>/
curl http://<ESP_IP>/led/on
curl http://<ESP_IP>/led/off
curl http://<ESP_IP>/blink/start
curl http://<ESP_IP>/blink/stop
```

## Build and Upload

From this folder:

```bash
platformio run
platformio run --target upload
platformio device monitor --baud 9600
```

## Notes

- Waits for UNO response up to 500 ms (`UNO_REPLY_TIMEOUT_MS`).
- Returns UNO reply body directly in HTTP response.
- Keep ESP and UNO UART baud rates aligned at 9600.
