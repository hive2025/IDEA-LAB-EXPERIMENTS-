#define SOIL_PIN A1

void setup() {
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(SOIL_PIN);

  Serial.print("Soil Moisture Value: ");
  Serial.print(value);
  Serial.print(" -> ");

  if (value >= 950) {
    Serial.println("Dry Soil (No Water)");
  }
  else if (value >= 700) {
    Serial.println("Slight Moisture");
  }
  else if (value >= 400) {
    Serial.println("Medium Wet");
  }
  else {
    Serial.println("Very Wet Soil");
  }

  delay(500);
}
