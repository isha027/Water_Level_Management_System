int control=10;
#define echo 7
#define trig 8
long duration;
int distance;
void setup()
{
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
  Serial.println(" cm");
  if(distance>10){
    digitalWrite(control, LOW);
  }
  else if(distance<=5){
    digitalWrite(control,HIGH);
  }
  delay(100);
}

