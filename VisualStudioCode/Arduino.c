#include "Arduino.h"

#include <stdio.h>

static int simulatedDistanceMm = 350;

void pinMode(int pin, int mode) {
    (void)pin;
    (void)mode;
}

void digitalWrite(int pin, int value) {
    (void)pin;
    (void)value;
}

void delay(unsigned long milliseconds) {
    (void)milliseconds;
}

void delayMicroseconds(unsigned int microseconds) {
    (void)microseconds;
}

unsigned long pulseIn(int pin, int state, unsigned long timeout) {
    unsigned long duration;

    (void)pin;
    (void)state;

    if (simulatedDistanceMm < 0) {
        return 0;
    }

    duration = ((unsigned long)simulatedDistanceMm * 2000UL + 171UL) / 343UL;

    if (duration > timeout) {
        return 0;
    }

    return duration;
}

void tone(int pin, unsigned int frequency) {
    printf("Buzzer on: pin %d, %u Hz\n", pin, frequency);
}

void noTone(int pin) {
    printf("Buzzer off: pin %d\n", pin);
}

void serialBegin(unsigned long baudRate) {
    printf("Serial started at %lu baud\n", baudRate);
}

void setSimulatedDistanceMm(int distanceMm) {
    simulatedDistanceMm = distanceMm;
}
