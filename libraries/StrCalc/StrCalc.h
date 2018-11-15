#pragma once

#define OP_SUM    ('+')
#define OP_SUB    ('-')

class StrCalc {
public:
	double getAns(StringTok stStr, boolean & bError)
	{
		bError = false;
		StringTok stToken;
		stToken = stStr.getToken(); // Number1
		double x1 = stToken.toDouble(); // String -> double
		stToken = stStr.getToken(); // Operation
		char cOp = stToken[0]; // String -> char
		stToken = stStr.getToken(); // Number2
		double x2 = stToken.toDouble(); // String -> double
		double ans;
		if (cOp == OP_SUM) ans = x1 + x2;
		else if (cOp == OP_SUB) ans = x1 - x2;
		else bError = true;
		return ans;
	}
};