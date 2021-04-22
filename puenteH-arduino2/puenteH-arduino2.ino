int LeftPin=8;
int RightPin=9;
int input=0;


void setup() {
 Serial.begin(9600);
 pinMode(LeftPin, OUTPUT);
 pinMode(RightPin, OUTPUT);
}

void loop() {
  if(Serial.available()){
    if(input=='1'){
      digitalWrite(LeftPin, LOW);
      digitalWrite(RightPin, HIGH);
    }
    else if(input=='2'){
      digitalWrite(LeftPin, HIGH);
      digitalWrite(RightPin, LOW);
    }
    else if(input=='0'){
      digitalWrite(LeftPin, LOW);
      digitalWrite(RightPin, LOW); 
    }
  }
  delay(10);
}
