/* LaskaKit ESP8266 D1 mini blink example.
 * 
 * Board:   LaskaKit ESP8266 D1 mini  https://www.laskakit.cz/laskakit-esp8266-d1-mini/
 * 
 * In Arduino IDE choose board: "LOLIN(WEMOS) D1 R2 & mini"
 * 
 * Made by (c) laskakit.cz 2025
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 */

#define led D4           
int i, j;

void setup() {
  pinMode(led, OUTPUT);   
}

void loop() {
  for(i=0; i < 3; i++) {
    digitalWrite(led, HIGH);
    delay(100);

    digitalWrite(led, LOW);
    delay(100);
  }
  
  delay(500);
  
  for(i=0; i < 1; i++) {
	  for(j=0; j <= 256;){
		  analogWrite(led, j);
      delay(1);
		  j += 1;
	  }
	  delay(500);
	  for(j=256; j >= 0;){
		  analogWrite(led, j);
      delay(1);
		  j -= 1;
	  }
    delay(500);
  }
  delay(500);
}
