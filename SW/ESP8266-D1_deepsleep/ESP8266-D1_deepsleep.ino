/* LaskaKit ESP8266 D1 mini Deep sleep mode example.
 * Measured deep sleep current: 
 *                     * v1.0: 
 *                        * ADC - A0 soldered:  22 µA
 *                        * ADC - BAT soldered: 27 µA
 * Board:   LaskaKit ESP8266 D1 mini  https://www.laskakit.cz/laskakit-esp8266-d1-mini/
 * 
 * In Arduino IDE choose board: "LOLIN(WEMOS) D1 R2 & mini"
 * 
 * Made by (c) laskakit.cz 2025
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#define SLEEP_SEC 15         // Measurement interval (seconds)

void setup(void) {
  Serial.begin(115200);

  delay(2000);

  goToSleep();
}

void loop(void) {
}

void goToSleep(){

  Serial.println("I'm not sleeping");
  delay(3000);
  Serial.println("going to sleep 15 sek");

  // ESP Deep Sleep 
  Serial.println("ESP in sleep mode");
  Serial.flush(); 
  ESP.deepSleep(SLEEP_SEC * 1000000); 
}