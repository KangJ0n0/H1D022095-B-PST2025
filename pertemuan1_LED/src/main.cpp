#include <Arduino.h>

int merah = D0;
int kuning = D3;
int hijau = D4;

void setup() {
 pinMode(merah, OUTPUT);
 pinMode(kuning, OUTPUT);
 pinMode(hijau, OUTPUT);
}

void loop() {
  digitalWrite(merah, HIGH);
  delay(500);
  digitalWrite(merah, LOW);
  digitalWrite(kuning, HIGH);
  delay(500);
  digitalWrite(kuning, LOW);
  digitalWrite(hijau, HIGH);
  delay(500);
  digitalWrite(hijau, LOW);
  digitalWrite(kuning, HIGH);
  delay(500);
  digitalWrite(kuning, LOW);


}
