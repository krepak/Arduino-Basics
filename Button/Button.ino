//constants will not change
//they are used here to set pin numbers
const int buttonPin = 2;     
//the number of the pushbutton pin
//пин, к которому подключена нажимаемая кнопка
const int ledPin =  3;      
//the number of the led pin
//пин, к которому подключен светодиод

//variables will change
//по мере выполнения кода, значения переменных будут обновляться
int buttonState = 0;         
//variable for reading the pushbutton status
//первоначальное значение для кнопки

void setup() {
  //initialize the led pin as an output
  //определяет пин с светодиодом как пин вывода
  pinMode(ledPin, OUTPUT);
  //initialize the pushbutton pin as an input
  //определяет пин с кнопкой как пин ввода
  pinMode(buttonPin, INPUT);
}

void loop() {
  //read the state of the pushbutton value
  //считывает состояние кнопки
  buttonState = digitalRead(buttonPin);

  //check if the pushbutton is pressed
  //проверяет, нажата ли кнопка
  //if it is, the buttonState is HIGH
  //если кнопка нажата, то состояние 'buttonState' меняется на
  //'HIGH'
  if (buttonState == HIGH) {
    //turn led on
    //включает светодиод
    digitalWrite(ledPin, HIGH);
  } else {
    //turn led off
    //выключает светодиод
    digitalWrite(ledPin, LOW);
  }
}
