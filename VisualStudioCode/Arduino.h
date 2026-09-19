#ifndef ARDUINO_H
#define ARDUINO_H

typedef unsigned char byte;

#define LOW 0
#define HIGH 1
#define INPUT 0
#define OUTPUT 1

#define A1 55
#define A2 56
#define A3 57
#define A4 58

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
void delay(unsigned long milliseconds);
void delayMicroseconds(unsigned int microseconds);
unsigned long pulseIn(int pin, int state, unsigned long timeout);
void tone(int pin, unsigned int frequency);
void noTone(int pin);
void serialBegin(unsigned long baudRate);

#endif
