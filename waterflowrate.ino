int sensor = 2;
volatile long pulsecount;
unsigned long last;
float flowrate;
void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(sensor), increase, RISING);
}
void loop() {
  flowrate = 2.663 * pulsecount / 1000 * 30; 
  if (millis() - last > 2000) {
    pulsecount = 0;
    last = millis();
  }
  Serial.print(flowrate);
  Serial.println(" L/m");
}
void increase() {
  pulsecount++;
}

