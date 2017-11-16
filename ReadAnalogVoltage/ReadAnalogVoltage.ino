// the setup routine runs once when you press reset:
// повторяется один раз
void setup() {
  // initialize serial communication at 9600 bits per second:
  // устанавливается скорость обновления - 9600 бит в секунду
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
// этот алгоритм будет повторяться до выключения Arduino
void loop() {
  // read the input on analog pin 0:
  // считывает входной сигнал с аналогового порта Arduino под номером 0
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  // конвертирует аналоговый сигнал в величину в вольтах (от 0 до 5 вольт)
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  // выводит значение, которое прочитал порт
  Serial.println(voltage);
}
