#include <LiquidCrystal.h> 

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5);
const int echoPin = 4;
const int pingPin = 5;
const int echoPin2 = 2;
const int pingPin2 = 3;
int t=0,w=0;
int l=1,f=1,a;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(pingPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(pingPin2, OUTPUT); 
  pinMode(echoPin2, INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  // put your setup code here, to run once:

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

void loop() {
  int a,b,c=0;
  // put your main code here, to run repeatedly:
  a=ultra1();
  b=ultra2();
  digitalWrite(6,0);
  digitalWrite(7,0);
  if(a==1)
  {
    delay(3000);
    c++;
  }
  
  while(c>0)
  {
     digitalWrite(6,1);
     digitalWrite(7,1);
      a=ultra1();
      b=ultra2();
      lcd.setCursor(0,0);
   lcd.print("Enter key:"); 
    if (Serial.available() > 0)
    {
    char p = char(Serial.read());
    lcd.setCursor(0,0);
    lcd.print("Enter the key:*");
    if(p=='z')
    {
      lcd.print("Key accepted");
      delay(2000);
      lcd.clear();

     while(c>0)
     {
   if (Serial.available() > 0)
   {
  char msg = char(Serial.read());
   if (msg=='t')
   {
    if(t==0)
    {
      t=1;
      lcd.setCursor(0,0);
      lcd.print("TV is ON");
      delay(3000);
      lcd.clear();
    }
 
    else
    {
      t=0;
      lcd.setCursor(0,0);
      lcd.print("TV is OFF");
      delay(3000);
      lcd.clear();
    }
   }
   else if(msg=='w')
   {
      if(w==0)
    {
      w=1;
      lcd.setCursor(0,0);
      lcd.print("Washmach is ON");
      delay(3000);
      lcd.clear();
    }
 
    else
    {
      w=0;
      lcd.setCursor(0,0);
      lcd.print("Washmach is OFF");
      delay(3000);
      lcd.clear();
    }
   }
   else if(msg=='l')
   {
      if(l==0)
    {
      l=1;
      lcd.setCursor(0,0);
      lcd.print("Light is ON");
      digitalWrite(6,1);
      delay(3000);
      lcd.clear();
    }
 
    else
    {
      l=0;
      lcd.setCursor(0,0);
      lcd.print("Light is OFF");
      digitalWrite(6,0);
      delay(3000);
      lcd.clear();
    }
   }
   else if(msg=='f')
   {
      if(f==0)
    {
      f=1;
      lcd.setCursor(0,0);
      lcd.print("Fan is ON");
      digitalWrite(7,1);
      delay(3000);
      lcd.clear();
    }
 
    else
    {
      f=0;
      lcd.setCursor(0,0);
      lcd.print("Fan is OFF");
      digitalWrite(7,0);
      delay(3000);
      lcd.clear();
    }
   }
   }
      if(a==1)
      {
        delay(3000);
      c++;
      }
      if(b==1)
      {
        delay(3000);
      c=c-1;
     }
    
   
      if(a==1)
      {
        delay(3000);
      c++;
      }
      if(b==1)
      {
        delay(3000);
      c=c-1;
      }
  }

}
else
{
lcd.print("Invalid key");
delay(1000);
lcd.clear();
}
    }
  }
}
