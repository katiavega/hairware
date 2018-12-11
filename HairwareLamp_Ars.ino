#include <Adafruit_NeoPixel.h>
#define PIN 13
#define SENSORPIN 2
int buttonState = 0; 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(32, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
  strip.show(); 
  pinMode(SENSORPIN, INPUT);
  digitalWrite(SENSORPIN,HIGH);
  
}
void loop() {
  
buttonState = digitalRead(SENSORPIN);

  
  if (buttonState == LOW) {
     // for (int i=0;i<32;i++) {strip.setPixelColor(i, 255, 0, 255); }
    rainbowCycle(20);
  }
  else{
      for (int i=0;i<32;i++) {strip.setPixelColor(i, 0, 0, 0); }
    }
  strip.show();
  
  }

  void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  //for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel (era 256*5
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
//}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
  
