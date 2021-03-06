#pragma once

#include <math.h>
#include <StringTok.h>
#include <StrCalc.h>
#include <CalcStat.h>
#include <LedCtrl.h>

#define PREC_DIGIT  (20)
#define OP_SUM    ('+')
#define OP_SUB    ('-')
#define FUN_SIN   ('s')
#define FUN_COS   ('c')
#define TITLE_HOME	("home")
#define TITLE_CALC	("calc")
#define TITLE_EZCALC	("ezCalc")
#define TITLE_CALCSTAT	("calcStat")
#define TITLE_LEDCTRL	("ledCtrl")

class Calculator {
public:
	void home() {
		printHome(); println();
		while (1) {
			String sCommand = scanCommand(TITLE_HOME);
			if (parseHomeCommand(sCommand)) break;
			println();
		}
	}

	void calc() {
		printCalcHome(); println();
		while (1) {
			String sCommand = scanCommand(TITLE_CALC);
			if (parseCalcCommand(sCommand)) break;
			println();
		}
	}

	void ezCalc() {
		printEzCalcHome(); println();
		while (1) {
			String sCommand = scanCommand(TITLE_EZCALC);
			if (parseEzCalcCommand(sCommand)) break;
			println();
		}
	}

	void calcStat() {
		CalcStat calcStat;
		calcStat.makeArray();
		printCalcStatHome(); println();
		while (1) {
			String sCommand = scanCommand(TITLE_CALCSTAT);
			if (parseCalcStatCommand(sCommand, calcStat)) break;
			println();
		}
	}

	void ledCtrl() {
		printLedCtrlHome(); println();
		while (1) {
			String sCommand = scanCommand(TITLE_LEDCTRL);
			if (parseLedCtrlCommand(sCommand)) break;
			println();
		}
	}

	boolean isOp(char cOpFun) {
		if (cOpFun == OP_SUM || cOpFun == OP_SUB) return true;
		else  return false;
	}

	boolean isFun(char cOpFun) {
		if (cOpFun == FUN_SIN || cOpFun == FUN_COS) return true;
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

	String scanCommand(String sTitle) {
		prints(sTitle + ">");
		String sCommand; scans(sCommand);
		prints(sCommand + "\r\n");
		return sCommand;
	}

	String scanAnyStr(String sTitle) {
		prints(sTitle);
		String sInput; scans(sInput);
		prints(sInput + "\r\n");
		return sInput;
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

	double scanDouble(String sNum) {
		if (sNum.length() == 0) prints("Input = ");
		else prints("Input " + sNum + " = ");
		double x; scans(x); prints(x); println();
		return x;
	}

	void scanDouble2(double & x1, double & x2) {
		x1 = scanDouble("#1");
		x2 = scanDouble("#2");
	}

	void printHome() {
		prints("Mokwon ICE Calculator [Version 0.1]\r\n");
		prints("Press \"help\" for more information.\r\n");
	}

	void printHomeHelp() {
		prints("calc: A Most Simple Calculator\r\n");
		prints("ezCalc: Easy Calculator\r\n");
		prints("calcStat: Calculator with Statistics\r\n");
		prints("ledCtrl: LED Control\r\n");
		prints("exit: exit home\r\n");
		prints("help: help for home");
	}

	void printCalcHome() {
		prints("A Most Simple Calculator\r\n");
		prints("Press \"help\" for more information.\r\n");
	}

	void printCalcHelp() {
		prints("+: additon\r\n");
		prints("-: subtraction\r\n");
		prints("s: sine\r\n");
		prints("c: cosine\r\n");
		prints("exit: exit calc\r\n");
		prints("help: help for calc");
	}

	void printEzCalcHome() {
		prints("Easy Calculator\r\n");
		prints("Write any math expression or type \"exit\" to exit.\r\n");
	}

	void printCalcStatHome() {
		prints("Calculator with Statistics\r\n");
		prints("Press \"help\" for more information.\r\n");
	}

	void printCalcStatHelp() {
		prints("input: input array elements\r\n");
		prints("avg: average\r\n");
		prints("exit: exit calcStat\r\n");
		prints("help: help for calcStat");
	}

	void printLedCtrlHome() {
		prints("LED Control\r\n");
		prints("Write any LED command or type \"exit\" to exit.\r\n");
	}

	void printAns(double x) {
		prints("Answer = ");
		Serial.print(x, PREC_DIGIT);
	}

	void printAnyAns(double x, String sTitle) {
		prints(sTitle + " = ");
		Serial.print(x, PREC_DIGIT);
	}

	void printError(String sCommand) {
		prints("Unknown command: " + sCommand);
	}

	boolean parseHomeCommand(String sCommand) {
		if (sCommand == "exit") return true;
		else if (sCommand == "help") printHomeHelp();
		else if (sCommand == "calc") calc();
		else if (sCommand == "ezCalc") ezCalc();
		else if (sCommand == "calcStat") calcStat();
		else if (sCommand == "ledCtrl") ledCtrl();
		else printError(sCommand);
		return false;
	}

	boolean parseCalcCommand(String sCommand) {
		if (sCommand == "exit") return true;
		else if (sCommand == "help") printCalcHelp();
		else if (isOp(sCommand[0])) {
			double x1, x2; scanDouble2(x1, x2);
			printAns(calcOp(sCommand[0], x1, x2));
		}
		else if (isFun(sCommand[0])) {
			double x = scanDouble("");
			printAns(calcFun(sCommand[0], x));
		}
		else printError(sCommand);
		return false;
	}

	boolean parseEzCalcCommand(String sCommand) {
		if (sCommand == "exit") return true;
		else {
			StrCalc strCalc;
			boolean bError;
			double ans = strCalc.getAns(sCommand, bError);
			if (bError) printError(sCommand);
			else printAns(ans);
		}
		return false;
	}

	boolean parseCalcStatCommand(String sCommand, CalcStat & calcStat) {
		if (sCommand == "exit") return true;
		else if (sCommand == "help") printCalcStatHelp();
		else if (sCommand == "input") {
			StringTok stInput = scanAnyStr("Array elements = ");
			calcStat.inputArray(stInput);
		}
		else if (sCommand == "avg") {
			double avg = calcStat.getAvg(calcStat.nNumElement);
			printAnyAns(avg, "Average");
		}
		else printError(sCommand);
		return false;
	}

	boolean parseLedCtrlCommand(String sCommand) {
		if (sCommand == "exit") return true;
		else {
		}
		return false;
	}
};

#undef PREC_DIGIT
#undef OP_SUM
#undef OP_SUB
#undef FUN_SIN
#undef FUN_COS
#undef TITLE_HOME
#undef TITLE_CALC
#undef TITLE_EZCALC