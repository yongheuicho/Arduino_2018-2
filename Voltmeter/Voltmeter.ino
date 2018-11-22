void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nVolt = analogRead(A0);
  double volt = map(nVolt, 0, 1023, 0, 5000)/1000.;
  Serial.println(volt);
  delay(1000);
}
