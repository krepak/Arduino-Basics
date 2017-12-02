#include <Process.h>

void setup() {
  SerialUSB.begin(9600);
  while (!SerialUSB);

  SerialUSB.println("Most startuyet...\n");
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);
  delay(1500);
}

void loop() {
  Process wifiCheck;
  wifiCheck.runShellCommand("/usr/bin/pretty-wifi-info.lua");
  while (wifiCheck.available() > 0) {
    char c = wifiCheck.read();
    SerialUSB.print(c);
  }
  SerialUSB.println();
  delay(2500);
}
