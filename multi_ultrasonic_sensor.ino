#include  <Servo.h>
Servo caosservo;

#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 7
#define echoPin3 8
long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  caosservo.attach(9);
  caosservo.write(0);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
SonarSensor(trigPin3, echoPin3);
FrontSensor = distance;

Serial.print(LeftSensor);
Serial.print(" - ");
Serial.print(FrontSensor);
Serial.print(" - ");
Serial.println(RightSensor);

if(LeftSensor < 5){
  caosservo.write(90);
  }
if(RightSensor < 5){
  caosservo.write(0);
  }
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
