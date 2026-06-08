/*
 * WIRING CONNECTIONS:
 * 1. Touch Sensor (TTP223)
 * - VCC -> 5V
 * - GND -> GND
 * - OUT -> Pin 2
 * * 2. I2C LCD Display (16x2)
 * - VCC -> 5V
 * - GND -> GND
 * - SDA -> A4 (On Arduino Uno)
 * - SCL -> A5 (On Arduino Uno)
 *
 * LIBRARY INSTALLATION:
 * 1. Open Arduino IDE.
 * 2. Go to 'Sketch' -> 'Include Library' -> 'Manage Libraries...'.
 * 3. Search for "LiquidCrystal I2C".
 * 4. Install the version by Frank de Brabander.
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F (run I2C scanner if blank)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int touchPin = 2;

void setup() {
  pinMode(touchPin, INPUT);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Sensor Status:");
}

void loop() {
  int touchState = digitalRead(touchPin);

  lcd.setCursor(0, 1);
  if (touchState == HIGH) {
    lcd.print("Touched!        ");
  } else {
    lcd.print("Not Touched     ");
  }
  delay(200);
}