// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

#include <TM1637Display.h>
#define CLK A0
#define DIO 3

TM1637Display display(CLK, DIO);

// declare variables here
int threshold = 400;
int score = 0;
long c = 523.25;
long a = 783.99;
int beat = 400;
int lastReading;
int i;

void flashLEDs() {
  awesome.port3.LEDString.turnOn();
  delay(250);
  awesome.port3.LEDString.turnOff();
  delay(250);
}

void goal() {
  score = score + 1;
  display.showNumberDec(score);
  flashLEDs();
  flashLEDs();
  flashLEDs();
  flashLEDs();
  flashLEDs();
  awesome.port3.LEDString.turnOn();
  playSong();
  delay(1000);
}

void playSong() {
  awesome.buzzer.turnOn(c);
  delay(beat/3);
  awesome.buzzer.turnOff();
  delay(10);
  awesome.buzzer.turnOn(c);
  delay(beat/3);
  awesome.buzzer.turnOff();
  delay(10);
  awesome.buzzer.turnOn(c);
  delay(beat/3);
  awesome.buzzer.turnOff();
  delay(10);
  awesome.buzzer.turnOn(a);
  delay(beat*2);
  awesome.buzzer.turnOff();
  delay(10);
}

void setup() {
  awesome.setup(9600);
  // put your setup code here, to run once:
  display.setBrightness(0x0f);
  awesome.port3.LEDString.turnOn();
}

void loop() {
  // put your main code here, to run repeatedly:
  lastReading = awesome.port1.IR.reading();
  if ( lastReading > threshold ) {
    goal();
//    awesome.LED.turnOn();
//    delay(100);
//    awesome.LED.turnOff();
  }
  Serial.println(lastReading);
}
