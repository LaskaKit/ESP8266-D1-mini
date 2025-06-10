/* LaskaKit ESP8266 D1 mini Relay example.
 * This shield will not work from battery on LaskaKit ESP8266 D1 mini, because it used 5V power
 *
 * Board:   LaskaKit ESP8266 D1 mini          https://www.laskakit.cz/laskakit-esp8266-d1-mini/
 * Sensor:  Wemos D1 mini 1-kanál relé shield https://www.laskakit.cz/wemos-d1-mini-1-kanal-rele-shield/
 * 
 * In Arduino IDE choose board: "LOLIN(WEMOS) D1 R2 & mini"
 * 
 * Made by (c) laskakit.cz 2025
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#define relay D1           
int i, j;

void setup() {
  pinMode(relay, OUTPUT);   
}

void loop() {
  for(i=0; i < 3; i++) {
    digitalWrite(relay, HIGH);
    delay(100);

    digitalWrite(relay, LOW);
    delay(100);
  }
  
  delay(500);
}
