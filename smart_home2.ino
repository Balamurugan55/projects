#include <LiquidCrystal.h> 

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5);
void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
pinMode(2,INPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
 }
int i=0;
int j=0,a;
int t=0,w=0;
int l=1,f=1;
void loop()
{
  a=digitalRead(2);
  if(a==1)
  {
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

     while(a==1)
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
      digitalWrite(3,1);
      delay(3000);
      lcd.clear();
    }
 
    else
    {
      l=0;
      lcd.setCursor(0,0);
      lcd.print("Light is OFF");
      digitalWrite(3,0);
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
      digitalWrite(4,1);
      delay(3000);
      lcd.clear();
    }
 
    else
    {
      f=0;
      lcd.setCursor(0,0);
      lcd.print("Fan is OFF");
      digitalWrite(4,0);
      delay(3000);
      lcd.clear();
    }
   }
   
    
   }
   a=digitalRead(2);
     }
    }
else
lcd.print("Invalid key");
}
    }
  }
