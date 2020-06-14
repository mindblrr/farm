int buzzer = 10;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 20;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  /*if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }*/
  

  if (sensorThres > 0 && sensorThres <50){
    tone(buzzer, 1000, 200);
  }

  if (sensorThres >= 50 && sensorThres <100){
        noTone(buzzer);
  }
  delay(100);
}
