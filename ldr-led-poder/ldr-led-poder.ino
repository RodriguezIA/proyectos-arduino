int analogPin = 3;
int digitalPin = 13;
int delayTime = 50;
int ldrPin = A5;

void setup(){
Serial.begin(9600);
pinMode(analogPin, OUTPUT);
}

void loop(){
int power = 255 - analogRead(ldrPin) / (1023 / 255);
analogWrite(analogPin, power);
digitalWrite(digitalPin, HIGH);
delay(delayTime);
Serial.println(analogRead(ldrPin));
}
