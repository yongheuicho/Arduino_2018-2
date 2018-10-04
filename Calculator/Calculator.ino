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
  prints("+ - * / s(sin) c(cos) t(tan) e(exp) l(log)\r\n");
  prints("Select one of the above operations or functions.\r\n");
}

char scanOpFun() {
  char c; scans(c);
  prints("Input operation or function = "); prints(c); println();
  return c;
}

double scanDouble() {
  prints("double = ");
  double x; scans(x); prints(x); println();
  return x;
}

void scanDouble2(double & x1, double & x2) {
  prints("x1 "); x1 = scanDouble();
  prints("x2 "); x2 = scanDouble();
}

double calcOp(char cOp, double x1, double x2) {
  return 0.;
}

double calcFun(char cFun, double x) {
  return 0.;
}

void printAns(double x) {

}
