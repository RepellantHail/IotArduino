#include "pitches.h"

int OUT_PIN = 8;

int melody[] = {
    NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
    NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4,
    NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4,
    NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4};

int noteDurations[] = {
    4, 4, 2, 2, 2, 1,
    4, 4, 2, 2, 2, 1,
    4, 4, 2, 2, 4, 4, 2, 1,
    4, 4, 2, 2, 2, 1};

void setup()
{
  for (int thisNote = 0; thisNote < 27; thisNote++)
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(OUT_PIN, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(OUT_PIN);
  }
  noTone(OUT_PIN);
}

void loop()
{
}