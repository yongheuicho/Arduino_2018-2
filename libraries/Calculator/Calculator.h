#pragma once

#include <math.h>
#include <StringTok.h>

#define PREC_DIGIT  (20)
#define OP_SUM    ('+')
#define OP_SUB    ('-')
#define FUN_SIN   ('s')
#define FUN_COS   ('c')

class Calculator {
public:
	void home() {
		printHome();
		while (1) {
			String sCommand = scanHomeCommand();
			if (parseHomeCommand(sCommand)) break;
			println();
		}
		println();
	}

	void calc() {
		printCalcHome();
		while (1) {
			String sCommand = scanCalcCommand();
			if (parseCalcCommand(sCommand)) break;
			println();
		}
		/*		char cOpFun = scanOpFun();
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
				printAns(ans);*/
	}

	boolean isOp(char cOpFun) {
		if (cOpFun == OP_SUM || cOpFun == OP_SUB) return true;
		else  return false;
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

	String decodeOpFun(char c) {
		switch (c) {
		case OP_SUM:  return "add (+)";
		case OP_SUB:  return "subtract (-)";
		case FUN_SIN: return "sine (sin)";
		case FUN_COS: return "cosine (cos)";
		default: return "wrong key";
		}
	}

	String scanHomeCommand() {
		prints("home>");
		String sCommand; scans(sCommand);
		prints(sCommand + "\r\n");
		return sCommand;
	}

	String scanCalcCommand() {
		prints("calc>");
		String sCommand; scans(sCommand);
		prints(sCommand + "\r\n");
		return sCommand;
	}

	char scanOpFun() {
		char c; scans(c);
		prints("[Selected key] = "); prints(decodeOpFun(c)); println();
		return c;
	}

	String scanOpFunStr() {
		String str; scans(str);
		return str;
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

	void printHome() {
		prints("Mokwon ICE Calculator [Version 0.1]\r\n");
		prints("Press \"help\" for more information.\r\n\r\n");
	}

	void printCalcHome() {
		prints("The Most Simple Calculator [Version 0.1]\r\n");
		prints("Press \"help\" for more information.\r\n\r\n");
	}

	void printHomeHelp() {
		prints("calc: simple calculator\r\n");
		prints("exit: exit home\r\n");
		prints("help: help for home\r\n");
	}

	void printCalcHelp() {
		prints("+: additon\r\n");
		prints("-: subtraction\r\n");
		prints("sin: sine\r\n");
		prints("cos: sine\r\n");
		prints("exit: exit calc\r\n");
		prints("help: help for calc\r\n");
	}

	void printAns(double x) {
		prints("Answer = ");
		Serial.print(x, PREC_DIGIT); println();
	}

	void printError(String sCommand) {
		prints("Unknown command: " + sCommand);
		println();
	}

	boolean parseHomeCommand(String sCommand) {
		if (sCommand == "exit") return true;
		else if (sCommand == "help") printHomeHelp();
		else if (sCommand == "calc") calc();
		else printError(sCommand);
		return false;
	}

	boolean parseCalcCommand(String sCommand) {
		if (sCommand == "exit") return true;
		else if (sCommand == "help") printCalcHelp();
		else if (sCommand == "+") calcOp(sCommand[0], 0, 0);
		else printError(sCommand);
		return false;
	}
};

#undef PREC_DIGIT
#undef OP_SUM
#undef OP_SUB
#undef FUN_SIN
#undef FUN_COS