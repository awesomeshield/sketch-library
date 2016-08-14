// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

int pause = 150; // pause between siren
int threshold = 1023;

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:

}

void loop() {
  threshold = awesome.knob.reading();
  if (awesome.lightSensor.reading() > threshold) {
    awesome.LED.turnOn(RED);
    awesome.buzzer.turnOn(300);
    delay(pause);
    awesome.LED.turnOn(BLUE);
    awesome.buzzer.turnOn(600);
    delay(pause);
  } else {
    awesome.LED.turnOff();
    awesome.buzzer.turnOff();
  }
}
