// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// the ambient light reading
int ambientLight = 0;

// the frequency for the buzzer
int frequency = 0;


void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:
  ambientLight = awesome.lightSensor.reading();
}

void loop() {
  frequency = map(awesome.lightSensor.reading(), 0, ambientLight, 0, 800);
  Serial.println(frequency);
  awesome.buzzer.turnOn(frequency);
  delay(10);
}
