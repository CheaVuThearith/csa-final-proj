#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

#define PIN 6
#define NUMPIXELS 12
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
}
void loop() {
  if (Serial.available() > 0) {
    char status = Serial.read();
    if (status == '1') {
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 150, 0));
        pixels.show();
      }
    } else if (status == '0') {
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        pixels.show();
      }
    }
  }
}
