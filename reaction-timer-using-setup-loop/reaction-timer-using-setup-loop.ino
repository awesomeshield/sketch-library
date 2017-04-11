// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

unsigned long signalTime = 0L; // The time when the light came on
unsigned long reactionTime = 0L; // The reaction time of the user
boolean buttonWasPressed = false; // A variable to store if the button was pressed

void setup() {
  awesome.setup(9600);
  /*The following code will run right after reset / first boot and only once:
    It will wait a random numer of seconds (between 2 seconds and 5 seconds)
    Record the number of seconds passed since last start/reset of arduino
    and then turn on the LED.
  */

  delay(random(2000, 5000));
  signalTime = millis();
  awesome.LED.turnOn(GREEN);
}

void loop() {
  /*Check if the button is down now or was down before
    We do this because we only want to execute the code the first time the user
    presses the button
  */
  if ( awesome.button.isDown() && !buttonWasPressed ) {
    /*Now record the button press so this code doesn't run again,
      compute the reaction time, print it to the computer and turn
      the LED green so the user knows his button press was recorded.
    */
    buttonWasPressed = true;
    reactionTime = millis() - signalTime;
    Serial.println(""); // insert a newline at the beginning
    Serial.print("Your reaction time is ");
    Serial.print(reactionTime);
    Serial.println(" ms."); // New line after last word
    awesome.LED.turnOff();
  }
}
