const int buttonPin = 2;    
//the number of the pushbutton pin
//пин, к которому подключена кнопка
const int ledPin = 3;      
//the number of the led pin
//пин, к которому подключен светодиод

int ledState = HIGH;         
//the current state of the output pin
//задает состояние пина, который будет отвечать за светодиод
int buttonState;             
//the current reading from the input pin
//задается состояние пина, которое будет отвечать за нажатия кнопки
int lastButtonState = LOW;   
//the previous reading from the input pin
//распознает последнее состояние пина ввода с кнопкой

//the following variables are unsigned long's because the time, measured in miliseconds,
//will quickly become a bigger number than can be stored in an int
//переменные задаются типом 'long', потому что время будет измеряться в миллисекундах
//большое значение приняло бы тип 'int'
unsigned long lastDebounceTime = 0;  
//the last time the output pin was toggled
//последнее время, когда пин вывода был изменен
unsigned long debounceDelay = 50;    
//the debounce time
//время отладки

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  //set initial led state
  //включает светодиод
  digitalWrite(ledPin, ledState);
}

void loop() {
  //read the state of the switch into a local variable
  //читатет последнее состояние и присвает его к локальной переменной
  int reading = digitalRead(buttonPin);

  //check to see if you just pressed the button
  //проверяет, нажата ли только что кнопка
  
  //if the switch changed
  //если значение изменено, то выполняется такое условие
  if (reading != lastButtonState) {
    //reset the debouncing timer
    //сбивает таймер
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    //whatever the reading is at, it is been there for longer
    //than the debounce delay, so take it as the actual current state
    //сравнивает 2 последних состояния

    //if the button state has changed
    //если состояние кнопки изменилось
    if (reading != buttonState) {
      buttonState = reading;

      //only toggle the led if the new button state is 'HIGH'
      //светодиод активируется, прочитав значение кнопки
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  //set the led
  //включает светодиод
  digitalWrite(ledPin, ledState);

  //save the reading, next time through the loop,
  //it will be the lastButtonState:
  /сохраняет последнее значение и записывает в переменную 'lastButtonState'
  lastButtonState = reading;
}

