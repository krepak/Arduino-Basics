
//constants is not change, i will use here to set a pin port
//положение лед-светодиода не изменяеся, я буду использовать светодиод на 3 пине
const int ledPin =  3;      
//the number of the led

//variables will change 
//значение переменных будет меняться
int ledState = LOW;             
//'ledState' used to set the led
//'ledState' используется чтобы обозначить светодиод

//you should use "unsigned long" for variables that hold time
//еhe value will quickly become too large for an int to store
//эта строка используется для переменных, которые остаются неизменными 
//заданное пользователем время
unsigned long previousMillis = 0;        
//will store last time led was updated
//получает последнее состояние светодиода

//constants won't change 
//постоянная величина не будет изменяться
const long interval = 1000;           
//interval at which to blink (milliseconds)
//задается интервал мигания в миллисекундах

void setup() {
  //set the digital pin as output
  //определеяет цифровой пин как пин вывода
  pinMode(ledPin, OUTPUT);
}

void loop() {
  //code that needs to be running all the time
  //код, который будет исполняться до выключения Arduino

  //check to see if it's time to blink the led, that is, if the
  //difference between the current time and last time you blinked
  //the led is bigger than the interval at which you want to
  //blink the led
  //команда для сравнения времени мелькания светодиода между реальным временем 
  //и частотой включения-отключения
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    //save the last time you blinked the led
    //считывает время, когда светодиод последний раз моргнул
    previousMillis = currentMillis;

    //if the LED is off turn it on and vice-versa
    //условие, которое будет выполняться если светодиод выключен
    if (ledState == LOW) {
      ledState = HIGH;
      //условие, которое будет выполняться если светодиод включен
    } else {
      ledState = LOW;
    }

    //set the led with the ledState of the variable
    //изменяет переменную через 'ledState'
    digitalWrite(ledPin, ledState);
  }
}

