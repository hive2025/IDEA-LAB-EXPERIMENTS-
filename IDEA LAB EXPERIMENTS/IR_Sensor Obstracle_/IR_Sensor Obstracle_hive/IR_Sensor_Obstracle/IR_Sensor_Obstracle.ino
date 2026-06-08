/*
 * WIRING GUIDE:
 * ----------------------------------------------------
 * ISD1820 VCC       -> Arduino 5V
 * ISD1820 GND       -> Arduino GND
 * ISD1820 PLAYE     -> Arduino Pin 3
 * * SPEAKER CONNECTION:
 * Connect the two wires from your 8 Ohm 0.5W speaker 
 * directly to the 'SP+' and 'SP-' terminals on the 
 * ISD1820 module (polarity does not matter).
 * * NOTE: 
 * Ensure you have recorded a message on the module using 
 * the onboard 'REC' button before running this code.
 */

const int playTrigger = 3; // Pin connected to PLAYE on the module

void setup() {
  // Set the trigger pin as output
  pinMode(playTrigger, OUTPUT);
  
  // Ensure the module is not playing at startup
  digitalWrite(playTrigger, LOW);
  
  // Small delay for system initialization
  delay(1000);
}

void loop() {
  // To play the recording, we send a brief HIGH signal (pulse)
  // to the PLAYE pin.
  
  digitalWrite(playTrigger, HIGH);
  delay(100);              // Hold signal for 100ms
  digitalWrite(playTrigger, LOW);
  
  // Wait for 10 seconds before playing the recording again
  // Adjust this delay based on the length of your recording
  delay(10000); 
}
