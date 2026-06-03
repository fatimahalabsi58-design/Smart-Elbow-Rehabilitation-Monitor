#include <LiquidCrystal.h>

// Smart Elbow Rehabilitation Monitor
// Arduino Uno + HC-SR04 + LCD 16x2 + RGB LED + Buzzer

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 13, 5, 4, 3, 2);

// LCD contrast: V0 -> D6
const int contrastPin = 6;

// Ultrasonic sensor
const int trigPin = 10;
const int echoPin = 11;

// RGB LED
const int redPin = A0;
const int greenPin = A1;
const int bluePin = A2;

// Buzzer
const int buzzerPin = A3;

// Repetition counter
int reps = 0;
bool flexionReached = false;

float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000);

  if (duration == 0) {
    return -1;
  }

  return duration * 0.0343 / 2;
}

void setColor(int r, int g, int b) {
  digitalWrite(redPin, r);
  digitalWrite(greenPin, g);
  digitalWrite(bluePin, b);
}

void beep() {
  tone(buzzerPin, 1000);
  delay(150);
  noTone(buzzerPin);
}

void setup() {
  Serial.begin(9600);

  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, 75);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(buzzerPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Rehab Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1200);
  lcd.clear();
}

void loop() {
  float distance = readDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reps: ");
  lcd.print(reps);

  lcd.setCursor(0, 1);

  if (distance >= 2 && distance <= 5) {
    setColor(LOW, HIGH, LOW);
    lcd.print("Flexion OK");

    if (!flexionReached) {
      flexionReached = true;
      beep();
    }
  }
  else if (distance >= 45 && distance <= 55) {
    setColor(LOW, HIGH, LOW);
    lcd.print("Extension OK");

    if (flexionReached) {
      reps++;
      flexionReached = false;
      beep();
    }
  }
  else if (distance >= 14 && distance <= 25) {
    setColor(LOW, LOW, HIGH);
    lcd.print("Middle Range");
  }
  else {
    setColor(HIGH, LOW, LOW);
    lcd.print("Out of Range");
  }

  delay(250);
}
