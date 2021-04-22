#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

#define echoPin 9 // Pin eco
#define trigPin 8 // Pin Trigger
int maximumRange = 200; // Rango maximo
int minimumRange = 0; // Rango minimo
float duration, distance; // Duracion usada para medir la duracion

void setup() {
 lcd.begin(16, 2);
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);

 //Medimos el tiempo que tarda en llegar el eco
 duration = pulseIn(echoPin, HIGH);
 //Calculamos la distancia
 distance = float (duration*0.017);
 
 //iniciamos el ciclo de la pantalla lcd
 PantallaLCD();
 }

 void PantallaLCD(){
            lcd.clear();
            lcd.write("Distancia");
            lcd.setCursor(0,1);
            lcd.write("d=");
            lcd.print(distance);
            lcd.write("cm");
            delay(400);
            return;      
}
