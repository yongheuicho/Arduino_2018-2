#pragma once

#include <StringTok.h>


class LedCtrl {
public:
	boolean bLedControl;

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
		else if (stToken.toString() == "turn") turnLed(stInput);
	}

	void startLed() {
		bLedControl = true;
	}

	void stopLed() {
		bLedControl = false;
	}

	void turnLed(StringTok & stInput) {
		if (!bLedControl) return;
		StringTok stToken;
		stToken = stInput.getToken(); // #led
		int nLed = stToken.toInt();
		stToken = stInput.getToken(); // "on" or "off"
		if (stToken.toString() == "on") digitalWrite(nLed, HIGH);
		else if (stToken.toString() == "off") digitalWrite(nLed, LOW);
	}
};