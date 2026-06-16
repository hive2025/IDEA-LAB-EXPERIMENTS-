// Define the pins for the 4 touch sensors
const int sensorPins[] = {2, 3, 4, 5}; 

void setup() {
  Serial.begin(9600);
  
  // Set all sensor pins as input
  for (int i = 0; i < 4; i++) {
    pinMode(sensorPins[i], INPUT);
  }
  
  Serial.println("System Ready. Touch a sensor to see the number.");
}

void loop() {
  for (int i = 0; i < 4; i++) {
    // Read the current state of the sensor
    if (digitalRead(sensorPins[i]) == HIGH) {
      // Print the index + 1 to correspond to 1, 2, 3, 4
      Serial.print("Detected touch at place: ");
      Serial.println(i + 1);
      
      // Small delay to prevent multiple prints for one touch
      delay(300); 
    }
  }
}
