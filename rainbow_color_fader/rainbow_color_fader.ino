// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

/* RAINBOW MAKER!!!

   This sketch shows the colors of the rainbow.
   Here are the colors
   with RGB values like this: (r, g, b)
   red      (255,0,0)
   orange   (255,32,0)
   yellow   (255,85,0)
   green    (0,255,0)
   blue     (0,0,255)
   indigo   (0,150,255)
   violet   (0,255,255)

   If the toggleSwitch is turned on, the LED flashes each color.
   Otherwise it fades between the colors.
*/


// length of each pause while fading between colors
int fadeDelay = 10;

// length of each pause while flashing between colors
int flashDelay = 500;

void setup() {
  awesome.setup(9600);
  // nothing else needs to be done in setup

}

void loop() {
  if ( awesome.toggleSwitch.isOn() ) {
    // flash each color of the rainbow
    awesome.LED.turnOn(RED);
    delay(flashDelay);
    awesome.LED.turnOn(ORANGE);
    delay(flashDelay);
    awesome.LED.turnOn(YELLOW);
    delay(flashDelay);
    awesome.LED.turnOn(GREEN);
    delay(flashDelay);
    awesome.LED.turnOn(BLUE);
    delay(flashDelay);
    // violet is similar to purple
    awesome.LED.turnOn(PURPLE);
    delay(flashDelay);
  }
  else {
    // fade between the colors of the rainbow

    // fade from red (255,0,0) to yellow (255,85,0) 
    for (int i = 0; i <= 85; i++ ) {
      /* at the beginning of the for loop, 
         i = 0 so the LED.turnOn function gets
         (255,0,0) as an input, which makes red.

         i gradually increases until i = 85.
         At this point the LED.turnOn function gets
         (255,85,0) as an input, which makes yellow.
      */
      awesome.LED.turnOn(255, i, 0);
      delay(fadeDelay);
    }

    // fade from yellow (255,85,0) to green (0,255,0)
    for (int i = 0; i <= 255; i++ ) {
      awesome.LED.turnOn(255 - i, 85 + i, 0);
      delay(fadeDelay);
    }

    // fade from green (0,255,0) to blue (0,0,255)
    for (int i = 0; i <= 255; i++ ) {
      awesome.LED.turnOn(0, 255 - i, i);
      delay(fadeDelay);
    }

    // fade from blue (0,0,255) to purple (0,255,255)
    for (int i = 0; i <= 255; i++ ) {
      awesome.LED.turnOn(i, 0, 255);
      delay(fadeDelay);
    }
    // hold on purple for one second
    delay(1000);
  }

  /* turn off the LED and wait for one second
     to signal the end of the loop
  */
  awesome.LED.turnOff();
  delay(1000);
}
