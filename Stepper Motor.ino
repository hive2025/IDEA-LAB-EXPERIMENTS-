#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  motor.setSpeed(10);
}

void loop() {
  motor.step(2048);   // Clockwise
  delay(1000);

  motor.step(-2048);  // Counter-clockwise
  delay(1000);
}