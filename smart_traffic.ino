const int echoPin = 4;
const int pingPin = 5;
const int echoPin2 = 2;
const int pingPin2 = 3;
int b=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(pingPin2, OUTPUT); 
  pinMode(echoPin2, INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,INPUT);
  pinMode(A5,OUTPUT);
}

long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}
int ultra1()
{
  long duration,cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);

  
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  delay(100);
  if(cm>20)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
int ultra2()
{
  long duration,cm;
  
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin2, LOW);

  
  duration = pulseIn(echoPin2, HIGH);
  cm = microsecondsToCentimeters(duration);
  delay(100);
  if(cm>20)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
void traffic1()
{
  int i=5,a;
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,1);
  digitalWrite(9,1);
  delay(3000);
  a=ultra1();
  Serial.println(a);
  while(i<=50 && a==1)
  {
    a=ultra1();
    Serial.println(a);
    if(a==1)
    {
     i=i+5;
     delay(5000);
    }
     
  }
  digitalWrite(7,1);
  digitalWrite(8,0);
  delay(3000);
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(9,1);
  digitalWrite(11,1);
}
void traffic2()
{
  int i=5,a;
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,1);
  delay(3000);
  a=ultra2();
  Serial.println(a);
  while(i<=50 && a==1)
  {
    a=ultra2();
    Serial.println(a);
    if(a==1)
    {
     i=i+5;
     delay(5000);
    }
     
  }
  digitalWrite(10,1);
  digitalWrite(11,0);
  delay(3000);
  digitalWrite(9,1);
  digitalWrite(10,0);
}
void loop() {

  int a;
  
  if(b==1)
  {
    a=1;
    digitalWrite(A5,0);
    b=0;
  }
  else
  {
  a=digitalRead(13);
  
  }
  if(a==1)
  {
  digitalWrite(A5,0);
  traffic1();
  traffic2();
  digitalWrite(A5,1);
  delay(1000);
  }
  else if(a==0)
  {
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,1);
  digitalWrite(10,0);
  digitalWrite(11,0);
  digitalWrite(A5,0);  
  }
  // put your main code here, to run repeatedly:

}
