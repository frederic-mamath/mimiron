   #include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 8

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 14
#define BUTTON_PIN 16

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    pinMode(BUTTON_PIN, INPUT_PULLUP); 
}

void turnOnAllLedsInWhite() {
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB(255, 255, 255);
  }
  FastLED.show();
}

void onStart() {
  turnOnAllLedsToWhite();
}

void loop() {
  onStart();
}
