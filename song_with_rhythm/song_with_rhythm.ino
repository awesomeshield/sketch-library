// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// declare variables here
// C major scale
float Cmaj[] = {261.63, 293.66, 329.63, 349.23, 392, 440, 493.88, 523.25};

// the number of notes in the song
int numNotes=9;

// the index of each note in the scale
int notes[] = {0,1,2,3,0,3,3,3,4};

// the duration of each note, in eigth notes
int rhythm[] = {1,1,1,2,2,1,1,1,5};

// length of an eigth note in millis
int eighthNote = 200;
// pause between notes, in millis
int pause = 0.05 * eighthNote;
// amount of time to hold each eigth note
int holdEigth = eighthNote-pause;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  
}

void loop() {
  // wait for button press
  while ( awesome.port1.button.isUp() ) {
    // do nothing
  }
  // loop through notes array
  for (int i = 0; i < numNotes; i++) {
    // turn buzzer on using requency of current note
    awesome.buzzer.turnOn(Cmaj[notes[i]]);
    
    /* delay for the duration of the note
     * which is equal to the duration in eigth notes
     * multiplied by the duration of an eigth note
     */
    delay(rhythm[i]*holdEigth);
    
    // turn off buzzer
    awesome.buzzer.turnOff();
    
    // delay briefly to create space between the notes
    delay(pause);
  }
  delay(2500);
}
