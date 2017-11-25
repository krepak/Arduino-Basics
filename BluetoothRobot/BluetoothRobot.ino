#include <RemoteXY.h>    
#include <Servo.h>  

#define REMOTEXY_SERIAL Serial  
#define REMOTEXY_SERIAL_SPEED 9600  
#define PIN_LED_LEFT 2
#define PIN_LED_RIGHT 3 
#define PIN_LEFT_SERVO 4 
#define PIN_RIGHT_SERVO 5 
#define PIN_HEAD_SERVO 6 
#define REMOTEXY_MODE__SERIAL

Servo left_servo; 
Servo right_servo; 
Servo head_servo; 

unsigned char RemoteXY_CONF[] =  
  { 6,0,79,0,1,5,4,0,5,7 
  ,11,56,2,4,0,84,7,11,56,2 
  ,4,128,20,13,60,11,2,129,0,26 
  ,3,49,6,0,208,161,97,114,100,98 
  ,111,97,114,100,32,82,111,98,111,116 
  ,0,1,0,25,29,16,16,1,76,0 
  ,1,0,60,29,16,16,1,82,0,2 
  ,0,38,51,24,10,2,79,78,0,79 
  ,70,70,0 };  
    
struct {  
  unsigned char slider_left;
  unsigned char slider_right;
  unsigned char slider_head; 
  unsigned char button_left; 
  unsigned char button_right; 
  unsigned char switch_1; 
  unsigned char connect_flag; 
} 
RemoteXY;  

unsigned char led_state = 0; 
unsigned long led_time=0; 
unsigned long prev_time=0; 

void setup()   
{  
  RemoteXY_Init ();   
   
  pinMode (PIN_LED_LEFT, OUTPUT); 
  pinMode (PIN_LED_RIGHT, OUTPUT); 
 
  left_servo.attach(PIN_LEFT_SERVO); 
  right_servo.attach(PIN_RIGHT_SERVO); 
  head_servo.attach(PIN_HEAD_SERVO); 

  RemoteXY.slider_left=50; 
  RemoteXY.slider_right=50; 
  RemoteXY.slider_head=50; 
}  

void loop()   
{   
  RemoteXY_Handler ();  
    
  unsigned long time = millis(); 
  unsigned long d_time = time - prev_time; 
  prev_time = time; 
  if (RemoteXY.switch_1==0) { 
    digitalWrite(PIN_LED_LEFT, (RemoteXY.button_left==0)?LOW:HIGH); 
    digitalWrite(PIN_LED_RIGHT, (RemoteXY.button_right==0)?LOW:HIGH); 
  } 
  else 
  { 
    led_time+=d_time; 
    if (led_time>500) 
    { 
      if (led_state==0) led_state=1; 
      else  led_state=0; 
      led_time-=500; 
    } 
    digitalWrite(PIN_LED_LEFT, (led_state==0)?LOW:HIGH); 
    digitalWrite(PIN_LED_RIGHT, (led_state==1)?LOW:HIGH);     
  } 
  left_servo.writeMicroseconds(RemoteXY.slider_left*20+500);  
  right_servo.writeMicroseconds(2500-RemoteXY.slider_right*20);  
  head_servo.writeMicroseconds(RemoteXY.slider_head*20+500);  
} 
