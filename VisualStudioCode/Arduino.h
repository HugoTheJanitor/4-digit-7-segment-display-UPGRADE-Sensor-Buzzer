#pragma once

using byte = unsigned char;

constexpr int LOW = 0;
constexpr int HIGH = 1;
constexpr int INPUT = 0;
constexpr int OUTPUT = 1;

constexpr int A1 = 55;
constexpr int A2 = 56;
constexpr int A3 = 57;
constexpr int A4 = 58;

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
void delay(unsigned long milliseconds);
void delayMicroseconds(unsigned int microseconds);
unsigned long pulseIn(int pin, int state, unsigned long timeout = 1000000UL);
void tone(int pin, unsigned int frequency);
void noTone(int pin);

class HardwareSerial {
public:
	void begin(unsigned long baudRate);
};

extern HardwareSerial Serial;
