const int ledPin = 4;
const int ldrPin = A0;
 
void setup() {
  pinMode(ledPin, OUTPUT);  
  pinMode(ldrPin, INPUT);
}
 
void loop() {
  int ldrStatus = analogRead(ldrPin);
  if (ldrStatus <=300) {
    digitalWrite(ledPin, HIGH);              
    delay(1000);
  }
  else {
    digitalWrite(ledPin, LOW);  
  }
  delay(100);
}
