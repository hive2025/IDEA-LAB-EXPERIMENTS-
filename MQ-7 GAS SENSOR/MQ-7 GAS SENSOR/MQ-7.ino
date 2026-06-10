/* * CONNECTIONS:
 * MQ-7 VCC  -> Arduino 5V
 * MQ-7 GND  -> Arduino GND
 * MQ-7 A0   -> Arduino A0
 * MQ-7 D0   -> Arduino D2
 */

const int analogPin = A0;  // Connect A0 to A0
const int digitalPin = 2;  // Connect D0 to D2

void setup() {
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  Serial.println("MQ-7 Sensor Initialized...");
}

void loop() {
  int rawValue = analogRead(analogPin);
  int thresholdReached = digitalRead(digitalPin);

  Serial.print("Raw CO Level: ");
  Serial.print(rawValue);
  
  if (thresholdReached == LOW) { // Usually LOW when gas is detected
    Serial.println(" | Alert: High CO concentration!");
  } else {
    Serial.println(" | CO levels normal.");
  }

  delay(1000);
}