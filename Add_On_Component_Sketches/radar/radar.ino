// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here
int position1 = 20;
int position2 = 140;
int movementTime = 13;

void readRangeAt(int pos) {
  awesome.port3.servo.setPosition(pos);
  delay(movementTime);
  Serial.print(pos);
  Serial.print(",");
  int numReadings = 1;
  int sum;
  for (int i = 0; i < numReadings; i++ ) {
    sum += awesome.port1.sonicSensor.reading();
  }
  int average = sum/numReadings;
  Serial.print(average);
  Serial.print(".");
}

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:

}

void loop() {
  // sweep from position1 to position2
  for (int i = position1; i < position2; i++ ) {
    readRangeAt(i);
  }
  
  // sweep from position2 to position1
  for (int i = position2; i > position1; i-- ) {
    readRangeAt(i);
  }
}
