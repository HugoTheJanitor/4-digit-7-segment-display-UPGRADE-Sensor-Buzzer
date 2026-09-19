# 4-Digit 7-Segment Distance Sensor with Buzzer

An Arduino Mega 2560 project that measures distance with an HC-SR04 ultrasonic sensor, displays the result in millimeters, and activates a buzzer at 200 mm or less.

The repository contains an Arduino IDE version for the real hardware and a pure C version for desktop simulation in Visual Studio Code.

## Features

- HC-SR04 distance measurement
- Four-digit multiplexed 7-segment output
- Measurement range limited to 0–9999 mm
- 1000 Hz warning tone at 200 mm or less
- Arduino/C++ hardware version
- Standard C desktop version

## Hardware

- Arduino Mega 2560
- HC-SR04 ultrasonic sensor
- Four-digit 7-segment display
- Buzzer
- Current-limiting resistors
- Breadboard and jumper wires

## Pin Configuration

| Component | Connection | Mega 2560 pin |
|---|---|---:|
| Display digit 1 | Digit select | A1 |
| Display digit 2 | Digit select | A2 |
| Display digit 3 | Digit select | A3 |
| Display digit 4 | Digit select | A4 |
| Display segments | A, B, C, D, E, F, G | 5–11 |
| HC-SR04 | TRIG | 22 |
| HC-SR04 | ECHO | 24 |
| Buzzer | Signal | 4 |

All modules must share a common ground.

## Project Structure

```text
.
├── ArduinoIDE/
│   └── 7-segment_display_counter_Sensor_Buzzer.ino
├── VisualStudioCode/
│   ├── Arduino.h
│   ├── Arduino.c
│   └── Buzzer_display_sensor.c
├── Photos/
├── .gitignore
├── LICENSE
└── README.md
```

## Arduino IDE Version

The `ArduinoIDE` sketch uses the real Arduino Core and should be uploaded to the Arduino Mega 2560.

1. Open the `.ino` file in Arduino IDE.
2. Select **Arduino Mega or Mega 2560**.
3. Select the correct serial port.
4. Compile and upload the sketch.

## Visual Studio Code C Version

The `VisualStudioCode` directory contains genuine standard C:

- `Arduino.h` contains C-compatible constants and function declarations.
- `Arduino.c` implements a desktop simulation of the Arduino functions.
- `Buzzer_display_sensor.c` contains the original project logic and `main()`.

The C version simulates the pins, sensor, display, and buzzer in the terminal. It does not control the physical Arduino board.

Compile it with GCC:

```bash
gcc -std=c11 -Wall -Wextra -pedantic Arduino.c Buzzer_display_sensor.c -o sensor_demo
```

Run it on Windows and pass the simulated distance in millimeters:

```powershell
.\sensor_demo.exe 150
```

On Linux or macOS:

```bash
./sensor_demo 150
```

Examples:

- `150` → buzzer on
- `350` → buzzer off
- no argument → uses 350 mm

## Why There Are C and C++ Versions

Arduino sketches are compiled as C++, even when their syntax looks mostly like C. The separate `.c` files are actual standard C and are counted by GitHub as C source code.

## License

This project is available under the [MIT License](LICENSE).
