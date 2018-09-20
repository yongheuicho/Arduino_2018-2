#define ARRAY_SIZE  (500)

class CalcStat {
public:
	int arrayData[ARRAY_SIZE];

	void makeArray() {
		for (int i = 0; i < ARRAY_SIZE; i++)
			arrayData[i] = 0;
	}

	void fillArray() {
		for (int i = 0; i < ARRAY_SIZE; i++)
			arrayData[i] = i + 1;
	}

	double getAvg() {
		double sum = 0.;
		for (int i = 0; i < ARRAY_SIZE; i++)
			sum += arrayData[i];
		return sum / (double)ARRAY_SIZE;
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

	double getStdDev() {
		double var = getVar();
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