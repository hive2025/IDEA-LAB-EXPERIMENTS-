// PIR Motion Sensor with Arduino UNO

#define PIR_PIN 2
#define LED_PIN 13

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("PIR Motion Sensor Ready");
}

void loop() {

  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) {

    digitalWrite(LED_PIN, HIGH);

    Serial.println("Motion Detected!");

  } else {

    digitalWrite(LED_PIN, LOW);

    Serial.println("No Motion");
  }

  delay(500);
}