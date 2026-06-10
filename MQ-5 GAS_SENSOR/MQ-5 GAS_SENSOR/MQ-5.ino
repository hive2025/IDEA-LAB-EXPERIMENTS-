/* * CONNECTIONS:
 * MQ-5 VCC -> Arduino 5V
 * MQ-5 GND -> Arduino GND
 * MQ-5 A0  -> Arduino A0
 * MQ-5 D0  -> Arduino Pin 2
 */

const int analogPin = A0;  // Analog pin for concentration
const int digitalPin = 2;  // Digital pin for threshold
const int ledPin = 13;     // Onboard LED

void setup() {
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("MQ-5 Sensor Initialized...");
}

void loop() {
  int analogValue = analogRead(analogPin);
  int gasDetected = digitalRead(digitalPin);

  Serial.print("Analog Level: ");
  Serial.println(analogValue);

  // Digital output is usually LOW when gas is detected
  if (gasDetected == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.println("⚠️ Warning: Gas Detected!");
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}