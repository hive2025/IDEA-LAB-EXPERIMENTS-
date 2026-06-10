/*
 * TSOP1738 IR Sensor with Arduino Uno
 * * --- WIRING INSTRUCTIONS (Facing the curved bump/lens of the sensor) ---
 * Pin 1 (Left)   -> GND on Arduino
 * Pin 2 (Middle) -> 5V on Arduino 
 * Pin 3 (Right)  -> Digital Pin 2 on Arduino
 * * --- LIBRARY TO INSTALL ---
 * You need the "IRremote" library. 
 * To install: Open Arduino IDE -> Go to Sketch -> Include Library -> 
 * Manage Libraries -> Search for "IRremote" (by shirriff/ArminJo) -> Click Install.
 */

#include <IRremote.h>

// Define the Arduino pin connected to the TSOP1738 output (Pin 3)
const int RECV_PIN = 2; 

void setup() {
  // Initialize serial communication to view the output
  Serial.begin(9600);
  
  // Start the IR receiver on the specified pin, and flash the built-in LED when a signal is received
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); 
  
  Serial.println("TSOP1738 is ready. Point your remote at the sensor and press a button!");
}

void loop() {
  // Check if an infrared signal has been received
  if (IrReceiver.decode()) {
    
    // Print the received command to the Serial Monitor in Hexadecimal format
    Serial.print("Button Command Received: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    
    // Resume the receiver to prepare for the next signal
    IrReceiver.resume(); 
  }
}
