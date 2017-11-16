// the setup routine runs once when you press reset:
// установка первоначальных надстроек выполняется единажды в начале программного кода
void setup() {
  // initialize serial communication at 9600 bits per second:
  // чтение с порта будет происходить со скоростью 9600 бит в секунду
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
// действие, которое будет происходить до выключения Arduino
void loop() {
  // read the input on analog pin 0:
  // считывает состояние аналогового порта
  int sensorValue = analogRead(A0);
  // аналоговый порт - А0
  // print out the value you read:
  // выводить в монитор порта информацию, которую Arduino получает через этот порт
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
  // информация обновляется каждые 0.001 секунд
}
