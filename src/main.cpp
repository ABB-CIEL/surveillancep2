#include <Arduino.h>
#include <Wire.h>
#include "SSD1306.h"

SSD1306 ecranOled(0x3c, 5, 4);

void setup() {
  Serial.begin(115200);
    ecranOled.init();
    ecranOled.clear();
    ecranOled.setFont(ArialMT_Plain_10); 
    ecranOled.drawString(0, 0, "mugiwara boooom moyaaaaaaaaah moyah");
 
    ecranOled.display();
}

void loop() {
}
