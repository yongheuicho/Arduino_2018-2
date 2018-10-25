#include <Calculator.h>

#define SERIAL_BPS  (9600)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
}

void loop() {
  // put your main code here, to run repeatedly:
  StringTok stStr;
  scans(stStr);
  prints(stStr); println();
  StringTok stToken;
  stToken = stStr.getToken(); // Number1
  double x1 = stToken.toDouble(); // String -> double
  prints(x1); println();
  stToken = stStr.getToken(); // Operation
  char cOp = stToken[0]; // String -> char
  prints(cOp); println();
  stToken = stStr.getToken(); // Number2
  double x2 = stToken.toDouble(); // String -> double
  prints(x2); println();
  double ans;
  if (cOp == '+') ans = x1 + x2;
  else if (cOp == '*') ans = x1 * x2;
  prints("Answer = "); prints(ans); println();
}
