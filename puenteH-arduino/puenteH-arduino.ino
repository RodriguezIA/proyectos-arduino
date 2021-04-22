//Código para utilizar motor con puente H
int LeftPin=8; //Pines de salida del Arduino
int RightPin=9;
int input=0;

void setup(){
    Serial.begin(9600);
    pinMode(LeftPin, OUTPUT);
    pinMode(RightPin, OUTPUT);
}

void loop(){
    if (Serial.available()){
    if (input=='1'){ //El motor girará a la derecha
    digitalWrite(LeftPin, LOW);
    digitalWrite(RightPin, HIGH);
    }
    else if (input=='2'){ //El motor girará a la izquierda
    digitalWrite(LeftPin, HIGH);
    digitalWrite(RightPin, LOW);
    }
    else if (input=='0'){ //El motor se detendrá
    digitalWrite(LeftPin, LOW);
    digitalWrite(RightPin, LOW);
    }
    delay(10);
    }
}
