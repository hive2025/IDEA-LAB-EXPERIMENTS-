/*
 * WIRING GUIDE (Modified for Serial Logging):
 * ----------------------------------------------------
 * ISD1820 VCC       -> Arduino 5V
 * ISD1820 GND       -> Arduino GND
 * ISD1820 PLAYE     -> Arduino Pin 3
 * * * NOTE: 
 * The speaker has been removed from this configuration. 
 * Ensure your Serial Monitor is open and set to 9600 baud 
 * to view the detailed system output.
 */

const int playTrigger = 3; // Pin connected to PLAYE on the module
int playbackCounter = 1;   // Tracks the number of trigger cycles

void setup() {
  // Initialize Serial Communication at 9600 baud rate
  Serial.begin(9600);
  
  Serial.println("--- System Initialization Started ---");
  
  // Set the trigger pin as output
  pinMode(playTrigger, OUTPUT);
  Serial.println("[INIT] Pin 3 configured as OUTPUT for PLAYE trigger.");
  
  // Ensure the module is not playing at startup
  digitalWrite(playTrigger, LOW);
  Serial.println("[INIT] Trigger pin set to LOW (Idle state).");
  
  // Small delay for system initialization
  delay(1000);
  Serial.println("--- System Initialization Complete ---");
  Serial.println("Waiting for the first playback cycle...\n");
}

void loop() {
  Serial.print(">>> Cycle #");
  Serial.print(playbackCounter);
  Serial.println(" started.");

  // Send a brief HIGH signal (pulse) to the PLAYE pin
  Serial.println("[ACTION] Sending HIGH pulse to trigger playback...");
  digitalWrite(playTrigger, HIGH);
  
  delay(100);              // Hold signal for 100ms
  Serial.println("[ACTION] Pulse held for 100ms.");
  
  digitalWrite(playTrigger, LOW);
  Serial.println("[ACTION] Trigger pin returned to LOW.");
  
  Serial.println("[STATUS] Playback triggered successfully.");
  
  // 10-second wait with detailed Serial countdown
  for(int i = 10; i > 0; i--) {
    Serial.print("Next trigger in: ");
    Serial.print(i);
    Serial.println(" seconds...");
    delay(1000); // Wait 1 second per loop iteration
  }
  
  playbackCounter++;
  Serial.println("--------------------------------------------------\n");
}
