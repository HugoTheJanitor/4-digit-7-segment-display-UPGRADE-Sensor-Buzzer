#include "Arduino.h"

#include <stdio.h>
#include <stdlib.h>

int digitPins[] = {A1, A2, A3, A4};
int segmentPins[] = {5, 6, 7, 8, 9, 10, 11};

int numbers[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

const int TRIG_PIN = 22;
const int ECHO_PIN = 24;
const int BUZZER_PIN = 4;

int distanceMm = 0;

int getDistance(void);
void displayNumber(int number);
void setup(void);
void loop(void);

void setup(void) {
    int i;

    for (i = 0; i < 4; i++) {
        pinMode(digitPins[i], OUTPUT);
        digitalWrite(digitPins[i], HIGH);
    }

    for (i = 0; i < 7; i++) {
        pinMode(segmentPins[i], OUTPUT);
        digitalWrite(segmentPins[i], LOW);
    }

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    serialBegin(9600);
}

void loop(void) {
    distanceMm = getDistance();

    if (distanceMm > 9999) {
        distanceMm = 9999;
    }

    if (distanceMm < 0) {
        distanceMm = 0;
    }

    displayNumber(distanceMm);
    printf("Displayed distance: %d mm\n", distanceMm);

    if (distanceMm <= 200) {
        tone(BUZZER_PIN, 1000);
    } else {
        noTone(BUZZER_PIN);
    }
}

int getDistance(void) {
    unsigned long duration;
    int distance;

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH, 30000UL);

    if (duration == 0) {
        return 9999;
    }

    distance = (int)(duration * 343UL / 2000UL);
    return distance;
}

void displayNumber(int number) {
    int digits[4];
    int i;
    int j;
    int k;

    digits[0] = number / 1000;
    digits[1] = (number / 100) % 10;
    digits[2] = (number / 10) % 10;
    digits[3] = number % 10;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            digitalWrite(digitPins[j], HIGH);
        }

        for (k = 0; k < 7; k++) {
            digitalWrite(segmentPins[k], numbers[digits[i]][k]);
        }

        digitalWrite(digitPins[i], LOW);
        delay(1);
        digitalWrite(digitPins[i], HIGH);
    }
}

int main(int argc, char *argv[]) {
    long requestedDistance = 350;

    if (argc > 1) {
        requestedDistance = strtol(argv[1], NULL, 10);
    }

    if (requestedDistance > 9999) {
        requestedDistance = 9999;
    }

    setSimulatedDistanceMm((int)requestedDistance);
    setup();
    loop();

    return 0;
}
