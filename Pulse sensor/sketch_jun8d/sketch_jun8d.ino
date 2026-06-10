// Pulse Sensor Module with Arduino UNO

#define PULSE_PIN A0

void setup() {
  Serial.begin(9600);
  Serial.println("Pulse Sensor Started");
}

void loop() {

  int pulseValue = analogRead(PULSE_PIN);

  Serial.print("Pulse Value: ");
  Serial.println(pulseValue);

  delay(20);
}