#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_1(0x27, 16, 2);  // адрес дисплея, 16 символов, 2 строки

int bad = 0;
int buttonState = 0;
int soso = 0;
int good = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, INPUT);
  pinMode(4, OUTPUT);
  pinMode(12, INPUT);
  pinMode(8, OUTPUT);

  bad = 0;
  soso = 0;
  good = 0;
  lcd_1.init();            // инициализация
  lcd_1.backlight();       // включить подсветку
  lcd_1.setCursor(1, 0);
  lcd_1.print("Self-awareness");
  delay(1000); // Wait for 1000 millisecond(s)
  lcd_1.clear();
}

void loop()
{
  // read the state of the pushbutton value
  buttonState = digitalRead(2);
  // check if pushbutton is pressed.  if it is, the
  // buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    bad = (bad + 1);
    lcd_1.setCursor(0, 0);
    lcd_1.print("bad");
    lcd_1.setCursor(1, 1);
    lcd_1.print(bad);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // turn LED off
    digitalWrite(LED_BUILTIN, LOW);
  }

  // read the state of the pushbutton value
  buttonState = digitalRead(7);
  // check if pushbutton is pressed.  if it is, the
  // buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    soso = (soso + 1);
    digitalWrite(4, HIGH);
    lcd_1.setCursor(5, 0);
    lcd_1.print("soso");
    lcd_1.setCursor(6, 1);
    lcd_1.print(soso);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // turn LED off
    digitalWrite(4, LOW);
  }

  // read the state of the pushbutton value
  buttonState = digitalRead(12);
  // check if pushbutton is pressed.  if it is, the
  // buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    good = (good + 1);
    digitalWrite(8, HIGH);
    lcd_1.setCursor(10, 0);
    lcd_1.print("good");
    lcd_1.setCursor(11, 1);
    lcd_1.print(good);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // turn LED off
    digitalWrite(8, LOW);
  }
  delay(500); // Delay a little bit to improve simulation performance
}
