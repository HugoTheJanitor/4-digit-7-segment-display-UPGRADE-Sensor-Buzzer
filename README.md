# 4-Digit 7-Segment Distance Sensor with Buzzer

An Arduino Mega 2560 project that measures distance with an HC-SR04 ultrasonic sensor, shows the result in millimeters on a four-digit 7-segment display, and activates a buzzer when an object is within 200 mm.

## Features

- Measures distance with the HC-SR04 ultrasonic sensor
- Displays values from 0 to 9999 mm
- Uses multiplexing to control the four display digits
- Activates a 1000 Hz buzzer signal at distances of 200 mm or less
- Includes an Arduino IDE sketch and a Visual Studio Code version

## Hardware

- Arduino Mega 2560
- HC-SR04 ultrasonic distance sensor
- Four-digit 7-segment display
- Buzzer
- Current-limiting resistors for the display segments
- Breadboard and jumper wires

## Pin Configuration

| Component | Connection | Arduino Mega 2560 pin |
|---|---|---:|
| Display digit 1 | Digit select | A1 |
| Display digit 2 | Digit select | A2 |
| Display digit 3 | Digit select | A3 |
| Display digit 4 | Digit select | A4 |
| Display segments | A, B, C, D, E, F, G | 5, 6, 7, 8, 9, 10, 11 |
| HC-SR04 | TRIG | 22 |
| HC-SR04 | ECHO | 24 |
| Buzzer | Signal | 4 |

Connect all modules to a common ground.

## How It Works

1. The Arduino sends a 10 microsecond trigger pulse to the HC-SR04.
2. The sensor returns an echo pulse whose duration represents the travel time of the sound.
3. The program converts that duration to distance in millimeters.
4. The value is split into four digits and displayed using multiplexing.
5. When the measured distance is 200 mm or less, the buzzer produces a 1000 Hz tone.

If no echo is received within 30 milliseconds, the displayed value is set to 9999.

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

- `ArduinoIDE/` contains the sketch intended for uploading to the Arduino Mega 2560.
- `VisualStudioCode/` contains the C++ source and a lightweight Arduino declaration header for editing and code analysis.
- `Photos/` is reserved for photographs and wiring images of the completed project.

## Running the Project

1. Assemble the circuit according to the pin configuration above.
2. Open `ArduinoIDE/7-segment_display_counter_Sensor_Buzzer.ino` in Arduino IDE.
3. Select **Arduino Mega or Mega 2560** as the board.
4. Select the correct serial port.
5. Compile and upload the sketch.
6. Move an object in front of the HC-SR04 and observe the displayed distance and buzzer response.

## License

This project is available under the [MIT License](LICENSE).
