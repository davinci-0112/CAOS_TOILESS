int sensorL = A0;
int sensorR = A1;
int motorL1 = 3;
int motorL2 = 4;
int motorR1 = 5;
int motorR2 = 6;
int sensorLvalue = 0;
int sensorRvalue = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensorL,INPUT);
pinMode(sensorR,INPUT);
pinMode(motorL1,OUTPUT);
pinMode(motorL2,OUTPUT);
pinMode(motorR1,OUTPUT);
pinMode(motorR2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorLvalue = analogRead(sensorL);
sensorRvalue = analogRead(sensorR);
Serial.print(sensorLvalue);
Serial.print("  ");
Serial.println(sensorRvalue);

if(sensorLvalue < 100 && sensorRvalue < 100){
  digitalWrite(motorL1,1);
  digitalWrite(motorL2,0);
  digitalWrite(motorR1,1);
  digitalWrite(motorR2,0);
}
else if(sensorLvalue > 100 && sensorRvalue < 100){
  digitalWrite(motorL1,0);
  digitalWrite(motorL2,0);
  digitalWrite(motorR1,1);
  digitalWrite(motorR2,0);
}
else if(sensorLvalue < 100 && sensorRvalue > 100){
  digitalWrite(motorL1,1);
  digitalWrite(motorL2,0);
  digitalWrite(motorR1,0);
  digitalWrite(motorR2,0);
}
else if(sensorLvalue > 100 && sensorRvalue > 100){
  digitalWrite(motorL1,0);
  digitalWrite(motorL2,0);
  digitalWrite(motorR1,0);
  digitalWrite(motorR2,0);
}
}
