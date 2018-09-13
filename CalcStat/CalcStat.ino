#define ARRAY_SIZE  (1000)

int arrayData[ARRAY_SIZE];
  
void makeArray() {
//
}

void fillArray() {
//  
}

double getAvg() {
  return 0.;
}

double getVar() {
  return 0.;
}

double getStdDev() {
  return 0.;
}

void printArray(double avg, double var, double stdDev) {
  
}

void calcStat() {
  makeArray();
  fillArray();
  double avg = getAvg();
  double var = getVar();
  double stdDev = getStdDev();
  printArray(avg, var, stdDev); 
}

void setup() {
  // put your setup code here, to run once: 한 번만 실행
  calcStat();
}

void loop() {
  // put your main code here, to run repeatedly: 계속 실행

}
