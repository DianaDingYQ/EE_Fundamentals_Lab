#include <Arduino.h>

// put function declarations here:
// Define analog input pins
const int analogPin1 = 1;  // GPIO1
const int analogPin2 = 2;  // GPIO2

void setup() {
  // Initialize serial monitor with a baud rate of 115200
  Serial.begin(115200);

  // Set ADC resolution to 12 bits
  analogReadResolution(12);

  // Print initialization message
  Serial.println("ESP32 ADC Voltage Reader");
}

void loop() {
  // Read ADC values from GPIO1 and GPIO2
  int adcValue1 = analogRead(analogPin1);
  int adcValue2 = analogRead(analogPin2);

  // Convert ADC values to voltage
  float voltage1 = (adcValue1 / 4095.0) * 3.3; 
  float voltage2 = (adcValue2 / 4095.0) * 3.3;

  // Print voltage readings to the serial monitor
  Serial.print("GPIO1 Voltage: ");
  Serial.print(voltage1);
  Serial.println(" V");

  Serial.print("GPIO2 Voltage: ");
  Serial.print(voltage2);
  Serial.println(" V");

  Serial.println("-------------------------");

  // Delay for 1 second
  delay(1000);
}
