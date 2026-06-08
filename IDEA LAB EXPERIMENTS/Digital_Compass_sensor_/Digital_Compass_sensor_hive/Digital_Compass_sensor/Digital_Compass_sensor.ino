#include <QMC5883LCompass.h>

// Create a compass object
QMC5883LCompass compass;

void setup() {
  // Initialize the serial monitor
  Serial.begin(9600);
  
  // Initialize the compass
  compass.init();
  
  Serial.println("GY-271 (QMC5883L) Compass Initialized.");
}

void loop() {
  // Read the sensor values
  compass.read();

  // Retrieve X, Y, Z values
  int x = compass.getX();
  int y = compass.getY();
  int z = compass.getZ();
  
  // Get the calculated azimuth (heading in degrees from 0 to 359)
  // 0 = North, 90 = East, 180 = South, 270 = West
  int azimuth = compass.getAzimuth();

  // Print the results to the Serial Monitor
  Serial.print("X: "); 
  Serial.print(x);
  Serial.print(" | Y: "); 
  Serial.print(y);
  Serial.print(" | Z: "); 
  Serial.print(z);
  Serial.print(" | Heading: "); 
  Serial.print(azimuth);
  Serial.println("°");

  // Wait a quarter of a second before the next reading
  delay(250);
}