// TCS34725 RGB Color Sensor with Arduino UNO

#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Create sensor object
Adafruit_TCS34725 tcs = Adafruit_TCS34725(
  TCS34725_INTEGRATIONTIME_50MS,
  TCS34725_GAIN_4X
);

void setup() {
  Serial.begin(9600);

  if (tcs.begin()) {
    Serial.println("TCS34725 Found");
  } else {
    Serial.println("No TCS34725 found");
    while (1);
  }
}

void loop() {

  uint16_t r, g, b, c;

  // Read RGB values
  tcs.getRawData(&r, &g, &b, &c);

  Serial.print("Red: ");
  Serial.print(r);

  Serial.print("  Green: ");
  Serial.print(g);

  Serial.print("  Blue: ");
  Serial.print(b);

  Serial.print("  Clear: ");
  Serial.println(c);

  delay(1000);
}