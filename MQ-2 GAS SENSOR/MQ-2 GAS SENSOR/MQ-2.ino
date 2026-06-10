/* * MQ-2 Gas & Smoke Sensor
 * * CONNECTIONS:
 * MQ-2 VCC  -> Arduino 5V
 * MQ-2 GND  -> Arduino GND
 * MQ-2 A0   -> Arduino A0
 * MQ-2 D0   -> Arduino 3
 */

#include <MQUnifiedsensor.h>

// Library Setup
#define Board ("Arduino UNO")
#define Pin (A0) 
#define Type ("MQ-2")
#define Voltage_Resolution (5)
#define ADC_Bit_Resolution (10)

MQUnifiedsensor MQ2(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);

const int ledPin = 13;

void setup() {
  Serial.begin(9600);

  // Set sensor parameters
  MQ2.setRegressionMethod(1); // PPM = a*ratio^b
  MQ2.init(); 

  Serial.print("Calibrating MQ-2...");
  // Update this line in your setup() function:
  MQ2.calibrate(0.21);
  Serial.println(" Done!");

  pinMode(ledPin, OUTPUT);
}

void loop() {
  MQ2.update(); 
  float ppm = MQ2.readSensor(); 
  
  Serial.print("Gas Concentration: ");
  Serial.print(ppm);
  Serial.println(" PPM");

  // Simple logic to trigger alarm
  if (ppm > 500) { // Adjust this threshold based on your needs
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  delay(1000);
}