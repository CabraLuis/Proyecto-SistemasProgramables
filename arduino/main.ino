#include <SimpleWebSerial.h>

SimpleWebSerial WebSerial;

int buttonPin = 3;
int ledPin = 2;
int sensorPin = A0;
int sensorThreshold = 500;
int analogSensor = 0;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(57600);
}

void loop() {
  // analogSensor = analogRead(sensorPin);
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    WebSerial.send("smoke", "true");
  } else {
    digitalWrite(ledPin, LOW);
    WebSerial.send("smoke", "false");
  }

  delay(50);

//   if (analogSensor > sensorThreshold) {
//     WebSerial.send("smoke", "true");
//     digitalWrite(ledPin, HIGH);
//   } else {
//     digitalWrite(ledPin, LOW);
//     WebSerial.send("smoke", "false");
//   }
}