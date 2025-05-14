#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonik soalnya I2C ga perlu init Digital"kayaknya"
const int trigPin = D1;
const int echoPin = D2;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();         
  lcd.backlight();     
  lcd.setCursor(0, 0);
  lcd.print("   SHIELD URGENT OPS   ");
  delay(2000);
  lcd.clear();
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // sinyal sensor
  long duration = pulseIn(echoPin, HIGH);
  // hitung jarak
  float distance = duration * 0.034 / 2;

  // tampil di lcd
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance, 1);
  lcd.print(" cm    ");

  // output status
  lcd.setCursor(0, 1);
  if (distance < 100.0) {
    lcd.print("AREA BERBAHAYA ");
  } else {
    lcd.print("AMAN            ");
  }

  delay(500); 
}
