#include <SimpleWebSerial.h>

SimpleWebSerial WebSerial;

int outputPin = 2;
int sensorPin = A0;

void setup() {
  pinMode(outputPin, OUTPUT);
  Serial.begin(57600);
}

void loop() {
    float sensorState = analogRead(sensorPin);
    Serial.println(sensorState);

  if (sensorState > 300.00) {
    digitalWrite(outputPin, HIGH);
    WebSerial.send("smoke", sensorState);
  } else {
    digitalWrite(outputPin, LOW);
    WebSerial.send("smoke", sensorState);
  }

  delay(100);
}