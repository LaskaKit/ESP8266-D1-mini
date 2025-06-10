/* LaskaKit ESP8266 D1 mini 0.91 OLED display test
 * Sketch is based od examples form libraryes below.
 * 
 * Board:   LaskaKit ESP8266 D1 mini                                      https://www.laskakit.cz/laskakit-esp8266-d1-mini/
 * Display: LaskaKit OLED display 128x32 0.91" I²C                        https://www.laskakit.cz/laskakit-oled-displej-128x32-0-91--i--c/
 * 
 * In Arduino IDE choose board: "LOLIN(WEMOS) D1 R2 & mini"
 *
 * Libraries:
 * https://github.com/adafruit/Adafruit-GFX-Library
 * https://github.com/adafruit/Adafruit_SSD1306
 * 
 * Made by (c) laskakit.cz 2025
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#include <Wire.h>
#include <Adafruit_GFX.h>     // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SSD1306.h> // https://github.com/adafruit/Adafruit_SSD1306

#define i2c_Address 0x3c

Adafruit_SSD1306 display(128, 32, &Wire, -1);

void setup() {
  Serial.begin(115200);
    
  // initilizace BME280 | BME280 Initialization
  Wire.begin (); 
  while(!Serial);    // time to get serial running
           
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, i2c_Address)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(1000); // Pause for 1 second

  display.clearDisplay(); 
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setTextSize(1); 
}

void loop() {
  // put your main code here, to run repeatedly:

  display.setCursor(0,0);
  display.println((String)"Teplota: 25C");
  display.println((String)"Tlak: 950hPa");
  display.println((String)"Vlhkost: 65%");
  display.println((String)"Nadmorska vyska: 554m");
  display.display(); 
  delay(500);
  display.clearDisplay();

}  
