#define SOIL_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(SOIL_PIN);

  int moisturePercent = map(value, 1023, 300, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(500);
}