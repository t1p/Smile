#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // подставь свой адрес

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Hello!");
}

void loop() {}
