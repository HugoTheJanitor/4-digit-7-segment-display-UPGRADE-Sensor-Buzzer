#include "Arduino.h"

// HC-SR04 + 4-digit 7-segment display
// Arduino Mega 2560

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

int getDistance();
void displayNumber(int number);

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH);
  }

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  serialBegin(9600);
}

void loop() {
  distanceMm = getDistance();

  if (distanceMm > 9999) {
    distanceMm = 9999;
  }

  if (distanceMm < 0) {
    distanceMm = 0;
  }

  displayNumber(distanceMm);

  if (distanceMm <= 200) {
    tone(BUZZER_PIN, 1000);
  } else {
    noTone(BUZZER_PIN);
  }
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return 9999;
  }

  int distance = duration * 343 / 2000;
  return distance;
}

void displayNumber(int number) {
  int digits[4];

  digits[0] = number / 1000;
  digits[1] = (number / 100) % 10;
  digits[2] = (number / 10) % 10;
  digits[3] = number % 10;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      digitalWrite(digitPins[j], HIGH);
    }

    for (int k = 0; k < 7; k++) {
      digitalWrite(segmentPins[k], numbers[digits[i]][k]);
    }

    digitalWrite(digitPins[i], LOW);
    delay(1);
    digitalWrite(digitPins[i], HIGH);
  }
}
