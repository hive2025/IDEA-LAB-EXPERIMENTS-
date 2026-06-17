/*
 * WIRING CONNECTIONS:
 * Touch Sensor (TTP223) to Arduino Uno:
 * - VCC -> 5V
 * - GND -> GND
 * - OUT/SIG -> Pin 2
 */

// Define the pin connected to the touch sensor
const int touchPin = 2;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
  
  // Configure the touch pin as an input
  pinMode(touchPin, INPUT);
  
  // Print an initial status message
  Serial.println("Sensor Status: Initialized");
  Serial.println("--------------------------");
}

void loop() {
  // Read the current state of the touch sensor
  int touchState = digitalRead(touchPin);

  // Output the status to the Serial Monitor based on the reading
  if (touchState == HIGH) {
    Serial.println("Touched!");
  } else {
    Serial.println("Not Touched");
  }
  
  // A small delay makes the output easier to read
  delay(200);
}
