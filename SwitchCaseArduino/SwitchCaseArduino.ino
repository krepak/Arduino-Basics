const int sensorMin = 0;      // sensor minimum, discovered through experiment
const int sensorMax = 600;    // sensor maximum, discovered through experiment

void setup() 
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  switch (range) {
    case 0:
      Serial.println("temno");
      break;
    case 1:
      Serial.println("dim");
      break;
    case 2:
      Serial.println("poydet");
      break;
    case 3:
      Serial.println("yarko");
      break;
  }
  delay(1);
}
