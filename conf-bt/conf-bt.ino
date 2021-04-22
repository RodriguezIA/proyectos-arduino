#include <SoftwareSerial.h>
 //incluimos biblioteca que permite definir un segundo puerto serial en los puertos digitales de Arduino

SoftwareSerial mySerial(10, 11);
// Definimos un segundo puerto serial, colocando el Pin 10 como RX y el Pin 11 como TX

void setup()
{
Serial.begin(9600);
mySerial.begin(38400);
while (!Serial) {
}
 Serial.println("Configuracion:");
}


void loop()
{
//Se leen los datos de los modulos Bluetooth simultaneamente para su configuracion
if (mySerial.available())
 Serial.write(mySerial.read());
if (Serial.available())
mySerial.write(Serial.read());
}
