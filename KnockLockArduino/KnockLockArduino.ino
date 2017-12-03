#include <Servo.h>

Servo servoPrivod;

const int pishalka = A0; 
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;
int knockVal;
int switchVal;
const int quietKnock = 10;
const int loudKnock = 100;
boolean locked = false;
int numberOfKnocks = 0;

void setup() 
{
  servoPrivod.attach(6);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  servoPrivod.write(0);
  Serial.println("korobka otkrita");
}

void loop() 
{
  if (locked == false) 
  {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH) 
    {
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      servoPrivod.write(90);
      Serial.println("korobka zakrita");
      delay(1000);
    }
  }

  if (locked == true) 
  {
    knockVal = analogRead(pishalka);
    if (numberOfKnocks < 3 && knockVal > 0) 
    {
      if (checkForKnock(knockVal) == true) 
      {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println("eshe nazhat nado");
    }

    if (numberOfKnocks >= 3) 
    {
      locked = false;
      servoPrivod.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("korobka otkrita");
      numberOfKnocks = 0;
    }
  }
}

boolean checkForKnock(int value) 
{
  if (value > quietKnock && value < loudKnock) 
  {
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Podtverdite");
    Serial.println(value);
    return true;
  }
  else 
  {
    Serial.print("Neudalos");
    Serial.println(value);
    return false;
  }
}
