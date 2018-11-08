#include <SoftwareSerial.h>

#define SERIAL_BPS    (9600)
#define SW_SERIAL_BPS (9600)

SoftwareSerial swSerial(9, 10); // Rx, Tx

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  swSerial.begin(SW_SERIAL_BPS);
}

void loop() {
  // put your main code here, to run repeatedly:

}
