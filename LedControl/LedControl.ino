#include <StringTok.h>

#define SERIAL_BPS  (9600)

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

}

void controlLed() {
  StringTok stInput = getLedStr();
  parseLedControl(stInput);
}

StringTok getLedStr() {

}

void parseLedControl(StringTok & stInput) {
  StringTok stToken = stInput.getToken();
  if (stToken.toString() == "start") startLed();
  else if (stToken.toString() == "stop") stopLed();
  else if (sttoken.toString() == "led") onOffLed();
}

void startLed() {
  
}

void stopLed() {
  
}

void onOffLed() {
  
}
