int sensor = 2;
volatile long pulsecount;
unsigned long last;
float flowrate;
int control=10;
#define echo 7
#define trig 8
long duration;
int distance;
void setup()
{
  pinMode(sensor, INPUT); 
  attachInterrupt(digitalPinToInterrupt(sensor), increase, RISING);
  pinMode(control,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  digitalWrite(control,HIGH);
  digitalWrite(trig,LOW);
}
void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm\n");
  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print("\n");
  if(distance>10){
    digitalWrite(control, LOW);
  }
  else if(distance<=5){
    digitalWrite(control,HIGH);
  }
  delay(1000);
  flowrate = 2.663 * pulsecount / 1000 * 30;
  if (millis() - last > 2000) {
    pulsecount = 0;
    last = millis();
  }
  Serial.print("Flow rate: ");
  Serial.print(flowrate);
  Serial.println(" L/min");
}

void increase() {
  pulsecount++;
}
