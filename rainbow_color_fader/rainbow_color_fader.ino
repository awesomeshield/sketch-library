// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

/*
 * Want to fade between the colors of the rainbow
 * Here are the colors, with RGB values
 * red      (255,0,0)
 * orange   (255,32,0)
 * yellow   (255,85,0)
 * green    (0,255,0)
 * blue     (0,0,255)
 * indigo   (0,150,255)
 * violet   (0,255,255)
 */

// declare variables here
int delayTime=5;

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:
  
}

void loop() {
  // red to yellow
  for (int i = 0; i <= 85; i++ ) {
    awesome.LED.turnOn(255,i,0);
    delay(delayTime);
  }
  
  // yellow to green
  for (int i = 0; i <= 255-85; i++ ) {
    awesome.LED.turnOn(255-i,85+i,0);
    delay(delayTime);
  }

  // green to blue
  for (int i = 0; i <= 255; i++ ) {
    awesome.LED.turnOn(0,255-i,i);
    delay(delayTime);
  }

  // blue to violet
  for (int i = 0; i <= 255; i++ ) {
    awesome.LED.turnOn(i,0,255);
    delay(delayTime);
  }
  
  // signal end of loop
  awesome.LED.turnOff();
  delay(1000);
}
