// C++ code
//
/*
  Button
  Turns on and off a light emitting diode(LED)
  connected to digital  pin 13, when pressing a
  pushbutton attached to pin 2.

   The circuit:
  * LED attached from pin 13 to ground
  * pushbutton attached to pin 2 from +5V
  * 10K resistor attached to pin 2 from ground
  * Note: on most Arduinos there is already an LED
  on the board  attached to pin 13.

  created 2005  by DojoDave <http://www.0j0.org>

  modified 30 Aug 2011  by Tom Igoe

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Button
*/

#include <Adafruit_LiquidCrystal.h>

int bad = 0;

int buttonState = 0;

int soso = 0;

int good = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
  pinMode(7, INPUT);
  pinMode(4, OUTPUT);
  pinMode(12, INPUT);
  pinMode(8, OUTPUT);

  bad = 0;
  soso = 0;
  good = 0;
  lcd_1.setCursor(1, 1);
  lcd_1.print("Самосознание");
  digitalWrite(LED_BUILTIN, HIGH);
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
  delay(10); // Delay a little bit to improve simulation performance
}