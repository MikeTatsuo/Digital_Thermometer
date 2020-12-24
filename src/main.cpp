#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 20, 4);

float Celsius, Farenheit;

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Digital Thermometer");
  
  lcd.setCursor(0, 2);
  lcd.print("Celsius: ");

  lcd.setCursor(0, 3);
  lcd.print("Farenheit: ");
}

void loop() {
  sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Farenheit = sensors.getTempFByIndex(0);

  lcd.setCursor(9, 2);
  lcd.print(Celsius);

  lcd.setCursor(11, 3);
  lcd.print(Farenheit);
}