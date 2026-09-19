#include <Arduino.h>
// HC-SR04 + 4-digit 7-segment display
// Arduino Mega 2560

// ===== 7-segment display =====

int digitPins[] = {A1, A2, A3, A4};
int segmentPins[] = {5, 6, 7, 8, 9, 10, 11};

// {A, B, C, D, E, F, G}
int numbers[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};


// ===== HC-SR04 =====

const int TRIG_PIN = 22;
const int ECHO_PIN = 24;


// ===== Buzzer =====

const int BUZZER_PIN = 4;


// ===== Distance =====

int distanceMm = 0;


void setup() {

  // Display
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH);
  }

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  // HC-SR04
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Buzzer
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}


void loop() {

  // Измеряем расстояние
  distanceMm = getDistance();

  // Ограничиваем диапазон 0–9999 мм
  if (distanceMm > 9999) {
    distanceMm = 9999;
  }

  if (distanceMm < 0) {
    distanceMm = 0;
  }


  // Показываем расстояние
  displayNumber(distanceMm);


  // Пищалка, если рука ближе 200 мм
  if (distanceMm <= 200) {
    tone(BUZZER_PIN, 1000);
  }
  else {
    noTone(BUZZER_PIN);
  }
}


// ===== HC-SR04 =====

int getDistance() {

  // Отправляем ультразвуковой импульс
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);


  // Получаем время возвращения сигнала
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);


  // Если сигнал не получен
  if (duration == 0) {
    return 9999;
  }


  // Перевод времени в миллиметры
  int distance = duration * 343 / 2000;

  return distance;
}


// ===== Display =====

void displayNumber(int number) {

  int digits[4];

  digits[0] = number / 1000;
  digits[1] = (number / 100) % 10;
  digits[2] = (number / 10) % 10;
  digits[3] = number % 10;


  for (int i = 0; i < 4; i++) {

    // Выключаем все разряды
    for (int j = 0; j < 4; j++) {
      digitalWrite(digitPins[j], HIGH);
    }


    // Устанавливаем сегменты
    for (int k = 0; k < 7; k++) {
      digitalWrite(
        segmentPins[k],
        numbers[digits[i]][k]
      );
    }


    // Включаем текущий разряд
    digitalWrite(digitPins[i], LOW);

    delay(1);

    // Выключаем
    digitalWrite(digitPins[i], HIGH);
  }
}
