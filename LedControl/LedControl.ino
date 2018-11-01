#include <StringTok.h>

#define SERIAL_BPS  (9600)

boolean bLedControl;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
  initLed();
}

void loop() {
  // put your main code here, to run repeatedly:
  controlLed();
}

void initLed() {
  pinMode(13, OUTPUT);
  bLedControl = false;
}

void controlLed() {
  StringTok stInput = getLedStr();
  parseLedControl(stInput);
}

StringTok getLedStr() {
  StringTok stInput;
  scans(stInput);
  prints(stInput); println();
  return stInput;
}

void parseLedControl(StringTok & stInput) {
  StringTok stToken = stInput.getToken();
  if (stToken.toString() == "start") startLed();
  else if (stToken.toString() == "stop") stopLed();
  else if (stToken.toString() == "led") onOffLed();
}

void startLed() {
  bLedControl = true;
}

void stopLed() {
  bLedControl = false;
}

void onOffLed() {
  if (!bLedControl) return;
}
