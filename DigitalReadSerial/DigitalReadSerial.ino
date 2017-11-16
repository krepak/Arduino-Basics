// digital pin 2 has a pushbutton attached to it. Give it a name:
// к цифровому порту 2 подключена кнопка, котрую можно нажимать
// ей дают название 'pushButton'
int pushButton = 2;

// the setup routine runs once when you press reset:
// этот алгоритм повторяется всего один раз
void setup() {
  // initialize serial communication at 9600 bits per second:
  // компьютер принимает информацию с скоростью 9600 бит в секунду
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  // эта строчка говорит о том, что Arduino готова принимать 
  // сигнал с этой кнопки 'pushButton'
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
// этот алгоритм будет повторяться до выключения Arduino
void loop() {
  // read the input pin:
  // считывает информацию с пина
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  // получил информацию с порта и вывел её в монитор порта
  Serial.println(buttonState);
  delay(1);        
  // delay in between reads for stability
  // повторение предыдущего действия 0.001 секунду
}



