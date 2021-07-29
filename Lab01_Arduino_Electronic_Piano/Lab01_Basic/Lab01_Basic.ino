#include  "pitches.h"


int melody[]={
  NOTE_C4 ,NOTE_D4 ,NOTE_E4 ,NOTE_F4 ,NOTE_G4,NOTE_A4,NOTE_B4
};
int button1,button2,button3,button4,button5,button6,button7=0;

void setup(){
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);
  pinMode(3,INPUT);  
}

void loop(){
  button1=digitalRead(14);
  button2=digitalRead(15);
  button3=digitalRead(16);
  button4=digitalRead(17);
  button5=digitalRead(18);
  button6=digitalRead(19);
  button7=digitalRead(3);

  if(button1==HIGH)
  {
    tone(2,melody[0],10);
  }
  if(button2==HIGH)
  {
    tone(2,melody[1],10);
  }
  if(button3==HIGH)
  {
    tone(2,melody[2],10);
  }
  if(button4==HIGH)
  {
    tone(2,melody[3],10);
  }
  if(button5==HIGH)
  {
    tone(2,melody[4],10);
  }
  if(button6==HIGH)
  {
    tone(2,melody[5],10);
  }
  if(button7==HIGH)
  {
    tone(2,melody[6],10);
  }
  
}
