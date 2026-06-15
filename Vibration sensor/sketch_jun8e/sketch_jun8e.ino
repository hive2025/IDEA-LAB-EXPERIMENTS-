#define VIBRATION_PIN 2
#define LED_PIN 13

void setup() {
  Serial.begin(9600);

  pinMode(VIBRATION_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Vibration Sensor Ready");
}

void loop() {

  int vibration = digitalRead(VIBRATION_PIN);

  if (vibration == HIGH) {
    Serial.println("Vibration Detected!");
    digitalWrite(LED_PIN, HIGH);
  } 
  else {
    Serial.println("No Vibration");
    digitalWrite(LED_PIN, LOW);
  }

  delay(300);
}
