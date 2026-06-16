const int TOUCH_PIN = 2;     // Connect TTP223 SIG to Digital Pin 2
const int LED_PIN   = 13;    // Uses the Arduino Uno's built-in LED

void setup() {
  Serial.begin(9600);        // 9600 baud rate is standard for Uno
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int touchState = digitalRead(TOUCH_PIN);

  if (touchState == HIGH) {
    digitalWrite(LED_PIN, HIGH);   // Lights up the built-in "L" LED on the Uno
    Serial.println("Touched!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(50); 
}
