#include "pitches.h"

int melody[]={
  NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,
  NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4,
  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,
  NOTE_C4,NOTE_C4,NOTE_G4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_G4,
  NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_C4,
};

int duration[]={4,4,4,4,4,4,2};

void setup() {
  for(int i=0;i<42;i++)
  {
    int noteduration=1000/duration[i%7];
    tone(8,melody[i],noteduration);
    delay(noteduration*1.3);
    noTone(8);
  }
}

void loop(){
}
