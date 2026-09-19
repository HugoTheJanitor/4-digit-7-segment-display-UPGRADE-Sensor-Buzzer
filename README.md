# 4-Digit 7-Segment Distance Sensor with Buzzer

An Arduino Mega 2560 project that measures distance with an HC-SR04 ultrasonic sensor, displays the result in millimeters, and activates a buzzer when an object is within 200 mm.

## Features

- Measures distance with the HC-SR04
- Displays values from 0 to 9999 mm
- Uses multiplexing for the four display digits
- Activates a 1000 Hz buzzer at 200 mm or less
- Includes Arduino IDE and Visual Studio Code versions

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
| Display digits | Digit 1, 2, 3, 4 | A1, A2, A3, A4 |
| Display segments | A, B, C, D, E, F, G | 5, 6, 7, 8, 9, 10, 11 |
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
│   └── Buzzer_display_sensor.cpp
├── Photos/
├── .gitignore
├── LICENSE
└── README.md
```

## Versions

### Arduino IDE

The `ArduinoIDE` folder contains the sketch used with the real Arduino Mega 2560.

### Visual Studio Code

The `VisualStudioCode` folder contains the same project logic in a `.cpp` file. The included `Arduino.h` is a small C-compatible learning header that declares the Arduino constants and functions used by the project.

The header helps explain what names such as `HIGH`, `LOW`, `pinMode()`, `digitalWrite()`, `pulseIn()`, and `tone()` represent. It is not a replacement for the complete Arduino Core.

## How It Works

1. The Arduino sends a 10 microsecond pulse through the HC-SR04 TRIG pin.
2. `pulseIn()` measures the returned ECHO pulse.
3. The pulse duration is converted to millimeters.
4. The number is divided into four digits and displayed using multiplexing.
5. At 200 mm or less, the buzzer produces a 1000 Hz tone.

If no echo is received within 30 milliseconds, the value is set to 9999.

## Uploading to Arduino

1. Open `ArduinoIDE/7-segment_display_counter_Sensor_Buzzer.ino`.
2. Select **Arduino Mega or Mega 2560**.
3. Select the correct serial port.
4. Compile and upload the sketch.

## License

This project is available under the [MIT License](LICENSE).
