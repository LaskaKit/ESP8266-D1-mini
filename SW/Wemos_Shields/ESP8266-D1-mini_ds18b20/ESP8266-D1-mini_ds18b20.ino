/* LaskaKit ESP8266 D1 mini reads Temperature from DS18B20 sensor 
 * and and print in Serial Monitor
 * Sketch is based on examples form libraryes below.
 * 
 * Board:   LaskaKit ESP8266 D1 mini      https://www.laskakit.cz/laskakit-esp8266-d1-mini/
 * Sensor:  WeMos D1 mini DS18B20 shield  https://www.laskakit.cz/wemos-d1-mini-ds18b20-shield/
 * 
 * In Arduino IDE choose board: "LOLIN(WEMOS) D1 R2 & mini"
 *
 * Libraries:
 * https://github.com/milesburton/Arduino-Temperature-Control-Library
 * 
 * Made by (c) laskakit.cz 2025
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS D2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */

void setup() {
  Serial.begin(115200);
  while (!Serial)   {
    ; // wait for serial port
  }
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}

void loop() {
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  delay(1500);
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  }
  else
  {
    Serial.println("Error: Could not read temperature data");
  }
}
