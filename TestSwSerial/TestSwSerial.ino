#include <SoftwareSerial.h>
#include <StringTok.h>

#define SERIAL_BPS    (9600)
#define SW_SERIAL_BPS (9600)
#define DELAY_MS      (1000)

SoftwareSerial swSerial(9, 10); // Rx, Tx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  swSerial.begin(SW_SERIAL_BPS);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Tx
  if (Serial.available() > 0) {
    StringTok stInput;
    stInput.inputSerial();
    String sInput = stInput.toString();
    Serial.println(sInput);
    swSerial.print(sInput);
  }

  delay(DELAY_MS);
}
