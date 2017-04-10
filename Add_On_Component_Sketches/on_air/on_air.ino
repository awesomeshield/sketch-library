// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

#define plusPin A0
DigitalInput guardSwitch;

// declare variables here

void flash(int duration) {
  awesome.port3.LEDString.turnOn();
  delay(duration);
  awesome.port3.LEDString.turnOff();
  delay(duration);
}

void onAir() {
  for (int i = 0; i < 3; i++ ) {
    if ( guardSwitch.isOn() || awesome.toggleSwitch.isOn() ) {
      flash(100);
      delay(50);
      flash(100);
      delay(1250);
    } else {
      offAir();
    }
  }
  while ( guardSwitch.isOn() || awesome.toggleSwitch.isOn() ) {
    awesome.port3.LEDString.turnOn();
  }
}
void offAir() {
  awesome.port3.LEDString.turnOff();
}

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:
    guardSwitch.setVariables(port2PrimaryPin, 2, "guardSwitch", LOW, true);
}

void loop() {
  // put your main code here, to run repeatedly:
  while ( guardSwitch.isOn() || awesome.toggleSwitch.isOn() ) {
    onAir();
  }
  offAir();
}
