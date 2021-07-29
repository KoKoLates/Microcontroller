int lastTime=0;
int currentTime=0;
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

void setup() {
  for(int i=2;i<=15;i++)
  {
    pinMode(i,OUTPUT);
  }
}

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

void loop() {
  for(byte tens=0;tens<6;++tens){
    for(byte unit=0;unit<10;++unit){
      unitWrite(unit);
      tensWrite(tens);
      while((currentTime-lastTime)<interval)
      {
        currentTime=millis(); 
      }
      lastTime=currentTime;
    }
  }
}
