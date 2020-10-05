int sensorL = A0;
int sensorR = A1;
int motorL1 = 3;
int motorL2 = 4;
int motorR1 = 5;
int motorR2 = 6;
int enA = 9;
int enB = 8;
int LS = 100; //lowspeed
int HS = 255; //Highspeed
int sensorLvalue = 0;
int sensorRvalue = 0;
int sensorMQ = A2;
int MQ = 0;
int led = 7;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensorL,INPUT);
pinMode(sensorR,INPUT);
pinMode(motorL1,OUTPUT);
pinMode(motorL2,OUTPUT);
pinMode(motorR1,OUTPUT);
pinMode(motorR2,OUTPUT);
pinMode(sensorMQ,INPUT);
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(led,OUTPUT);
digitalWrite(led,1);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorLvalue = analogRead(sensorL);
sensorRvalue = analogRead(sensorR);
MQ = analogRead(sensorMQ);
Serial.print(sensorLvalue);
Serial.print("  ");
Serial.print(sensorRvalue);
Serial.print("  ");
Serial.println(MQ);
if(MQ < 500){
  
if(sensorLvalue < 100 && sensorRvalue < 100){
  digitalWrite(motorL1,1);
  digitalWrite(motorL2,0);---
  digitalWrite(motorR1,1);
  digitalWrite(motorR2,0);
  //analogWrite(enA,HS);
  //analogWrite(enB,HS);
}
else if(sensorLvalue > 100 && sensorRvalue < 100){
  digitalWrite(motorL1,0);
  digitalWrite(motorL2,0);
  digitalWrite(motorR1,1);
  digitalWrite(motorR2,0); 
  //analogWrite(enA,HS);
  //analogWrite(enB,HS);
}
else if(sensorLvalue < 100 && sensorRvalue > 100){
  digitalWrite(motorL1,1);
  digitalWrite(motorL2,0);
  digitalWrite(motorR1,0);
  digitalWrite(motorR2,0);
  //analogWrite(enA,HS);
  //analogWrite(enB,HS);
}
else if(sensorLvalue > 100 && sensorRvalue > 100){
  digitalWrite(motorL1,0);
  digitalWrite(motorL2,0);
  digitalWrite(motorR1,0);
  digitalWrite(motorR2,0);
  //analogWrite(enA,HS);
  //analogWrite(enB,HS);
}
}
else if(MQ > 501){
  digitalWrite(motorL1,0);
  digitalWrite(motorL2,0);
  digitalWrite(motorR1,0);
  digitalWrite(motorR2,0);
  digitalWrite(led,0);
  delay(500);
  digitalWrite(led,1);
  delay(500);

  }
}
