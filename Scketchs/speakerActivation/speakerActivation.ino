#include "pitches.h"
const int buttonPin = 2;  // the pin the button is connected to

int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3
};

void setup() {
    Serial.begin(9600); 
    pinMode(buttonPin, INPUT_PULLUP); // set the button pin as input
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("Button Pressed!"); 
    for (int i = 0; i < 3; i++) {
      tone(8, notes[i], 20); // play each note for a short duration
      delay(2000); // add some delay between each note if needed
      Serial.println("BUZZ"); 
    }
    delay(100);
  } 
}
