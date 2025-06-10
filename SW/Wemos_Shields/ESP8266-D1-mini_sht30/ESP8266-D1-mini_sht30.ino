/* LaskaKit ESP8266 D1 mini reads Temperature and Humidity from SHT30 sensor 
 * and and print in Serial Monitor
 * Sketch is based on examples form libraryes below.
 * 
 * Board:   LaskaKit ESP8266 D1 mini    https://www.laskakit.cz/laskakit-esp8266-d1-mini/
 * Sensor:  WeMos D1 mini SHT30 shield  https://www.laskakit.cz/wemos-d1-mini-sht30-shield--i2c/
 * 
 * In Arduino IDE choose board: "LOLIN(WEMOS) D1 R2 & mini"
 *
 * Libraries:
 * https://github.com/adafruit/Adafruit_SHT31
 * 
 * Made by (c) laskakit.cz 2025
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#include <Wire.h>
#include "Adafruit_SHT31.h"

Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  Serial.begin(115200);
  while (!Serial) 
  {
    ; // wait for serial port
  }

  if (! sht31.begin(0x45))  // alternatively 0x44, depends on ADDR pin
  {
    Serial.println("SHT31 not found");
    Serial.println("Check the connection");
    while (1) delay(1);
  }

}

void loop() {
  float temperature = sht31.readTemperature();
  float humidity = sht31.readHumidity(); 

  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" degC");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("% rH");

  delay(2000);
}
