// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      64

#define FLAME          8

int colors[3][3] = {{150,0,0},{0,150,0},{0,0,150}}; //three types of colors

int pxdata[FLAME][NUMPIXELS] = {
  {2,2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,1,2,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,2,2,1,2,2,1,2,2,2,1,2,1,1,2,1,2,1,2,1,2,2,1,2,1},
  {2,2,2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,1,2,1,1,0,1,1,0,1,2,1,1,1,1,1,1,1,2,2,2,1,2,2,1,2,2,2,1,2,1,1,2,1,2,1,2,1,2,2,1,2},
  {2,2,2,2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,2,2,1,1,0,1,1,0,2,2,1,1,1,1,1,1,2,2,2,2,1,2,2,1,2,2,2,1,2,1,1,2,2,2,1,2,1,2,2,1},
  {2,2,2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,1,2,1,1,0,1,1,0,1,2,1,1,1,1,1,1,1,2,2,2,1,2,2,1,2,2,2,1,2,1,1,2,1,2,1,2,1,2,2,1,2},
  {2,2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,1,2,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,2,2,1,2,2,1,2,2,2,1,2,1,1,2,1,2,1,2,1,2,2,1,2,1},
  {2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,1,2,2,1,0,1,1,0,1,1,2,1,1,1,1,1,1,1,2,2,1,2,2,1,2,2,2,1,2,1,1,2,1,2,2,2,1,2,2,1,2,1,2},
  {2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,2,1,1,1,1,1,2,2,2,0,1,1,0,1,1,2,2,1,1,1,1,1,1,2,2,1,2,2,1,2,2,2,2,2,1,1,2,1,2,2,2,1,2,2,1,2,1,2,2},
  {2,2,1,1,2,2,2,2,2,1,1,1,1,2,2,2,1,1,1,1,1,1,2,2,1,0,1,1,0,1,1,2,1,1,1,1,1,1,1,2,2,1,2,2,1,2,2,2,1,2,1,1,2,1,2,2,2,1,2,2,1,2,1,2}
  };


// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 300; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int h=0;h<FLAME;h++){

    for(int i=0;i<NUMPIXELS;i++){
  
      int j = pxdata[h][i];
      pixels.setPixelColor(i, pixels.Color(colors[j][0],colors[j][1],colors[j][2]));
      pixels.show();
  
    }
    
    delay(delayval);
    
  }

}
