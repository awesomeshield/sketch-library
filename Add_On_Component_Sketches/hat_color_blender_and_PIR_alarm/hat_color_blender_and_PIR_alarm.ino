// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here
int r, g, b;

void burglarAlarm() {
  while ( awesome.port1.IRMotionSensor.isOn() ) {
    siren();
  }
  awesome.LED.turnOff();
  awesome.buzzer.turnOff();
}

void colorBlender() {
  r = awesome.knob.reading() / 4;
  g = 1023 - awesome.port2.knob.reading();
  g = g / 4;
  b = 1023 - awesome.port3.knob.reading();
  b = b / 4;
  awesome.LED.turnOn(r, g, b);
}

void siren() {
  awesome.LED.turnOn(RED);
  awesome.buzzer.turnOn(300);
  delay(300);
  awesome.LED.turnOn(WHITE);
  awesome.buzzer.turnOn(600);
  delay(300 );
}

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  if ( awesome.toggleSwitch.isOn() ) {
    burglarAlarm();
  } else {
    colorBlender();
  }
}
