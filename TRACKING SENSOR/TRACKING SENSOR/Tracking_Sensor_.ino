// Define the Arduino pins for the 5 channels
const int SENSOR_FAR_LEFT   = 4;
const int SENSOR_NEAR_LEFT  = 5;
const int SENSOR_CENTER     = 6;
const int SENSOR_NEAR_RIGHT = 7;
const int SENSOR_FAR_RIGHT  = 8;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Set all sensor pins as Inputs
  pinMode(SENSOR_FAR_LEFT, INPUT);
  pinMode(SENSOR_NEAR_LEFT, INPUT);
  pinMode(SENSOR_CENTER, INPUT);
  pinMode(SENSOR_NEAR_RIGHT, INPUT);
  pinMode(SENSOR_FAR_RIGHT, INPUT);

  Serial.println("BFD-1000 5-Channel Sensor Initialized.");
}

void loop() {
  // Read the digital state of each channel (1 or 0)
  int s1 = digitalRead(SENSOR_FAR_LEFT);
  int s2 = digitalRead(SENSOR_NEAR_LEFT);
  int s3 = digitalRead(SENSOR_CENTER);
  int s4 = digitalRead(SENSOR_NEAR_RIGHT);
  int s5 = digitalRead(SENSOR_FAR_RIGHT);

  // Print raw values to the Serial Monitor for debugging
  Serial.print("Sensors: ");
  Serial.print(s1); Serial.print(" ");
  Serial.print(s2); Serial.print(" ");
  Serial.print(s3); Serial.print(" ");
  Serial.print(s4); Serial.print(" ");
  Serial.print(s5);
  
  // Create a quick visual map in text format
  Serial.print("  |  Visual Map: [");
  Serial.print(s1 == HIGH ? "X" : " ");
  Serial.print(s2 == HIGH ? "X" : " ");
  Serial.print(s3 == HIGH ? "X" : " ");
  Serial.print(s4 == HIGH ? "X" : " ");
  Serial.print(s5 == HIGH ? "X" : " ");
  Serial.println("]");

  // Simple Logic Example for Robot Decisions
  if (s3 == HIGH) {
    Serial.println("-> Action: Move Straight (Line is centered)");
  } else if (s1 == HIGH || s2 == HIGH) {
    Serial.println("-> Action: Turn Left (Line is drifting left)");
  } else if (s4 == HIGH || s5 == HIGH) {
    Serial.println("-> Action: Turn Right (Line is drifting right)");
  } else {
    Serial.println("-> Action: Line Lost / Stopped");
  }

  Serial.println("----------------------------------------");
  delay(200); // 200ms delay to make the reading readable
}