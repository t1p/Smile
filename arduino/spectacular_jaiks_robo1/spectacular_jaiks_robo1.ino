// Переделанный скетч под LiquidCrystal_I2C с адресом 0x27
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // адрес дисплея, 16 символов, 2 строки

int bad = -1;
int soso = -1;
int good = -1;

int buttonState = 0;

void setup() {
  pinMode(2, INPUT);    // кнопка "bad"
  pinMode(7, INPUT);    // кнопка "soso"
  pinMode(12, INPUT);   // кнопка "good"

  pinMode(LED_BUILTIN, OUTPUT); // LED встроенный
  pinMode(4, OUTPUT);    // LED для "soso"
  pinMode(8, OUTPUT);    // LED для "good"

  lcd.init();            // инициализация
  lcd.backlight();       // включить подсветку

  lcd.setCursor(1, 0);
  lcd.print("bad");
  lcd.setCursor(5, 0);
  lcd.print("soso");
  lcd.setCursor(10, 0);
  lcd.print("good");
}

void loop() {
  // BAD
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    bad++;
    lcd.setCursor(1, 1);
    lcd.print(bad);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  // SOSO
  buttonState = digitalRead(7);
  if (buttonState == HIGH) {
    soso++;
    lcd.setCursor(5, 1);
    lcd.print(soso);
    digitalWrite(4, HIGH);
    delay(500);
  } else {
    digitalWrite(4, LOW);
  }

  // GOOD
  buttonState = digitalRead(12);
  if (buttonState == HIGH) {
    good++;
    lcd.setCursor(10, 1);
    lcd.print(good);
    digitalWrite(8, HIGH);
    delay(500);
  } else {
    digitalWrite(8, LOW);
  }
}
