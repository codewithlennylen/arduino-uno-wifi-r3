# Arduino Uno Wifi R3 (ESP8266)

<img width="1920" height="1080" alt="Screenshot from 2026-04-02 23-31-08" src="https://github.com/user-attachments/assets/9e8f5dc1-1981-417c-80f9-9796ce95d956" />

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

### 8-way DIP switch guide

<img width="1920" height="1080" alt="Screenshot from 2026-04-02 23-32-01" src="https://github.com/user-attachments/assets/4c1f0aed-5b8a-4dfc-978c-f13615bda5a4" />

<img width="1920" height="1080" alt="Screenshot from 2026-04-02 23-34-12" src="https://github.com/user-attachments/assets/68212c06-3bc5-4b3b-a023-ae3bf8e7abe0" />

<img width="1920" height="1080" alt="Screenshot from 2026-04-02 23-34-43" src="https://github.com/user-attachments/assets/a06bc5c5-1b97-4e35-aba2-1d6b14029ff6" />


## Reference Tutorial

[UNO+WiFi R3 ATmega328P + ESP8266 Module 32Mb Memory USB TTL CH340G ❤❤ Easy Tutorial Step By Step ❤❤](https://youtu.be/AM83Q5dXVwI?list=TLPQMDQwNDIwMjZm97ak_Lv49g)
