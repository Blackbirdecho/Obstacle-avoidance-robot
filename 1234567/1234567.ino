  const int ultra1_trig=3;
  const int ultra1_eco=4;
  const int ultra2_trig=10;
  const int ultra2_eco=11;
  const int motor1_1pin=5;
  const int motor1_2pin=6;
  const int motor2_1pin=8;
  const int motor2_2pin=9;
  int distance1;
  int distance2;
  int t1;
  int t2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   pinMode(ultra1_trig,OUTPUT);
   pinMode(ultra1_eco,INPUT);
   pinMode(motor1_1pin,OUTPUT);
   pinMode(motor1_2pin,OUTPUT);
  pinMode(motor2_1pin,OUTPUT);
  pinMode(motor2_2pin,OUTPUT);
  pinMode(ultra2_trig,OUTPUT);
  pinMode(ultra2_eco,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ultra1_trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(ultra1_trig,LOW);
  t1=pulseIn(ultra1_eco,HIGH);
  distance1=(t1*0.034)/2;
  Serial.print(distance1);
  Serial.println("cm");
  delay(1000);
  ultra2();
  
  if(distance1<distance2)
  {
  digitalWrite(motor1_1pin,HIGH);
  digitalWrite(motor1_2pin,LOW);
  digitalWrite(motor2_1pin,LOW);
  digitalWrite(motor2_2pin,HIGH);
}
else if(distance1>distance2)
{
  digitalWrite(motor1_1pin,LOW);
  digitalWrite(motor1_2pin,HIGH);
  digitalWrite(motor2_1pin,HIGH);
  digitalWrite(motor2_2pin,LOW);
}
else
{
  digitalWrite(motor1_1pin,LOW);
  digitalWrite(motor1_2pin,HIGH);
  digitalWrite(motor2_1pin,LOW);
  digitalWrite(motor2_2pin,HIGH);
}
}
void ultra2()
{
  digitalWrite(ultra2_trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(ultra2_trig,LOW);
  t2=pulseIn(ultra2_eco,HIGH);
  distance2=(t2*0.034)/2;
  Serial.print(distance2);
  Serial.println("cm");
  delay(1000);
}

