// Define the analog pin connected to the FSR voltage divider node
const int FSR_PIN = A0; 

void setup() {
  // Start serial communication
  Serial.begin(9600);
  
  // Analog pins are configured as inputs by default, 
  // but explicitly setting it keeps the code clean.
  pinMode(FSR_PIN, INPUT);
  
  Serial.println("38.1mm Square Force Sensor Initialized.");
}

void loop() {
  // Read the analog value from the FSR circuit (0 to 1023)
  int fsrReading = analogRead(FSR_PIN);  
  
  Serial.print("Analog Reading = ");
  Serial.print(fsrReading);
  Serial.print(" - ");

  // Interpret the analog values into human-readable force levels
  // These thresholds can be adjusted based on your specific setup
  if (fsrReading < 10) {
    Serial.println("No Pressure");
  } else if (fsrReading < 200) {
    Serial.println("Light Touch");
  } else if (fsrReading < 500) {
    Serial.println("Medium Squeeze");
  } else if (fsrReading < 800) {
    Serial.println("Medium-Heavy Force");
  } else {
    Serial.println("⚠️ Heavy Squeeze!");
  }

  delay(200); // Small delay to make the Serial Monitor easy to read
}