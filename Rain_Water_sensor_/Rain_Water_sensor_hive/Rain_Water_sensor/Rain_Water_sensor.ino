// Define the pins connected to the sensor
const int analogPin = A0;  // Analog output from the sensor
const int digitalPin = 2;  // Digital output from the sensor

// Variables to store the sensor readings
int analogValue = 0;
int digitalValue = 0;

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  
  // Set the digital pin as an input
  pinMode(digitalPin, INPUT);
  
  Serial.println("Rain Drop Sensor Initialized.");
  Serial.println("-----------------------------");
}

void loop() {
  // Read the values from the sensor
  analogValue = analogRead(analogPin);
  digitalValue = digitalRead(digitalPin);
  
  // Print the raw analog value (ranges from 0 to 1023)
  // 1023 usually means completely dry, closer to 0 means completely wet
  Serial.print("Analog Value (Intensity): ");
  Serial.print(analogValue);
  
  // Print a descriptive status based on the analog value
  Serial.print(" - Status: ");
  if (analogValue > 900) {
    Serial.print("Completely Dry");
  } else if (analogValue > 600) {
    Serial.print("Light Rain / Drizzle");
  } else if (analogValue > 400) {
    Serial.print("Moderate Rain");
  } else {
    Serial.print("Heavy Rain / Submerged");
  }

  // Print the digital value state
  // D0 goes LOW (0) when water is detected beyond the threshold set by the potentiometer
  Serial.print(" | Digital Out: ");
  if (digitalValue == LOW) {
    Serial.println("Rain Detected!");
  } else {
    Serial.println("No Rain.");
  }
  
  // Wait for a second before taking the next reading
  delay(1000);
}