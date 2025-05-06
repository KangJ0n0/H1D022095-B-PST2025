#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D2;
int SCL_pin = D1;

void setup()
{
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  Serial.begin(9600);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("HLO WORLD!");
  lcd.setCursor(0,1);
  lcd.print("HALO");
}

void loop()
{
}