#define SOIL_PIN A1

void setup() {
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(SOIL_PIN);

  int moisture = map(value, 1023, 300, 0, 100);
  moisture = constrain(moisture, 0, 100);

  Serial.print("Moisture: ");
  Serial.print(moisture);
  Serial.println("%");

  delay(500);
}