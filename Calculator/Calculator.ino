#include <StringTok.h>

#define SERIAL_BPS  (9600)
#define OP_SUM    ('+')
#define OP_SUB    ('-')
#define FUN_SIN   ('s')
#define FUN_COS   ('c')

void setup() {
  // put your setup code here, to run once:
  Serial.begin(SERIAL_BPS);
}

void loop() {
  // put your main code here, to run repeatedly:
  calculator();
}

void calculator() {
  printOpFun();
  char cOpFun = scanOpFun();
  double ans;
  if (isOp(cOpFun)) {
    double x1, x2;
    scanDouble2(x1, x2);
    ans = calcOp(cOpFun, x1, x2);
  }
  else {
    double x = scanDouble();
    ans = calcFun(cOpFun, x);
  }
  printAns(ans);
}

boolean isOp(char cOpFun) {
  if (cOpFun == OP_SUM || cOpFun == OP_SUB) return true;
  else  return false;
}
void printOpFun() {
  prints("Select operation or function:");
}

char scanOpFun() {
  return '.';
}

double scanDouble() {
  return 0.;
}

void scanDouble2(double & x1, double & x2) {
  x1 = scanDouble();
  x2 = scanDouble();
}

double calcOp(char cOp, double x1, double x2) {
  return 0.;
}

double calcMath(char cFun, double x) {
  return 0.;
}

void printAns(double x) {

}
