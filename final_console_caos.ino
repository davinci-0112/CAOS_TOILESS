#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 7
#define MQPIN A0
#define car 8
#define alco 9

int mqvalue = 0;

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(MQPIN,INPUT);
  pinMode(car,OUTPUT);
  pinMode(alco,OUTPUT);
  digitalWrite(car,1);
  digitalWrite(alco,1);
  lcd.begin();
  lcd.backlight();
  dht.begin();
  lcd.setCursor(7, 0); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print("Welcome");
  lcd.setCursor(9, 1); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print("To");
  lcd.setCursor(8, 2); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print("CAOS");
  lcd.setCursor(9, 3); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print(">_<");
  delay(5000);
  lcd.clear();
}

void loop() {

  if(mqvalue < 500){
    digitalWrite(car,0);
    digitalWrite(alco,1);
  }
  else if(mqvalue > 500){
    digitalWrite(car,1);
    digitalWrite(alco,0);
  }

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  mqvalue = analogRead(MQPIN);
  
  lcd.setCursor(0, 0); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print("Temp : ");
  lcd.print(h);
  lcd.print(" C");
  lcd.setCursor(0, 1); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print("Heat : ");
  lcd.print(hic);
  lcd.print(" C");
  lcd.setCursor(0, 2); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print("Alcohol : ");
  lcd.print(mqvalue);
  lcd.setCursor(0, 3); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
  lcd.print("CAOS RUNNING...");
  
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.print(F("°F"));
  Serial.print("  Alcohol : ");
  Serial.println(mqvalue);
}
