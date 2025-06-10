/* LaskaKit ESP8266 D1 mini reads Temperature and Pressure from BMP180 sensor 
 * and and print in Serial Monitor
 * Sketch is based on examples form libraryes below.
 * 
 * Board:   LaskaKit ESP8266 D1 mini    https://www.laskakit.cz/laskakit-esp8266-d1-mini/
 * Sensor:  WeMos D1 mini BMP180 Shield https://www.laskakit.cz/wemos-d1-mini-bmp180-shield/
 * 
 * In Arduino IDE choose board: "LOLIN(WEMOS) D1 R2 & mini"
 *
 * Libraries:
 * https://github.com/adafruit/Adafruit-BMP085-Library/blob/master/Adafruit_BMP085.h
 * 
 * Made by (c) laskakit.cz 2025
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#include <Wire.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(115200);

// Initialize device.
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
}

void loop() {
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();
    delay(500);
}