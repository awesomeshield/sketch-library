// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here
int r, g, b;

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  r = 1023 - awesome.port1.slider.reading();
  r = r/4;
  g = 1023 - awesome.port2.slider.reading();
  g = g/4;
  b = 1023 - awesome.port3.slider.reading();
  b = b/4;
  awesome.LED.turnOn(r, g, b);
}
