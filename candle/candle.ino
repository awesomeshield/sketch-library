// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here

// the red and green settings to make a candle-like orange color
int red = 255;
int green = 100;

// a variable to adjust the overall brightness
int brightness = 100;

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:

}

void loop() {
  // update the overall brightness to a number between 40 and 100
  brightness = random(40,100);
  
  /*
  turn on the LED
  using the red and green settings adjusted using the brightness
  */
  awesome.LED.turnOn(red*brightness/100, green*brightness/100, 0);
  delay(25);
}
