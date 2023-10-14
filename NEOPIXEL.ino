#include <Adafruit_NeoPixel.h>\
#define PIN        6 // On Trinket or Gemma, sugge

Adafruit_NeoPixel pixels(3, 6, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  //RED
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.setPixelColor(0, pixels.Color(225, 0, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(3000);
  //YELLo
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.setPixelColor(1, pixels.Color(255, 255, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(500);
  //GREEN
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.setPixelColor(2, pixels.Color(00, 255, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(2000);
  delay(DELAYVAL); // Pause before next pass through loop

}
