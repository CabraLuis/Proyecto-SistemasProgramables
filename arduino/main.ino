#include <SimpleWebSerial.h>

SimpleWebSerial WebSerial;

int outputPin = 2;
int sensorPin = 3;

void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(sensorPin, INPUT_PULLUP);
  Serial.begin(57600);
}

void loop() {
    bool sensorState = digitalRead(sensorPin);
    Serial.println(sensorState);

  if (sensorState) {
    digitalWrite(outputPin, LOW);
    WebSerial.send("smoke", "false");
  } else {
    digitalWrite(outputPin, HIGH);
    WebSerial.send("smoke", "true");
  }

  delay(100);
}