/*
 * Creation & Computation - Digital Futures, OCAD University
 * Kate Hartman / Nick Puckett
 * Sketch - 4 
 * Project - 2 
 */




#include <Adafruit_NeoPixel.h>

#define LDR_PIN A5
#define PIN 9	 // input pin Neopixel is attached to

#define NUMPIXELS      8 // number of neopixels in Ring

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 0; // timing delay

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int lightLevel = 0;
int preLightLevel = 0;

void setup() {
  pixels.begin(); // Initializes the NeoPixel library.
  pixels.show();            // Turn OFF all pixels ASAP
  pixels.setBrightness(225);
 //Serial.begin(960);
}

void loop() {

   pixels.show();
  // lightLevel = map(analogRead(LDR_PIN), 0, 1023, 0,1023);
  lightLevel = analogRead(LDR_PIN);

if (lightLevel > 900) {
  setBlackColor();
}
else if (lightLevel < 800) {
  setGreenColor();
}
else {
  setBlueColor();
}
}




 //setColor()
// picks random values to set for RGB
void setBlackColor(){
  // lightLevel = map(analogRead(LDR_PIN), 0, 1023, 255,10);
  Serial.println(lightLevel);

  if(preLightLevel != lightLevel)
   {
     for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    //pixels.show();
    }
  	//redColor =  lightLevel;
  	//greenColor = random(0, 10) + lightLevel;
  	//blueColor = random(0, 10);
  }
  // if(preLightLevel != lightLevel){ 
  // colorWipe(pixels.Color(255,   0,   0));
  // }
  
  preLightLevel = lightLevel;
}

void setGreenColor(){
//   //lightLevel = map(analogRead(LDR_PIN), 0, 1023,300,700);
  Serial.println(lightLevel);

  if(preLightLevel != lightLevel)
   {
     for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    //pixels.show();
    }
//    }
  // if(preLightLevel != lightLevel){ 
  // colorWipe(pixels.Color(255,   0,   0));
  // }
  
  preLightLevel = lightLevel;
   }
}

void setBlueColor(){
//   //lightLevel = map(analogRead(LDR_PIN), 0, 1023,300,700);
  Serial.println(lightLevel);

  if(preLightLevel != lightLevel)
   {
     for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
//     //pixels.show();
    }
//    }
  // if(preLightLevel != lightLevel){ 
  // colorWipe(pixels.Color(255,   0,   0));
  // }
  
  // preLightLevel = lightLevel;
   }
}



