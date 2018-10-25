#include <Calculator.h>

#define SERIAL_BPS  (9600)

int nInput = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  pinMode(nInput, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nVolt = digitalRead(nInput);
  if (nVolt == HIGH)  prints("High");
  else  prints("Low");
  println();
  delay(3000);  // ms
}
