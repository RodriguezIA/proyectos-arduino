#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

const int sensorPin = A0;
float SUMA;

void setup(){
  lcd.begin(16,2);
}

void loop(){
  SUMA=0;
  for(int i=0; i<5; i++){
  int value = analogRead(sensorPin);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  SUMA = celsius + SUMA;
  delay(500);
  }

  lcd.setCursor(0,0);
  lcd.print("TEMP: ");
  lcd.print(SUMA/5.0,1);
}

