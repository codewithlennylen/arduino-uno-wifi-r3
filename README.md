# Arduino Uno Wifi R3 (ESP8266)

Arduino UNO WiFi R3 examples and tasks for the ATmega328P (UNO side) and ESP8266 (Wi-Fi side), organized as step-by-step PlatformIO projects.

## Workspace Overview

This repository is structured as a progression:

1. Blink on UNO
2. Blink on ESP8266
3. Connect ESP8266 to Wi-Fi
4. Full UNO + ESP8266 integration over serial with HTTP control

## Project Index (Start Here)

- [1_uno_blink](1_uno_blink/README.md): Basic LED blink on Arduino UNO.
- [2_esp8266_blink](2_esp8266_blink/README.md): Basic LED blink on ESP8266 GPIO2.
- [3_esp8266_wifi](3_esp8266_wifi/README.md): ESP8266 Wi-Fi connection and status logging.
- [4_uno_esp8266](4_uno_esp8266/README.md): Combined system where ESP8266 exposes HTTP endpoints and UNO executes LED commands.


## Repository Layout

```text
arduino-uno-wifi-r3/
├── 1_uno_blink/
│   ├── platformio.ini
│   ├── README.md
│   └── src/main.cpp
├── 2_esp8266_blink/
│   ├── platformio.ini
│   ├── README.md
│   └── src/main.cpp
├── 3_esp8266_wifi/
│   ├── platformio.ini
│   ├── README.md
│   └── src/main.cpp
├── 4_uno_esp8266/
│   ├── README.md
│   ├── arduino_uno/
│   │   ├── platformio.ini
│   │   ├── README.md
│   │   └── src/main.cpp
│   └── esp8266/
│       ├── platformio.ini
│       ├── README.md
│       └── src/main.cpp
├── LICENSE
└── README.md
```

## Tasks

1. Complete [1_uno_blink](1_uno_blink/README.md) to confirm UNO upload flow.
2. Complete [2_esp8266_blink](2_esp8266_blink/README.md) to confirm ESP8266 upload flow.
3. Complete [3_esp8266_wifi](3_esp8266_wifi/README.md) to validate Wi-Fi configuration.
4. Complete [4_uno_esp8266](4_uno_esp8266/README.md) for full dual-chip communication.

## Notes

- These projects target common UNO WiFi R3 clone boards with CH340G and 8-way DIP switches.
- DIP-switch programming/runtime modes are documented in each project README.
- Keep serial baud rates aligned between UNO and ESP8266 when using the integrated project.
