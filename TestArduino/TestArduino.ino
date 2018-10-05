#include <Calculator.h>

#define SERIAL_BPS  (9600)

int nLed = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  pinMode(nLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(nLed, HIGH);
  delay(1000);  // ms
  digitalWrite(nLed, LOW);
  delay(1000);  // ms
}
