#include <IRremote.h>

// Define the pin connected to the OUT pin of the TSOP1738
const int RECV_PIN = 11; 

void setup() {
  // Start the serial communication to print results
  Serial.begin(9600);
  
  // Start the IR receiver
  // ENABLE_LED_FEEDBACK will blink the built-in LED (Pin 13) when a signal is received
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); 
  
  Serial.println("TSOP1738 IR Receiver is ready.");
  Serial.println("Point a remote at the sensor and press a button!");
}

void loop() {
  // Check if a signal has been received
  if (IrReceiver.decode()) {
    
    // Print the received command code in Hexadecimal format
    Serial.print("IR Code: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    
    // Resume listening for the next signal
    IrReceiver.resume(); 
  }
}