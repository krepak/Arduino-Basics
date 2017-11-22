#include<Servo.h>

const int greenpin1 = 3;
const int yellowpin1 = 4;
const int redpin1 = 5;
const int greenpin2 = 6;
const int yellowpin2 = 7;
const int redpin2 = 8;
const int servopin = 9;
const int trigpin = 10;
const int echopin = 11;

Servo zhanServo;
float distance;
float duration;

void setup() {
  
  pinMode(greenpin1,OUTPUT);
  pinMode(yellowpin1,OUTPUT);
  pinMode(redpin1,OUTPUT);
  pinMode(greenpin2,OUTPUT);
  pinMode(yellowpin2,OUTPUT);
  pinMode(redpin2,OUTPUT);
  
  zhanServo.attach(servopin);
  
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  
  zhanServo.write(0);
  
  digitalWrite(greenpin1,HIGH);
  delay(100);
  
  digitalWrite(redpin2,HIGH);
  delay(100);
  
  Serial.begin(9600);
}

void loop() {
  
  lane2();
  delay(5000);
  
  lane1();
  delay(5000);
  
}

int turnGreen(int pinNo,int delayy)
{
  
  digitalWrite(pinNo,HIGH);
  delay(delayy);
  
}

int turnYellow(int pinNo,int delayy)
{
  
  digitalWrite(pinNo,HIGH);
  delay(delayy);
  
}

int turnRed(int pinNo,int delayy)
{
  
  digitalWrite(pinNo,HIGH);
  delay(delayy);
  
}

int checkTraffic()
{
  digitalWrite(trigpin,HIGH);
  delay(100);
  
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = duration * 0.034/2;
  
  Serial.print("Distance:");
  Serial.println(distance);
  return(distance);
  
}

void lane1()
{
  
  zhanServo.write(90);
  checkTraffic();
  
  int lastCar  = checkTraffic();
  delay(2000);
  for(int i=90;i<=180;i=i+30)
  {
    zhanServo.write(i);
  }
  if(lastCar > 150)
  {
   digitalWrite(redpin2,LOW);
   turnYellow(yellowpin2,2000);
   
   digitalWrite(yellowpin2,LOW);
   if(lastCar > 150)
   {
    turnGreen(greenpin2,10*1000); 
   }
   delay(1000); 
  }
  else if(lastCar <= 110)
  {
   runNormal();
  }
}

void lane2()
{
  
    checkTraffic();
  int lastCar  = checkTraffic();
  
  zhanServo.write(90);
  delay(2000);
  for(int i=90;i>=0;i=i-30)
  {
    zhanServo.write(i);
  }
  if(lastCar > 150)
  {
    
   digitalWrite(redpin1,LOW);
   turnYellow(yellowpin1,2000);
   
   digitalWrite(yellowpin1,LOW);
   checkTraffic();
   
   int lastCar  = checkTraffic();
   if(lastCar > 150)
   {
    turnGreen(greenpin1,10*1000); 
   }
   else
   {
    turnRed(redpin1,10*1000);
   }
   delay(1000);
  }
  else if(lastCar < 110)
  {
    runNormal();
  }
}

void runNormal()
{
  
    delay(10000);
    digitalWrite(greenpin1,LOW);
    digitalWrite(yellowpin1,HIGH);
    
    delay(2000);
    digitalWrite(redpin2,LOW);
    digitalWrite(yellowpin2,HIGH);
    
    delay(1000);
    digitalWrite(yellowpin1,LOW);
    digitalWrite(redpin1,HIGH);
    
    delay(2000);
    digitalWrite(yellowpin2,LOW);
    digitalWrite(greenpin2,HIGH);
    
    delay(10000);
    digitalWrite(redpin1,LOW);
    digitalWrite(yellowpin1,HIGH);
    
    delay(1000);
    digitalWrite(greenpin2,LOW);
    digitalWrite(yellowpin2,HIGH);
    
    delay(2000);
    digitalWrite(yellowpin2,LOW);
    digitalWrite(redpin2,HIGH);
    
    delay(2000);
    digitalWrite(yellowpin1,LOW);
    digitalWrite(greenpin1,HIGH);
    
}

