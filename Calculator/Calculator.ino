#include <math.h>
#include <StringTok.h>

#define SERIAL_BPS  (9600)
#define PREC_DIGIT  (20)
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
  prints("======================================\r\n");
  prints("[Key] + - * / s(sin) c(cos) t(tan) e(exp) l(log)\r\n");
  prints("Select one of the above operations or functions:\r\n");
}

String decodeOpFun(char c) {
  switch (c) {
    case OP_SUM:  return "add (+)";
    case OP_SUB:  return "subtract (-)";
    case FUN_SIN: return "sine (sin)";
    case FUN_COS: return "cosine (cos)";
    default: return "wrong key";
  }
}

char scanOpFun() {
  char c; scans(c);
  prints("[Selected key] = "); prints(decodeOpFun(c)); println();
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
  double ans = 0.;
  switch (cOp) {
    case OP_SUM: ans = x1 + x2; break;
    case OP_SUB: ans = x1 - x2; break;
  }
  return ans;
}

double calcFun(char cFun, double x) {
  double ans = 0.;
  switch (cFun) {
    case FUN_SIN: ans = sin(x); break;
    case FUN_COS: ans = cos(x); break;
  }
  return ans;
}

void printAns(double x) {
  prints("Answer = ");
  Serial.print(x, PREC_DIGIT); println();
}
