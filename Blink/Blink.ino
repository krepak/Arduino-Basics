
// the setup function runs once when you press reset or power the board
// код в 'void setup' исполняется единажды, сразу после включения Arduino
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  // определение цифрового порта 'LED_BUILTIN' как порт вывода
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
// фрагмент этого кода будет исполняться до выключения
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  // turn the LED on (HIGH is the voltage level)
  // на светодиод подаётся максимально доступный вольтаж
  delay(1000);                       
  // wait for a second
  // предыдущее действие продолжается 1 секунду
  // 1000 значит 1 секунда, 500 значит 0,5 и так далее
  digitalWrite(LED_BUILTIN, LOW);    
  // turn the LED off by making the voltage LOW
  // на светодиод подаётся минимальный вольтаж
  // светодиод отключается
  delay(1000);                       
  // wait for a second
  // светодиод не горит 1 секунду
}
