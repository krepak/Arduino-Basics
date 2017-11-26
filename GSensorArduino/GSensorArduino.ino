
#define REMOTEXY_MODE__SOFTWARESERIAL  
#include <SoftwareSerial.h>  
#include <RemoteXY.h>  
#define REMOTEXY_SERIAL_RX 2  
#define REMOTEXY_SERIAL_TX 3  
#define REMOTEXY_SERIAL_SPEED 9600  
#define PIN_MOTOR_RIGHT_UP 4
#define PIN_MOTOR_RIGHT_DN 5
#define PIN_MOTOR_RIGHT_SPEED 6 
#define PIN_MOTOR_LEFT_UP 7
#define PIN_MOTOR_LEFT_DN 8
#define PIN_MOTOR_LEFT_SPEED 9 
#define PIN_LED 10

unsigned char RemoteXY_CONF[] =  
  { 3,0,23,0,1,5,5,15,41,11 
  ,43,43,1,2,0,6,5,27,11,5 
  ,79,78,0,79,70,70,0 };  
    
struct {  
  signed char joystick_1_x;
  signed char joystick_1_y;
  unsigned char switch_1;
  unsigned char connect_flag;
} 
RemoteXY;

unsigned char RightMotor[3] =  
  {PIN_MOTOR_RIGHT_UP, PIN_MOTOR_RIGHT_DN, PIN_MOTOR_RIGHT_SPEED}; 
unsigned char LeftMotor[3] =  
  {PIN_MOTOR_LEFT_UP, PIN_MOTOR_LEFT_DN, PIN_MOTOR_LEFT_SPEED}; 

void Wheel (unsigned char * motor, int v) 
{ 
  if (v>100) v=100; 
  if (v<-100) v=-100; 
  if (v>0) { 
    digitalWrite(motor[0], HIGH); 
    digitalWrite(motor[1], LOW); 
    analogWrite(motor[2], v*2.55); 
  } 
  else if (v<0) { 
    digitalWrite(motor[0], LOW); 
    digitalWrite(motor[1], HIGH); 
    analogWrite(motor[2], (-v)*2.55); 
  } 
  else { 
    digitalWrite(motor[0], LOW); 
    digitalWrite(motor[1], LOW); 
    analogWrite(motor[2], 0); 
  } 
} 

void setup() 
{ 
  pinMode (PIN_MOTOR_RIGHT_UP, OUTPUT); 
  pinMode (PIN_MOTOR_RIGHT_DN, OUTPUT); 
  pinMode (PIN_MOTOR_LEFT_UP, OUTPUT); 
  pinMode (PIN_MOTOR_LEFT_DN, OUTPUT); 
  pinMode (PIN_LED, OUTPUT); 
  RemoteXY_Init (); 
} 

void loop() 
{ 
  RemoteXY_Handler (); 
  digitalWrite (PIN_LED, (RemoteXY.switch_1==0)?LOW:HIGH); 
  Wheel (RightMotor, RemoteXY.joystick_1_y - RemoteXY.joystick_1_x); 
  Wheel (LeftMotor, RemoteXY.joystick_1_y + RemoteXY.joystick_1_x); 
} 
