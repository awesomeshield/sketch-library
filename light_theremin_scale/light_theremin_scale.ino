// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here
int index;
int ambientLightReading;

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:
  ambientLightReading = awesome.lightSensor.reading();
}

void loop() {
  // put your main code here, to run repeatedly:
  index = map(awesome.lightSensor.reading(), 0, ambientLightReading, 0, 7);
  awesome.buzzer.turnOn(Cmaj[index]);
}
