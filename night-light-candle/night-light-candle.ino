// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here

// the red and green settings to make a candle-like orange color
int red = 255;
int green = 100;

// state variables
int sampleEvery = 100;   // sample the room light every loop counts
int counter = 0;         // counts the loop count
int brightness = 100;    // the initial brightness
boolean isDark = false;  // determine if it is dark out, we start assuming a lit room.

void setup() {
  awesome.setup(9600);
}

void loop() {
  // update the overall brightness to a number between 40 and 100
  counter = counter + 1;
  if (counter == sampleEvery) {
    counter = 0;  // reset the counter
    awesome.LED.turnOff(); // turn off the light
    delay(10);  // wait a bit
    isDark = awesome.lightSensor.reading() < 3;
  }
  if (isDark) {
    brightness = random(40,100);  
    awesome.LED.turnOn(red*brightness/100, green*brightness/100, 0);
  }
  delay(100);
}
