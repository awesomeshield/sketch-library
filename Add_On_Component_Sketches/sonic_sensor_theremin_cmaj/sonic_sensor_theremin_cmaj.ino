// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here
float cmaj[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88, 523.25}; // C D E F G A B C
float cmajpent[] = {261.63, 293.66, 329.63, 392.00, 440.00, 523.25}; // C D E G A C
int index;
int maxReading = 57;
int currentReading, freq;

// speaker
int speakerPin = port3PrimaryPin;


void playNote() {
//  index = constrain(currentReading,0,maxReading);
//  index = map(index, 0, maxReading, 0, 7);
  freq = constrain(currentReading,0,maxReading);
  freq = map(freq, 0, maxReading, 100, 1000);
//  Serial.println(index);
  // awesome.buzzer.turnOn(cmaj[index]);
//  tone(speakerPin, cmaj[index]);
  tone(speakerPin, freq);
  delay(25);
}

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( awesome.toggleSwitch.isOn() ) {
      currentReading = awesome.port2.sonicSensor.reading();
    Serial.println(currentReading);
    if ( currentReading > maxReading ) {
  //    awesome.buzzer.turnOff();
        noTone(speakerPin);
    } else {
      playNote();
    }
    delay(25);
  }
  else {
    noTone(speakerPin);
  }
}
