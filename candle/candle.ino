// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// the red and green settings to make a candle-like orange color
int red = 255;
int green = 100;

// a variable to adjust the overall brightness
int brightness = 100;

// a variable to 
bool isDark = true;

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:

}

void loop() {
  if ( random(0,30) == 1 ) {
    awesome.LED.turnOff();
    isDark = awesome.lightSensor.reading() < 30;
  }
  if ( isDark ) {
    brightness = random(40,100);
    // order of the inputs is: red, green, blue
    awesome.LED.turnOn(255*brightness/100, 100*brightness/100, 0);
    Serial.println(brightness);
  }
  else {
    awesome.LED.turnOff();
  }
  delay(25);
}
