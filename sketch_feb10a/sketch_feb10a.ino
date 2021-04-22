int valorLDR;
int brilloLED;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorLDR = analogRead(0);
  Serial.println(valorLDR);
  brilloLED = map(valorLDR, 0, 1023, 0, 255);
  analogWrite(5, brilloLED);
  delay(100);
}
