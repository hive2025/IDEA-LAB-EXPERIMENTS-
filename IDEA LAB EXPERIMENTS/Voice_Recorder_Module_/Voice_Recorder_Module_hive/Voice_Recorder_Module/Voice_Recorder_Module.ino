/*
 * ISD1820 Voice Recorder Control
 * ------------------------------
 * LIBRARIES: No external libraries required. 
 * This uses built-in Arduino digital control.
 * * WIRING:
 * - Module VCC   -> Arduino 5V
 * - Module GND   -> Arduino GND
 * - Module PLAYE -> Arduino Pin 3
 * - Module REC   -> Arduino Pin 4
 * - Speaker      -> Module SP+ and SP- terminals
 */

const int playPin = 3; 
const int recPin = 4;  

void setup() {
  pinMode(playPin, OUTPUT);
  pinMode(recPin, OUTPUT);
  
  // Set pins LOW to ensure no triggers on startup
  digitalWrite(playPin, LOW);
  digitalWrite(recPin, LOW);
  
  Serial.begin(9600);
  Serial.println("System Initialized.");
}

void loop() {
  // Example: Record for 3 seconds then play back
  recordAudio(3000);
  delay(1000);
  playAudio();
  
  // Wait before repeating
  delay(5000); 
}

void recordAudio(int duration) {
  Serial.println("Recording...");
  digitalWrite(recPin, HIGH);
  delay(duration);
  digitalWrite(recPin, LOW);
  Serial.println("Recording Stopped.");
}

void playAudio() {
  Serial.println("Playing...");
  // A short pulse on PLAYE triggers the module to play the full recording
  digitalWrite(playPin, HIGH);
  delay(100);
  digitalWrite(playPin, LOW);
}