#include <Servo.h>

Servo servo_1;

const int sensorPin0 = A0;
const int sensorPin1 = A1;
const int sensorPin2 = A2;
int valor_potenciometro;

 
void setup() {
   Serial.begin(9600);
   servo_1.attach(9);
}
 
void loop() 
{
   int humedad = analogRead(sensorPin1);
   int temp = analogRead(sensorPin0);
   float millivolts =(temp/1023.0)*5000;
   float celsius = millivolts/10;

   valor_potenciometro = analogRead(sensorPin2);
   valor_potenciometro = map(valor_potenciometro, 0, 10223, 0, 180);
   servo_1.write(valor_potenciometro);
   
   
   Serial.print("Humedad: ");
   Serial.println(humedad);

   Serial.print("Temperarura: ");
   Serial.print(celsius);
   Serial.println(" C");

   
  

   delay(1);
}
