#pragma once

#define ARRAY_SIZE  (100)

class CalcStat {
public:
	int arrayData[ARRAY_SIZE];
	int nNumElement = 0;

	void makeArray() {
		for (int i = 0; i < ARRAY_SIZE; i++)
			arrayData[i] = 0;
	}

	void fillArray() {
		for (int i = 0; i < ARRAY_SIZE; i++)
			arrayData[i] = i + 1;
	}

	void inputArray(StringTok stInput) {
		nNumElement = 0;
		StringTok stToken;
		while (1) {
			stToken = stInput.getToken();
			if (stToken.isEmpty()) break;
			int n = stToken.toInt();
			arrayData[nNumElement] = n;
			nNumElement++;
		}
	}

	double getAvg() {
		double sum = 0.;
		for (int i = 0; i < ARRAY_SIZE; i++)
			sum += arrayData[i];
		return sum / (double)ARRAY_SIZE;
	}

	double getAvg(int nMax) {
		double sum = 0.;
		for (int i = 0; i < nMax; i++)
			sum += arrayData[i];
		return sum / (double)nMax;
	}

	double getVar() {
		double avg = getAvg();
		double sum = 0.;
		for (int i = 0; i < ARRAY_SIZE; i++) {
			double diff = arrayData[i] - avg;
			sum += diff * diff;
		}
		return sum / (double)ARRAY_SIZE;
	}

	double getVar(int nMax) {
		double avg = getAvg(nMax);
		double sum = 0.;
		for (int i = 0; i < nMax; i++) {
			double diff = arrayData[i] - avg;
			sum += diff * diff;
		}
		return sum / (double)nMax;
	}

	double getStdDev() {
		double var = getVar();
		return sqrt(var);
	}

	double getStdDev(int nMax) {
		double var = getVar(nMax);
		return sqrt(var);
	}

	void printArray(double avg, double var, double stdDev) {
		Serial.print("평균 = ");
		Serial.println(avg);
		Serial.print("분산 = ");
		Serial.println(var);
		Serial.print("표준편차 = ");
		Serial.println(stdDev);
	}

	void calcStat() {
		makeArray();
		fillArray();
		double avg = getAvg();
		double var = getVar();
		double stdDev = getStdDev();
		printArray(avg, var, stdDev);
	}
};

#undef ARRAY_SIZE