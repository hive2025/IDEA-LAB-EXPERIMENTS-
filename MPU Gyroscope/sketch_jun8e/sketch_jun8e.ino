#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(0x68);
  byte error = Wire.endTransmission();

  if (error == 0) {
    Serial.println("MPU6050 Found!");
  } else {
    Serial.println("MPU6050 Not Found!");
  }
}

void loop() {
}
