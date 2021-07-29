int startCount2=0;
int lastTime2=0;
int currentTime2=0;
int interval=1000;

int numarray[10][7]={
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0},
};


void unitWrite(byte digit){
  byte pin=2;
  for(byte seg=0;seg<7;++seg)
  {
    digitalWrite(pin,numarray[digit][seg]);
    ++pin;
  }
}
void tensWrite(byte digit){
  byte pin=9;
  for(byte seg=0;seg<7;++seg)
  {
    digitalWrite(pin,numarray[digit][seg]);
    ++pin;
  }
}

void setup() {
  for(int i=2;i<=15;i++)
  {
   pinMode(i,OUTPUT); 
  }
  pinMode(17,INPUT);
  pinMode(18,INPUT);
}

void loop() {
  resetplace:
  int startCount=0;
  while(startCount==0)
  {
    tensWrite(6);
    unitWrite(0);
    if(digitalRead(18)==HIGH){
      startCount++;
    }
  }
  currentTime2=millis();
  lastTime2=currentTime2;
  while((currentTime2-lastTime2)<interval){
        currentTime2=millis(); 
      }lastTime2=currentTime2;
  for(byte tens=5;tens>=0;--tens){
    for(byte unit=10;unit>0;--unit){
      unitWrite(unit-1);
      tensWrite(tens);
      while((currentTime2-lastTime2)<interval){
        while(digitalRead(18)!=LOW){
          startCount++;}
        while(startCount%2==0){
          unitWrite(unit-1);
          tensWrite(tens);
          while(digitalRead(18)!=LOW){
            startCount++;}
          while(digitalRead(17)!=LOW){
            goto resetplace;
          }
        }
        currentTime2=millis();
      }lastTime2=currentTime2;
    }
    while(tens==0){
      unitWrite(0);
      tensWrite(0);
      while(digitalRead(17)!=LOW){
        goto resetplace;
      }
    }
  }
}
