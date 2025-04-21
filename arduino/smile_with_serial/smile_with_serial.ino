#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(0x27, 16, 2);  // адрес дисплея, 16 символов, 2 строки

int bad = 0;
int buttonState = 0;
int soso = 0;
int good = 0;

void setup()
{
  Serial.begin(9600); // Инициализация монитора порта

  pinMode(2, INPUT);    // кнопка "bad" (S_BAD_B)
  pinMode(LED_BUILTIN, OUTPUT); // LED встроенный (D1 RED)
  pinMode(7, INPUT);    // кнопка "soso" (S_SOSO_B)
  pinMode(4, OUTPUT);    // LED для "soso" (D2 WHITE)
  pinMode(12, INPUT);   // кнопка "good" (S_GOOD_B)
  pinMode(8, OUTPUT);    // LED для "good" (D3 BLUE)

  bad = 0;
  soso = 0;
  good = 0;
  lcd_1.init();
  lcd_1.backlight();
  
  // Вывод информации о файле и дате на LCD и в Serial
  lcd_1.setCursor(0, 0);
  lcd_1.print("Self-awareness");
  //lcd_1.print("File:");
  //lcd_1.setCursor(0, 1);
  //lcd_1.print(__FILE__);
  
  Serial.print("File: ");
  Serial.println(__FILE__);
  Serial.print("Date: ");
  Serial.println(__DATE__);
  
  delay(2000); // Ждем, чтобы прочитать информацию
  lcd_1.clear();

  lcd_1.setCursor(1, 0);
  lcd_1.print("bad");
  lcd_1.setCursor(5, 0);
  lcd_1.print("soso");
  lcd_1.setCursor(10, 0);
  lcd_1.print("good");
}

void loop()
{
  // Обработка кнопки BAD (S_BAD_B)
  buttonState = digitalRead(2);
  if (buttonState == HIGH) { // Кнопка нажата (при INPUT и стягивающем резисторе)
    bad++;
    lcd_1.setCursor(1, 1);
    lcd_1.print("   "); // Очищаем предыдущее значение
    lcd_1.setCursor(1, 1);
    lcd_1.print(bad);
    digitalWrite(LED_BUILTIN, HIGH);
    
    Serial.print("bad: ");
    Serial.println(bad);
    delay(300); // Задержка для подавления дребезга
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  // Обработка кнопки SOSO (S_SOSO_B)
  buttonState = digitalRead(7);
  if (buttonState == HIGH) { // Кнопка нажата
    soso++;
    lcd_1.setCursor(5, 1);
    lcd_1.print("   "); // Очищаем предыдущее значение
    lcd_1.setCursor(5, 1);
    lcd_1.print(soso);
    digitalWrite(4, HIGH);
    
    Serial.print("soso: ");
    Serial.println(soso);
    delay(300); // Задержка для подавления дребезга
  } else {
    digitalWrite(4, LOW);
  }

  // Обработка кнопки GOOD (S_GOOD_B)
  buttonState = digitalRead(12);
  if (buttonState == HIGH) { // Кнопка нажата
    good++;
    lcd_1.setCursor(10, 1);
    lcd_1.print("   "); // Очищаем предыдущее значение
    lcd_1.setCursor(10, 1);
    lcd_1.print(good);
    digitalWrite(8, HIGH);
    
    Serial.print("good: ");
    Serial.println(good);
    delay(300); // Задержка для подавления дребезга
  } else {
    digitalWrite(8, LOW);
  }
  
  delay(10); // Небольшая задержка в конце цикла
}
