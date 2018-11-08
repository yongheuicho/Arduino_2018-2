#include <SoftwareSerial.h>
#include <StringTok.h>

#define SERIAL_BPS    (9600)
#define SW_SERIAL_BPS (9600)
#define DELAY_MS      (50)
#define INPUT_DELAY_MS  (10)

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
    while (Serial.available() > 0) {
      stInput.appendSerial();
      delay(INPUT_DELAY_MS);
    }
    String sInput = stInput.toString();
    Serial.println(sInput);
    swSerial.print(sInput);
  }

  // Rx
  if (swSerial.available() > 0) {
    StringTok stInput;
    while (swSerial.available() > 0) {
      stInput.appendSerial(swSerial);
      delay(INPUT_DELAY_MS);
    }
    String sInput = stInput.toString();
    Serial.println(sInput);
  }

  delay(DELAY_MS);
}
