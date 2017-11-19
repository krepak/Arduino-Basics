#include <Servo.h>
//servo library
//подключение библиотеки сервопривода
Servo servozhan1;
Servo servozhan2;
Servo servozhan3;
Servo servozhan4;
Servo servozhan5;
//5 servomotors
//объявление 5 сервомоторов
position servoPos;
//position as 'servoPos'
//измеряем позицию сервопривода через 'servoPos'


void setup() {

  int servoPos = 0;
  //position = 0
  //первоначальное положение сервопривода

  servozhan1.attach(2);
  servozhan2.attach(3);
  servozhan3.attach(4);
  servozhan4.attach(5);
  servozhan5.attach(6);
  //connecting to arduino
  //подключение всех сервоприводов
  
}

void loop() {
}
