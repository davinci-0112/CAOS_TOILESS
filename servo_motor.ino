#include  <Servo.h>
Servo myservo;         // create servo object to control a servo 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo control pin (orange)
}

void loop() {
  myservo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
  delay(3000); // หน่วงเวลา 1000ms
  myservo.write(45); // สั่งให้ Servo หมุนไปองศาที่ 45
  delay(3000); // หน่วงเวลา 1000ms
  myservo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
  delay(3000); // หน่วงเวลา 1000ms
  myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 90
  delay(3000); // หน่วงเวลา 1000ms
  myservo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
  delay(3000); // หน่วงเวลา 1000ms
  myservo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 90
  delay(3000); // หน่วงเวลา 1000ms

}        
