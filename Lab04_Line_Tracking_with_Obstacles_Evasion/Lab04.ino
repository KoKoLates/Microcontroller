void setup(){
  Serial.begin(9600);
  pinMode(12, OUTPUT); 
  digitalWrite(12, LOW); 
  pinMode(13, INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop(){
  digitalWrite(12, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(12, LOW); 
  int distance = pulseIn(13, HIGH); 
  distance=distance / 58; 
  Serial.println(distance);
  
  int RightIR=analogRead(A3);
  int MiddleIR=analogRead(A2);
  int LeftIR=analogRead(A1);
  analogWrite(5,0);
  analogWrite(6,50);
  analogWrite(10,50);
  analogWrite(11,0);

  if(distance<15){
    for(int i=50;i>=0;i--){
      analogWrite(6,i);
      delay(15);}
    for(int i=50;i>=0;i--){
      analogWrite(10,i);
      delay(15);}
    analogWrite(5,0);
    analogWrite(6,50);
    analogWrite(10,50);
    analogWrite(11,0);
    delay(400);
    for(int i=50;i>=0;i--){
      analogWrite(10,i);
      delay(15);}
    for(int i=50;i>=0;i--){
      analogWrite(6,i);
      delay(15);}
    analogWrite(5,0);
    analogWrite(6,50);
    analogWrite(10,50);
    analogWrite(11,0);
    delay(400); 
    for(int i=50;i>=0;i--){
      analogWrite(10,i);
      delay(15);}
    for(int i=50;i>=0;i--){
      analogWrite(6,i);
      delay(15);}
    analogWrite(5,0);
    analogWrite(6,50);
    analogWrite(10,50);
    analogWrite(11,0);
    delay(400); 
  }
  
  if(RightIR>500){
    analogWrite(5,0);
    analogWrite(6,40);
    analogWrite(10,0);
    analogWrite(11,0);
  }
  if(LeftIR>500){
    analogWrite(5,0);
    analogWrite(6,0);
    analogWrite(10,40);
    analogWrite(11,0);
  }
}
