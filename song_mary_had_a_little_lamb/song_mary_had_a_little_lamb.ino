// tell the Arduino you're using the Awesome Shield library
#include <Awesome.h>
// tell the Arduino you're using the Awesome Shield hardware
Awesome awesome;

// the index of each note in the song
int notes[] = {3,2,1,2,3,3,3,-1,2,2,2,-1,3,5,5,-1, 3,2,1,2,3,3,3,-1,2,2,3,2,1};

// the number of notes in the song
int numberOfNotes = 29;

// the length of one beat, in milliseconds
int beat = 250;

void setup() {
  Serial.begin(9600);

  // loop through notes array
  for (int i = 0; i < numberOfNotes; i++) {
    // if the note is a rest
    if ( notes[i] == -1 ) {
      // turn off the buzzer
      awesome.buzzer.turnOff();
      // pause for one beat
      delay(beat);
    } 
    // if the note is not a rest
    else {
      // play the current note
      awesome.buzzer.turnOn(Cmaj[notes[i]]);
      // delay for one beat
      delay(beat);
      // stop playing the note
      awesome.buzzer.turnOff();
    }
  }
}

void loop() {
  // do nothing in the loop
}
