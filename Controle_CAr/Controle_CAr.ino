#include<dht11.h>
int Up = 4; int Down = 5;
int Left = 6;
int Right = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13,OUTPUT);
  
  digitalWrite(13,HIGH);
  digitalWrite(Up, LOW);
  digitalWrite(Down, LOW);
  digitalWrite(Right, LOW);
  digitalWrite(Left, LOW);
}

void loop()
{

  if (Serial.available())
  {
    
    int c = Serial.read();

    if (c == 'U')
    {
      digitalWrite(Up, HIGH);
      Serial.println("  U  ");
    }
     if (c == 'D')
    {
      digitalWrite(Down, HIGH);
      Serial.println("  D  ");
    }
     if (c == 'L')
    {
      digitalWrite(Left, HIGH);
      Serial.println("  L  ");
    }
    if (c == 'C')
    {
      digitalWrite(Left, HIGH);
      delay(100);
      digitalWrite(Left, LOW);
    }
     if (c == 'R')
    {
      digitalWrite(Right, HIGH);
      Serial.println("  R  ");
    }
    if (c == 'T')
    {
      digitalWrite(Right, HIGH);
      delay(100);
      digitalWrite(Right, LOW);
    }
     if (c == 'P')
    {
      digitalWrite(Right, LOW);
      digitalWrite(Left, LOW);
      digitalWrite(Down, LOW);
      digitalWrite(Up, LOW);
    }
        if (c == '1')
    {
      digitalWrite(Up, LOW);
      Serial.println("  1  ");
    }
     if (c == '2')
    {
      digitalWrite(Down, LOW);
      Serial.println("  2  ");
    }
     if (c == '3')
     
    {
      digitalWrite(Left, LOW);
      Serial.println("  3  ");
    }
     if (c == '4')
    {
      digitalWrite(Right, LOW);
      Serial.println("  4  ");
    }
    
}
}
