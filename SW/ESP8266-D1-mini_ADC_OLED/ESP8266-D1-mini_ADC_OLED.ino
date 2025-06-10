/* LaskaKit ESP8266 D1 mini reads voltage on:
 *    1. pin A0  - max voltage 3.2V (Jumper ADC: A0 - right pads soldered. Default)
 *    2. Battery - max voltage 4.2V (Jumper ADC: Bat.V - left pads soldered)
 * and sends every 0.5 seconds through UART and LaskaKit 0.91" SSD1306 (SSD1315) OLED i2c display
 * 
 * Sketch is based od examples form libraryes below.
 * 
 * Board:   LaskaKit ESP8266 D1 mini                        https://www.laskakit.cz/laskakit-esp8266-d1-mini/
 * Battery: GeB LiPol Battery 102035 650mAh 3.7V JST-SH 2.0 https://www.laskakit.cz/geb-lipol-baterie-102035-650mah-3-7v-jst-sh-2-0/   
 * Display: LaskaKit OLED display 128x32 0.91" I²C          https://www.laskakit.cz/laskakit-oled-displej-128x32-0-91--i--c/
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

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>     // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SSD1306.h>

// Choose where to measure voltage
//#define ADC_A0 
#define ADC_BAT 

#ifdef ADC_A0
  #define MAXVOLTAGE 3.2
#else ADC_BAT
  #define MAXVOLTAGE 4.2
#endif

#define ADCpin A0
#define i2c_Address 0x3c

Adafruit_SSD1306 display(128, 32, &Wire, -1);

void setup() {
 Serial.begin(115200);

  Wire.begin();

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
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.2V):
  float voltage = sensorValue * (MAXVOLTAGE / 1023.0);
  
  // print out the value you read:
#ifdef ADC_A0
    Serial.print("Pin A0 Voltage = " );
#else ADC_BAT
    Serial.print("Battery Voltage = " );
#endif
  Serial.print(voltage);
  Serial.println("V");

  display.setCursor(0,0);
#ifdef ADC_A0
  display.println((String)"Pin A0 voltage: ");
#else ADC_BAT
  display.println((String)"Battery voltage: ");
#endif
  display.print(voltage);
  display.println((String)" V");
  display.display(); 
  delay(500);
  display.clearDisplay();
}
