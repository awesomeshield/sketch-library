 // tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here

void alarm() {
  awesome.LED.turnOn();
  awesome.buzzer.turnOn(200);
  delay(500);
  awesome.LED.turnOff();
  awesome.buzzer.turnOn(800);
  delay(500);
}

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if ( awesome.port1.IRMotionSensor.isOn() ) {
    alarm();
  } else {
    awesome.buzzer.turnOff();
  }
}
